#ifndef STRBLOBH
#define STRBLOBH
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>

class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob {
  friend class StrBlobPtr;
  friend class ConstStrBlobPtr;
public:
  typedef std::vector<std::string>::size_type size_type;
  //constructor
  StrBlob() : data(std::make_shared<std::vector<std::string>>()) { };
  StrBlob(std::initializer_list<std::string> il)
    : data(std::make_shared<std::vector<std::string>>(il)) { };
  //
  size_type size() const {return data ->size();};
  bool empty() const {return data ->empty();};
  //
  void push_back(const std::string &str) {return data->push_back(str);};
  void pop_back();
  std::string &front();
  const std::string &front() const;
  std::string &back();
  const std::string &back() const;
  StrBlobPtr begin();
  StrBlobPtr end();
  ConstStrBlobPtr begin() const;
  ConstStrBlobPtr end() const;
private:
  std::shared_ptr<std::vector<std::string>> data;
  void check(size_type i, const std::string &msg) const;
};

class StrBlobPtr {
public:
  StrBlobPtr() : index(0) { };
  StrBlobPtr(StrBlob &ob, StrBlob::size_type pos = 0)
    : wptr(ob.data), index(pos) { };
  std::string &deref() const
  {
    auto p = check(index, "dereference past end");
    return (*p)[index];
  }
  StrBlobPtr &incre()
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

class ConstStrBlobPtr {
public:
  ConstStrBlobPtr() : index(0) { };
  ConstStrBlobPtr(const StrBlob &ob, StrBlob::size_type pos = 0)
    : wptr(ob.data), index(pos) { };
  const std::string &deref() const
  {
    auto p = check(index, "dereference past end");
    return (*p)[index];
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
#endif
