#ifndef QUERYH
#define QUERYH

#include <memory>
#include <string>
#include <iostream>
#include <algorithm>
#include "TextQuery.h"

//************************************************************
//
//             Query_base
//
//************************************************************
class Query_base {
  friend class Query;

protected:
  using line_no = TextQuery::line_no;
  //**********destructors**********
  virtual ~Query_base() = default;

private:
  //**********methods**********
  virtual QueryResult eval(const TextQuery &) const = 0;
  virtual std::string rep() const = 0;

};

//************************************************************
//
//                Query
//
//************************************************************
class Query {
  friend Query operator~(const Query &);
  friend Query operator&(const Query &, const Query &);
  friend Query operator|(const Query &, const Query &);

public:
  //**********constructors**********
  Query() : q(nullptr), cnt(new size_t(1)) {}
  Query(const std::string &s);
  Query(const Query &s) : q(s.q), cnt(s.cnt) {++*cnt;}
  Query(Query &&s) : q(s.q), cnt(s.cnt) {s.q = nullptr; s.cnt = nullptr;}

  Query &operator=(const Query &rhs) {
    if (this != &rhs) {
      free();
      q = rhs.q;
      cnt = rhs.cnt;
      ++*cnt;
    }
    return *this;
  }

  //**********destructors**********
  ~Query() {free();}

  //**********methods**********
  QueryResult eval(const TextQuery &t) const { return q->eval(t);}
  std::string rep() const { return q->rep();}
  std::size_t count() const {return *cnt;}

private:
  void free() {
    if (*cnt == 1) {
      delete q;
      delete cnt;
    }
  }
  Query(Query_base *query) : q(query), cnt(new std::size_t(1)){ }
  Query_base *q;
  std::size_t *cnt;

};

inline
std::ostream &
operator<<(std::ostream &os, const Query &query)
{
  return os << query.rep();
}
//************************************************************
//
//                WordQuery
//
//************************************************************
class WordQuery : public Query_base {
  friend class Query;
  WordQuery(const std::string &s) : query_word(s) { }

  QueryResult eval(const TextQuery &t) const { return t.query(query_word);}
  std::string rep() const { return query_word;}
  std::string query_word;
};

inline Query::Query(const std::string &s) : q(new WordQuery(s)), cnt(new std::size_t(1)){}

//************************************************************
//
//                NotQuery
//
//************************************************************
class NotQuery : public Query_base {
  friend Query operator~(const Query &);
  NotQuery(const Query &q) : query(q) {}

  std::string rep() const {return "~(" + query.rep() + ")";}
  QueryResult eval(const TextQuery&) const;
  Query query;
};

inline Query operator~(const Query &operand)
{
  return new NotQuery(operand);
}

inline
QueryResult NotQuery::eval(const TextQuery &text) const
{
  auto result = query.eval(text);
  auto ret_line = std::make_shared<std::set<line_no>>( );
  auto beg = result.begin(), end = result.end();
  auto sz = result.get_file()->size();
  for (std::size_t n = 0; n != sz; ++n) {
    if (beg == end || *beg != n)
      ret_line->insert(n);
    else if (beg != end)
      ++beg;
  }
  return QueryResult(rep(), result.get_file(), ret_line);
}

//************************************************************
//
//                BianryQuery
//
//************************************************************
class BinaryQuery : public Query_base {
protected:
  BinaryQuery(const Query &l, const Query &r, std::string s) :
    lhs(l), rhs(r), opSym(s) {}
  std::string rep() const {
    return "(" + lhs.rep() + " "
               + opSym + " "
               + rhs.rep() + ")";
      }
  Query lhs, rhs;
  std::string opSym;
};

//************************************************************
//                AndQuery
//************************************************************
class AndQuery : public BinaryQuery {
  friend Query operator&(const Query &l, const Query &r);
  AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&") {}
  QueryResult eval(const TextQuery &) const;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
  return new AndQuery(lhs, rhs);
}

inline
QueryResult AndQuery::eval(const TextQuery &text) const
{
  auto left = lhs.eval(text), right = rhs.eval(text);
  auto ret_line = std::make_shared<std::set<line_no>>( );
  std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), std::inserter(*ret_line, ret_line->begin()));
  return QueryResult(rep(), left.get_file(), ret_line);
}

//************************************************************
//                OrQuery
//************************************************************
class OrQuery : public BinaryQuery {
  friend Query operator|(const Query &, const Query &);
  OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "|") {}
  QueryResult eval(const TextQuery &) const;
};

inline Query operator|(const Query &lhs, const Query &rhs)
{
  return new OrQuery(lhs, rhs);
}

QueryResult OrQuery::eval(const TextQuery &text) const
{
  auto right = rhs.eval(text), left = lhs.eval(text);
  auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
  ret_lines->insert(right.begin(), right.end());
  return QueryResult(rep(), left.get_file(), ret_lines);
}
#endif
