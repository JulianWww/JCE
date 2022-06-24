#pragma once

#include <memory>
#include <type_traits>

#define JCE_PTR_OPERATION(type, op) \
template<typename T> template<typename Other> \
bool& jce:: type <T>::operator op(const Other& other) { \
  if constexpr (std::is_same<Other, compPtr>()) \
    return *this op *other; \
  return *this op other; \
}

namespace jce {
  struct compPtr {};
  template<typename T>
  struct unique_ptr: public std::unique_ptr<T>, compPtr {
    template<typename Other> bool& operator<(const Other&);
    template<typename Other> bool& operator>(const Other&);
    template<typename Other> bool& operator<=(const Other&);
    template<typename Other> bool& operator>=(const Other&);
    template<typename Other> bool& operator==(const Other&);
  };

  template <typename T>
  struct weak_ptr: public std::weak_ptr<T>, compPtr {
    template<typename Other> bool& operator<(const Other&);
    template<typename Other> bool& operator>(const Other&);
    template<typename Other> bool& operator<=(const Other&);
    template<typename Other> bool& operator>=(const Other&);
    template<typename Other> bool& operator==(const Other&);
  };
}

JCE_PTR_OPERATION(unique_ptr, <)
JCE_PTR_OPERATION(unique_ptr, >)
JCE_PTR_OPERATION(unique_ptr, <=)
JCE_PTR_OPERATION(unique_ptr, >=)
JCE_PTR_OPERATION(unique_ptr, ==)

JCE_PTR_OPERATION(weak_ptr, <)
JCE_PTR_OPERATION(weak_ptr, >)
JCE_PTR_OPERATION(weak_ptr, <=)
JCE_PTR_OPERATION(weak_ptr, >=)
JCE_PTR_OPERATION(weak_ptr, ==)