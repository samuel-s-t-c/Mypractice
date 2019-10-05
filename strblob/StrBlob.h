#ifndef STRBLOBH
#define STRBLOBH
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <algorithm>

class StrBlobPtr;
class ConstStrBlobPtr;

//============================================================
//
//  StrBlob definition: custom version of vector<string>
//
//============================================================
class StrBlob {
  friend class StrBlobPtr;
  friend class ConstStrBlobPtr;
  friend bool operator==(const StrBlob &, const StrBlob &);
  friend bool operator!=(const StrBlob &, const StrBlob &);
  friend bool operator<(const StrBlob &, const StrBlob &);
  friend bool operator>(const StrBlob &, const StrBlob &);
  friend bool operator<=(const StrBlob &, const StrBlob &);
  friend bool operator>=(const StrBlob &, const StrBlob &);

public:

  typedef std::vector<std::string>::size_type size_type;

  //********** constructor **********
  StrBlob() : data(std::make_shared<std::vector<std::string>>()) { };
  StrBlob(std::initializer_list<std::string> il)
    : data(std::make_shared<std::vector<std::string>>(il)) { };
  StrBlob(const StrBlob &obj) : data(new std::vector<std::string>(*obj.data)) { }


  //********** operator **********
  StrBlob &operator=(const StrBlob &obj)
  {
    data.reset(new std::vector<std::string>(*obj.data));
    return *this;
  }
  std::string &operator[](std::size_t n)
  {
    return (*data)[n];
  }
  const std::string &operator[](std::size_t n) const
  {
    return (*data)[n];
  }


  //********** other methods **********
  size_type size() const {return data ->size();};
  bool empty() const {return data ->empty();};

  void push_back(const std::string &str) {return data->push_back(str);};
  void push_back(std::string &&str) {return data->push_back(std::move(str));};
  void pop_back();

  std::string &front();
  const std::string &front() const;
  std::string &back();
  const std::string &back() const;

  StrBlobPtr begin();
  ConstStrBlobPtr begin() const;

  StrBlobPtr end();
  ConstStrBlobPtr end() const;

private:

  std::shared_ptr<std::vector<std::string>> data;
  void check(size_type i, const std::string &msg) const;

};
//============================================================
//            friend declarations
//============================================================
bool operator==(const StrBlob &lhs, const StrBlob &rhs);
bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator<(const StrBlob &, const StrBlob &);
bool operator>(const StrBlob &, const StrBlob &);
bool operator<=(const StrBlob &, const StrBlob &);
bool operator>=(const StrBlob &, const StrBlob &);


//============================================================
//
//  StrBlobPtr definition
//
//============================================================
class StrBlobPtr {
  friend std::size_t operator-(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
  friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
  friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
  friend bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
  friend bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
  friend bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
  friend bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);

public:
  StrBlobPtr() : index(0) { }
  StrBlobPtr(const StrBlob &ob, StrBlob::size_type pos = 0)
    : wptr(ob.data), index(pos) { }

  char &operator[](std::size_t n) {return (*wptr.lock())[index][n];}
  const char &operator[](std::size_t n) const {return (*wptr.lock())[index][n];}
  StrBlobPtr operator+(std::size_t n);
  StrBlobPtr &operator+=(std::size_t n);
  StrBlobPtr operator-(std::size_t n);
  StrBlobPtr &operator-=(std::size_t n);
  StrBlobPtr &operator++();//prefix increment
  StrBlobPtr &operator--();//prefix decrement
  StrBlobPtr operator++(int);//postfix increment
  StrBlobPtr operator--(int);//postfix decrement
  std::string &operator*() const
  {
    auto p = check(index, "dereference past end");
    return (*p)[index];
  }
  std::string *operator->() const
  {
    return &this->operator*();
  }


private:
  std::weak_ptr<std::vector<std::string>> wptr;
  StrBlob::size_type index;
  std::shared_ptr<std::vector<std::string>> check(StrBlob::size_type i, const std::string &msg) const
  {
    auto ret = wptr.lock();
    if (!ret)
      throw std::runtime_error("unboud StrBlobPtr");
    if (i > ret->size())
      throw std::out_of_range(msg);
    return ret;
  }
};
//============================================================
//  friend declarations
//============================================================
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
std::size_t operator-(const StrBlobPtr &lhs, const StrBlobPtr &rhs);

//============================================================
//
//  ConstStrBlobPtr definition
//
//============================================================
class ConstStrBlobPtr {
  friend bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
  friend bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
  friend bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
  friend bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
  friend bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
  friend bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
public:
  ConstStrBlobPtr() : index(0) { };
  ConstStrBlobPtr(const StrBlob &ob, StrBlob::size_type pos = 0)
    : wptr(ob.data), index(pos) { };
  const std::string &operator*() const
  {
    auto p = check(index, "dereference past end");
    return (*p)[index];
  }
  const std::string *operator->() const
  {
    return &this->operator*();
  }
  ConstStrBlobPtr &incre()
  {
    check(index, "increment past end of StrBlobPtr");
    ++index;
    return *this;
  }
private:
  std::weak_ptr<std::vector<std::string>> wptr;
  StrBlob::size_type index;
  std::shared_ptr<std::vector<std::string>> check(StrBlob::size_type i, const std::string &msg) const
  {
    auto ret = wptr.lock();
    if (!ret)
      throw std::runtime_error("unboud StrBlobPtr");
    if (i > ret->size())
      throw std::out_of_range(msg);
    return ret;
  }
};
//============================================================
//  friend declarations
//============================================================
bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);
bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs);

//============================================================
//    StrBlob inline functions' implements
//============================================================
inline
void StrBlob::pop_back()
{
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}

inline
std::string &StrBlob::front()
{
  check(0, "front on empty StrBlob");
  return data->front();
}

inline
const std::string &StrBlob::front() const
{
  check(0, "front on empty StrBlob");
  return data->front();
}

inline
std::string &StrBlob::back()
{
  check(0, "back on empty StrBlob");
  return data->back();
}

inline
const std::string &StrBlob::back() const
{
  check(0, "back on empty StrBlob");
  return data->back();
}

inline
StrBlobPtr StrBlob::begin()
{
  return StrBlobPtr(*this);
}

inline
StrBlobPtr StrBlob::end()
{
  return StrBlobPtr(*this, data->size());
}

inline
void StrBlob::check(size_type i, const std::string &msg) const
{
  if (i >= data->size())
    throw std::out_of_range(msg);
}
//============================================================
//  StrBlobPtr inline functions' implements
//============================================================

//============================================================
//  ConstStrBlobPtr inline functions' implements
//============================================================

#endif
