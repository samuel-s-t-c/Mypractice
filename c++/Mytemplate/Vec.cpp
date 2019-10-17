#include <algorithm>
#include "Vec.h"

template <typename T>
std::allocator<T> Vec<T>::alloc;

//**********constructors**********
template <typename T>
Vec<T>::Vec(const Vec &obj)
{
  auto data = alloc_n_copy(obj.begin(), obj.end());
  elements = data.first;
  first_free = cap = data.second;
}

template <typename T>
Vec<T>::Vec(Vec &&obj) noexcept
  : elements(obj.elements), first_free(obj.first_free), cap(obj.cap)
{
  obj.elements = obj.first_free = obj.cap = nullptr;
}

template <typename T>
Vec<T>::Vec(const std::initializer_list<value_type> &ils)
{
  auto data = alloc_n_copy(ils.begin(), ils.end());
  elements = data.first;
  first_free = cap = data.second;
}

//**********destructor**********
template <typename T>
Vec<T>::~Vec()
{
  free();
}

//**********methods**********
//**********assignments**********
template <typename T>
Vec<T> &Vec<T>::operator=(const Vec &rhs)
{
  auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = newdata.first;
  cap = first_free = newdata.second;
  return *this;
}

template <typename T>
Vec<T> &Vec<T>::operator=(Vec &&rhs)
{
  if (this != &rhs) {
    free();
    elements = rhs.elements;
    first_free = rhs.first_free;
    cap = rhs.cap;
    rhs.elements = rhs.first_free = rhs.cap = nullptr;
  }
  return *this;
}

template <typename T>
Vec<T> &Vec<T>::operator=(const std::initializer_list<value_type> &rhs)
{
  auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = newdata.first;
  cap = first_free = newdata.second;
  return *this;
}

//**********Element access**********
template <typename T>
T &Vec<T>::operator[](size_type n)
{
  return *(elements + n);
}

template <typename T>
const T &Vec<T>::operator[](size_type n) const
{
  return *(elements + n);
}

template <typename T>
T &Vec<T>::back()
{
  return *(first_free - 1);
}

template <typename T>
const T &Vec<T>::back() const
{
  return *(first_free - 1);
}

template <typename T>
T &Vec<T>::front()
{
  return *elements;
}

template <typename T>
const T &Vec<T>::front() const
{
  return *elements;
}

//**********add and remove elements**********
template <typename T>
void Vec<T>::push_back(const T &val)
{
  chk_n_alloc();
  alloc.construct(first_free++, val);
}

template <typename T>
void Vec<T>::push_back(T &&val)
{
  chk_n_alloc();
  alloc.construct(first_free++, std::move(val));
}

template <typename T>
void Vec<T>::pop_back()
{
  if (elements != first_free)
    alloc.destory(--first_free);
}

//**********numbers of elements**********
template <typename T>
std::size_t Vec<T>::size() const
{
  return first_free - elements;
}

template <typename T>
bool Vec<T>::empty() const
{
  return first_free == elements;
}

template <typename T>
std::size_t Vec<T>::capacity() const
{
  return cap - elements;
}

//**********iterators**********
template <typename T>
T *Vec<T>::begin()
{
  return elements;
}

template <typename T>
const T *Vec<T>::begin() const
{
  return elements;
}

template <typename T>
const T *Vec<T>::cbegin() const
{
  return elements;
}

template <typename T>
T *Vec<T>::end()
{
  return first_free;
}

template <typename T>
const T *Vec<T>::end() const
{
  return first_free;
}

template <typename T>
const T *Vec<T>::cend() const
{
  return first_free;
}

//**********relational operators**********
template <typename T>
bool operator==(const Vec<T> &lhs, const Vec<T> &rhs)
{
  return lhs.size() == rhs.size() &&
         std::equal(lhs.begin(), lhs.end(), rhs.begin());
}
template <typename T>
bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs)
{
  return !(lhs == rhs);
}

template <typename T>
bool operator<(const Vec<T> &lhs, const Vec<T> &rhs)
{
  return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <typename T>
bool operator<=(const Vec<T> &lhs, const Vec<T> &rhs)
{
  return !(rhs < lhs);
}

template <typename T>
bool operator>(const Vec<T> &lhs, const Vec<T> &rhs)
{
  return rhs < lhs;
}
template <typename T>
bool operator>=(const Vec<T> &lhs, const Vec<T> &rhs)
{
  return !(lhs < rhs);
}
//**********utility functions**********
template <typename T>
std::pair<T*, T*> Vec<T>::alloc_n_copy(const T *b, const T *e)
{
  auto data = alloc.allocate( e - b );
  return {data, std::uninitialized_copy(b, e, data)};
}

template <typename T>
void Vec<T>::free()
{
  if (elements) {
    std::for_each(elements, first_free, [this](T &val){alloc.destroy(&val);});
    alloc.deallocate(elements, cap - elements);
  }
}

template <typename T>
void Vec<T>::chk_n_alloc()
{
  if (first_free == cap)
    reallocate();
}

template <typename T>
void Vec<T>::reallocate()
{
  auto newcapacity = size() ? 2 * size() : 1;
  auto first = alloc.allocate(newcapacity);
  auto last = std::uninitialized_copy(std::make_move_iterator(begin()), std::make_move_iterator(end()), first);
  free();
  elements = first;
  first_free = last;
  cap = elements + newcapacity;
}
