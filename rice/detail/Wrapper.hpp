#ifndef Rice__detail__Wrapper__hpp_
#define Rice__detail__Wrapper__hpp_

#include "ruby.hpp"

namespace Rice
{
namespace detail
{

class Wrapper
{
public:
  virtual ~Wrapper() = default;
  virtual void* get() = 0;

  void ruby_mark();
  void addKeepAlive(VALUE value);
  
  bool isOwner_ = true;

private:
  // We use a vector for speed and memory locality versus a set which does
  // not scale when getting to tens of thousands of objects (not expecting
  // that to happen...but just in case)
  std::vector<VALUE> keepAlive_;
};

template <typename T>
VALUE wrap(VALUE klass, rb_data_type_t* rb_type, T&& data);

template <typename T>
VALUE wrap(VALUE klass, rb_data_type_t* rb_type, T* data);

template <typename T>
T* unwrap(VALUE value, rb_data_type_t* rb_type);

void* unwrap(VALUE value);

template <typename T>
void replace(VALUE value, rb_data_type_t* rb_type, T* data);

Wrapper* getWrapper(VALUE value);

} // namespace detail
} // namespace Rice

#include "Wrapper.ipp"

#endif // Rice__detail__Wrapper__hpp_
