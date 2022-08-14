// SPDX-License-Identifier: BSD-3-Clause
// Copyright (C) Ivan Pizhenko, 2022. All rights reserved.

#ifndef CPPUTILS__TYPE_TRAITS_EXT_H__
#define CPPUTILS__TYPE_TRAITS_EXT_H__

#include <type_traits>

namespace stdx {

#ifndef __cpp_lib_type_identity

template<class T>
using type_identity = std::type_identity<T>;

#else

template<class T>
struct type_identity {
  typedef T type;
};
  
template<class T>
using type_identity_t = type_identity<T>::type;

#endif

template<typename T, typename...> 
struct first_type: type_identity<T>
{
};

template<typename T, typename...> 
using first_type_t = typename first_type<T>::type;  

template<typename ...Types> 
struct indirect_void_t = typename first_type<void, Types...>::type;
  
}  // namespace stdx

#endif  // CPPUTILS__TYPE_TRAITS_EXT_H__
