#ifndef MYVECH
#define MYVECH

#include <memory>
template <typename> class Vec;
template <typename T> bool operator==(const Vec<T> &lhs, const Vec<T> &rhs);
template <typename T> bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs);
template <typename T> bool operator>(const Vec<T> &lhs, const Vec<T> &rhs);
template <typename T> bool operator>=(const Vec<T> &lhs, const Vec<T> &rhs);
template <typename T> bool operator<(const Vec<T> &lhs, const Vec<T> &rhs);
template <typename T> bool operator<=(const Vec<T> &lhs, const Vec<T> &rhs);

template <typename T> class Vec {

  friend bool operator==<T>(const Vec<T> &lhs, const Vec<T> &rhs);
  friend bool operator!=<T>(const Vec<T> &lhs, const Vec<T> &rhs);
  friend bool operator< <T>(const Vec<T> &lhs, const Vec<T> &rhs);
  friend bool operator<=<T>(const Vec<T> &lhs, const Vec<T> &rhs);
  friend bool operator> <T>(const Vec<T> &lhs, const Vec<T> &rhs);
  friend bool operator>=<T>(const Vec<T> &lhs, const Vec<T> &rhs);

public:
  typedef T value_type;
  typedef std::size_t size_type;
  typedef T* iterator;
  typedef const T* const_iterator;
  //**********constructors**********
  Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  Vec(const Vec &obj);
  Vec(Vec &&obj) noexcept;
  Vec(const std::initializer_list<value_type> &ils);

  //**********destructor**********
  ~Vec();

  //**********methods**********
  //**********assignments**********
  Vec &operator=(const Vec &rhs);
  Vec &operator=(Vec &&rhs);
  Vec &operator=(const std::initializer_list<value_type> &rhs);

  //**********Element access**********
  T &operator[](size_type n);
  const T &operator[](size_type n) const;
  T &back();
  const T &back() const;
  T &front();
  const T &front() const;

  //**********add and remove elements**********
  void push_back(const T &val);
  void push_back(T &&val);
  void pop_back();

  //**********numbers of elements**********
  std::size_t size() const;
  bool empty() const;
  std::size_t capacity() const;

  //**********iterators**********
  T *begin();
  const T *begin() const;
  const T *cbegin() const;
  T *end();
  const T *end() const;
  const T *cend() const;

private:
  static std::allocator<value_type> alloc;
  value_type *elements;
  value_type *first_free;
  value_type *cap;

  //**********utility functions**********
  std::pair<T*, T*> alloc_n_copy(const T *b, const T *e);
  void free();
  void chk_n_alloc();
  void reallocate();
};

#endif
