#ifndef MYBLOBH
#define MYBLOBH

#include <vector>
#include <memory>

template <typename T> class Blob {

public:
  typedef typename std::vector<T>::size_type size_type;
  typedef T value_type;

  //**********constructors**********
  Blob() : p_data(std::make_shared<std::vector<T>>()) { }
  Blob(std::initializer_list<T> il) : p_data(std::make_shared<std::vector<T>>(il)) { }

  //**********menthods**********
  //**********number of elements**********
  size_type size() const {return p_data->size();}
  bool empty() const {return p_data->empty();}
  //**********add and remove elements**********
  void push_back(const T &t) {p_data->push_back(t);}
  void pop_back();
  //**********move elements**********
  void push_back(T &&t) {p_data->push_back(std::move(t));}
  //**********elements access**********
  T &back();
  T &back() const;
  T &operator[](size_type i);
  T &operator[](size_type i) const;


private:
  std::shared_ptr<std::vector<T>> p_data;
  void check(size_type i, const std::string &msg) const;
};

template <typename T> inline
void Blob<T>::check(size_type i, const std::string &msg) const
{
  if (i >= p_data->size())
    throw std::out_of_range(msg);
}

template <typename T> inline
T &Blob<T>::back()
{
  check(0, "back on empty Blob");
  return p_data->back();
}

template <typename T> inline
T &Blob<T>::back() const
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
T &Blob<T>::operator[](size_type i) const
{
  check(i, "subscript out of range");
  return (*p_data)[i];
}

template <typename B> inline
void Blob<B>::pop_back()
{
  check(0, "pop_back on empty Blob");
  p_data->pop_back();
}

#endif
