#ifndef Rice__Type__hpp_
#define Rice__Type__hpp_

#include <string>
#include <typeinfo>
#include "rice_traits.hpp"

namespace Rice::detail
{
  template <typename T, typename = void>
  struct is_builtin : public std::false_type {};

  template <typename T>
  constexpr bool is_builtin_v = is_builtin<T>::value;

  template<typename T>
  struct Type
  {
    static constexpr void verify();
  };

  // Return the name of a type
  std::string typeName(const std::type_info& typeInfo);
  std::string makeClassName(const std::type_info& typeInfo);

  template<typename T>
  void verifyType();

  template<typename Tuple_T>
  constexpr void verifyTypes();
}

#endif // Rice__Type__hpp_
