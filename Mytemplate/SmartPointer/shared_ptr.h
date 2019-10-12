#ifndef MYSHAREDPTRH
#define MYSHAREDPTRH

#include <initializer_list>
#include <vector>
class deleter {
public:
  virtual void operator()(void *obj) = 0;

  deleter &operator++(){
    ++ref_count_;
    return *this;
  }

  deleter &operator--(){
    --ref_count_;
    return *this;
  }

  explicit operator bool() const {
    if (ref_count_ == 0)
      return false;
    return true;
  }

  int ref_count() const {
    return ref_count_;
  }
  virtual ~deleter(){}

private:
  int ref_count_ = 1;
};

template <typename T, typename D>
class dele_templ :public deleter {
public:
  dele_templ(D d) : del(d){}
  void operator()(void *obj) override{
    del((T*)(obj));
  }

private:
  D del;
};

template <typename T>
class default_del {
public:
  void operator()(T *obj){
    delete obj;
  }
};

template <typename T> class shared_ptr {
public:
  typedef T element_type;
  //**********constructors**********
  template <typename D = default_del<T>> shared_ptr(T* p = nullptr, const D &d = default_del<T>())
    : p_data(p), del(new dele_templ<T,D>(d)) {}
  shared_ptr(const shared_ptr &obj)
    : p_data(obj.p_data), del(obj.del) {
    ++del;
  }

  //**********operators**********
  explicit operator bool() const{
    return p_data;
  }

  shared_ptr &operator=(const shared_ptr &rhs){
    if (this != &rhs) {
      free();
      p_data = rhs.p_data;
      del = rhs.del;
      ++del;
    }
    return *this;
  }

  T& operator*() const {
    return *p_data;
  }

  T* operator->() const {
    return p_data;
  }

  T* get() const {
    return p_data;
  }

  void swap(shared_ptr &obj) {
    auto temp = obj;
    obj = *this;
    *this = temp;
  }

  void reset(shared_ptr &&p){
    if (this != &p) {
      free();
      p_data = p.p_data;
      del = p.del;
      ++del;
    }
  }

  int use_count() const {
    return (*del).ref_count();
  }

  bool unique() const {
    return (*del).ref_count() == 1;
  }

  //**********destructor**********
  ~shared_ptr(){
    free();
  }

private:
  T* p_data;
  deleter *del;
  void free() {
    --*del;
    if (!del) {
      (*del)(p_data);
      delete del;
      del = nullptr;
    }
  }
};

template <typename T> shared_ptr<T> make_shared()
{
  return shared_ptr<T>(new T());
}

template <typename T> shared_ptr<T> make_shared(std::initializer_list<typename T::value_type> ls)
{
  return shared_ptr<T>(new T(ls));
}

template <typename T> shared_ptr<T> make_shared(const T& obj)
{
  return shared_ptr<T>(new T(obj));
}

#endif
