#ifndef MYBLOBH
#define MYBLOBH

#include <vector>
#include <string>
#include <stdexcept>
#include <initializer_list>
#include <memory>
// #include "shared_ptr.h"
using std::shared_ptr;
using std::make_shared;

//************************************************************
//
//                 BLOB
//
//************************************************************
template <typename> class BlobPtr;
template <typename> class ConstBlobPtr;
template <typename> class Blob;
template <typename T> bool operator==(const Blob<T> &, const Blob<T> &);
template <typename T> bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs);
template <typename T> bool operator<(const Blob<T> &lhs, const Blob<T> &rhs);
template <typename T> bool operator>(const Blob<T> &lhs, const Blob<T> &rhs);
template <typename T> bool operator<=(const Blob<T> &lhs, const Blob<T> &rhs);
template <typename T> bool operator>=(const Blob<T> &lhs, const Blob<T> &rhs);

template <typename T> class Blob {

  friend class BlobPtr<T>;
  friend class ConstBlobPtr<T>;

  friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
  friend bool operator!=<T>(const Blob &lhs, const Blob &rhs);
  friend bool operator< <T>(const Blob &lhs, const Blob &rhs);
  friend bool operator> <T>(const Blob &lhs, const Blob &rhs);
  friend bool operator<=<T>(const Blob &lhs, const Blob &rhs);
  friend bool operator>=<T>(const Blob &lhs, const Blob &rhs);

public:
  using size_type = typename std::vector<T>::size_type ;
  typedef T value_type;

  //**********constructors**********
  Blob() : p_data(make_shared<std::vector<T>>()) { }
  Blob(std::initializer_list<T> il) : p_data(make_shared<std::vector<T>>(il)) { }
  Blob(const Blob &obj) : p_data(make_shared<std::vector<T>>(*(obj.p_data))) { }
  template <typename IT> Blob(IT b, IT e);

  //**********menthods**********
  //**********assignment**********
  Blob &operator=(const Blob &rhs);
  Blob &operator=(Blob &&rhs);
  //**********number of elements**********
  size_type size() const {return p_data->size();}
  bool empty() const {return p_data->empty();}
  //**********add and remove elements**********
  void push_back(const T &t) {p_data->push_back(t);}
  void pop_back();
  //**********move elements**********
  void push_back(T &&t) {p_data->push_back(std::move(t));}
  //**********elements access**********
  T &front();
  const T &front() const;
  T &back();
  const T &back() const;
  T &operator[](size_type i);
  const T &operator[](size_type i) const;
  //**********iterators**********
  BlobPtr<T> begin();
  ConstBlobPtr<T> begin() const;
  ConstBlobPtr<T> cbegin() const;
  BlobPtr<T> end();
  ConstBlobPtr<T> end() const;
  ConstBlobPtr<T> cend() const;


private:
  shared_ptr<std::vector<T>> p_data;
  void check(size_type i, const std::string &msg) const;
};

//**********constructors**********
template <typename T>
template <typename IT> inline
Blob<T>::Blob(IT b, IT e)
  :p_data(make_shared<T>(b, e)) {}

//**********operators**********
template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs)
{
  return (*lhs.p_data) == (*rhs.p_data);
}

//**********menthods**********
//**********utility functions**********
template <typename T> inline
void Blob<T>::check(size_type i, const std::string &msg) const
{
  if (i >= p_data->size())
    throw std::out_of_range(msg);
}

//**********assignment**********
template <typename T> inline
Blob<T> &Blob<T>::operator=(const Blob<T> &rhs)
{
  p_data = make_shared<std::vector<T>>(*(rhs.p_data));
  return *this;
}

template <typename T> inline
Blob<T> &Blob<T>::operator=(Blob<T> &&rhs)
{
  if (this != &rhs)
    p_data = rhs.p_data;
  return *this;
}

//**********elements access**********
template <typename T> inline
T &Blob<T>::front()
{
  check(0, "front on empty Blob");
  return p_data->front();
}

template <typename T> inline
const T &Blob<T>::front() const
{
  check(0, "front on empty Blob");
  return p_data->front();
}

