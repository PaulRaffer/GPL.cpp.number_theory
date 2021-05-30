
// Copyright Paul Raffer 2020.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#if __cplusplus >= 201402L

#ifndef GPL_NUMBER_THEORY_NUMBER_THEORY_HPP
#define GPL_NUMBER_THEORY_NUMBER_THEORY_HPP

#define gpl_cpp_number_theory__          202007L
#define gpl_cpp_number_theory_odd_even__ 202005L
#define gpl_cpp_number_theory_prime__    202007L
#define gpl_cpp_number_theory_digit__    202006L


#include <cmath>


namespace gpl { // interface

template <typename T>
constexpr auto is_odd(T x) -> bool;

template <typename T>
constexpr auto is_even(T x) -> bool;


template <typename T>
constexpr auto is_prime(T x) -> bool;

template <typename T>
constexpr auto prime(T x) -> int;


template <typename T>
auto digit(T x, int d, int n = 1, int base = 10) -> int;

} // namespace gpl





namespace gpl { // implementation

template <typename T>
constexpr auto is_odd(T x) -> bool
{
	return x & 1;
}

template <typename T>
constexpr auto is_even(T x) -> bool
{
	return !is_odd(x);
}

template <typename T>
constexpr auto is_prime(T x) -> bool
{
	for (auto i = 3; i <= sqrt(x); i += 2)
		if (x % i == 0)
			return false;
	return true;
}

template <typename T> constexpr auto prime(T x) -> int
{
	constexpr auto offset = 0;
	if (x == offset)
		return 2;
	auto p = 3;
	for (decltype(x) count = offset + 1; count < x; )
		if (is_prime(p += 2))
			++count;
	return p;
}



template <typename T>
auto digit(T x, int d, int n, int base) -> int
{
	return
			static_cast<int>(x / std::pow(base, d)) %
			static_cast<int>(std::pow(base, n));
}

} // namespace gpl


#endif // GPL_NUMBER_THEORY_NUMBER_THEORY_HPP

#endif // __cplusplus >= 201402L