template <typename T> inline
T &Blob<T>::back()
{
  check(0, "back on empty Blob");
  return p_data->back();
}

template <typename T> inline
const T &Blob<T>::back() const
{
  check(0, "back on empty Blob");
  return p_data->back();
}

template <typename T> inline
T &Blob<T>::operator[](size_type i)
{
  check(i, "subscript out of range");
  return (*p_data)[i];
}

template <typename T> inline
const T &Blob<T>::operator[](size_type i) const
{
  check(i, "subscript out of range");
  return (*p_data)[i];
}

//**********add and remove elements**********
template <typename B> inline
void Blob<B>::pop_back()
{
  check(0, "pop_back on empty Blob");
  p_data->pop_back();
}

//************************************************************
//
//     POINTER TO BLOB
//
//************************************************************
template <typename T> class BlobPtr {

public:
  //**********constructors**********
  BlobPtr() : index(0) { }
  BlobPtr(Blob<T> &obj, size_t sz = 0) : wp_data(obj.p_data), index(sz) { }

  //**********operators**********
  T& operator*() const;
  BlobPtr& operator++();
  BlobPtr& operator--();

private:
  std::weak_ptr<std::vector<T>> wp_data;
  std::size_t index;
  shared_ptr<std::vector<T>> lock_ptr() const {return wp_data.lock();}
  shared_ptr<std::vector<T>> check(std::size_t n, const std::string &msg) const;
};

template <typename T> inline
T& BlobPtr<T>::operator*() const
{
  auto p =check(index, "dereference past end");
  return (*p)[index];
}

template <typename T> inline
BlobPtr<T>& BlobPtr<T>::operator++()
{
  check(index, "increment past end");
  ++index;
  return *this;
}

template <typename T> inline
BlobPtr<T>& BlobPtr<T>::operator--()
{
  check(--index, "decrement past begin");
  return *this;
}

template <typename T> inline
shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t n, const std::string &msg) const
{
  auto ret = wp_data.lock();
  if (!ret)
    throw std::runtime_error("unboud BlobPtr");
  if (n >= ret->size())
    throw std::out_of_range(msg);
  return ret;
}

//************************************************************
//
//     POINTER TO CONST BLOB
//
//************************************************************
template <typename T> class ConstBlobPtr {

public:
  //**********constructors**********
  ConstBlobPtr() : index(0) { }
  ConstBlobPtr(Blob<T> &obj, size_t sz = 0) : wp_data(obj.p_data), index(sz) { }

  //**********operators**********
  const T& operator*() const;
  ConstBlobPtr& operator++() const;
  ConstBlobPtr& operator--() const;

private:
  std::weak_ptr<std::vector<T>> wp_data;
  std::size_t index;
  shared_ptr<std::vector<T>> lock_ptr() const {return wp_data.lock();}
  shared_ptr<std::vector<T>> check(std::size_t n, const std::string &msg) const;
};

//**********iterators**********
template <typename T> inline
BlobPtr<T> Blob<T>::begin()
{
  return BlobPtr<T>(p_data, 0);
}
template <typename T> inline
ConstBlobPtr<T> Blob<T>::begin() const
{
  return ConstBlobPtr<T>(p_data, 0);
}
template <typename T> inline
ConstBlobPtr<T> Blob<T>::cbegin() const
{
  return ConstBlobPtr<T>(p_data, 0);
}
template <typename T> inline
BlobPtr<T> Blob<T>::end()
{
  return BlobPtr<T>(p_data, p_data->size());
}
template <typename T> inline
ConstBlobPtr<T> Blob<T>::end() const
{
  return ConstBlobPtr<T>(p_data, p_data->size());
}
template <typename T> inline
ConstBlobPtr<T> Blob<T>::cend() const
{
  return ConstBlobPtr<T>(p_data, p_data->size());
}

int main()
{
  Blob<int> b = {1,2,3,4};
  {
    Blob<int> q(b);
    auto p = b;
    b = std::move(p);
  }
  return 0;
}
#endif
