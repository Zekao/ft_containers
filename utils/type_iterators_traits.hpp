/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_iterators_traits.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:29:46 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/10 22:29:46 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_ITERATORS_TRAITS_HPP
# define TYPE_ITERATORS_TRAITS_HPP

namespace ft
{
	template <bool B, class T = void>
	struct enable_if
	{};

	template <bool B, typename T>
	struct is_integral_type
	{
		typedef T type;
		static const bool value = B;
	};

	template <typename T = void>
	struct is_integral : is_integral_type<false, T>
	{

	};

	template <>
	struct is_integral<bool>: is_integral_type<true, bool>
	{
	};
	
	template <>
	struct is_integral<char>: is_integral_type<true, char>
	{
	};

	template <>
	struct is_integral<wchar_t>: is_integral_type<true, wchar_t>
	{
	};

	template <>
	struct is_integral<signed char>: is_integral_type<true, signed char>
	{
	};

	template <>
	struct is_integral<unsigned char>: is_integral_type<true, unsigned char>
	{
	};

	template <>
	struct is_integral<short int>: is_integral_type<true, short int>
	{
	};

	template <>
	struct is_integral<int>: is_integral_type<true, int>
	{
	};

	template <>
	struct is_integral<long int>: is_integral_type<true, long int>
	{
	};

	template <>
	struct is_integral<long long int>: is_integral_type<true, long long int>
	{
	};

	template <>
	struct is_integral<unsigned short int>: is_integral_type<true, unsigned short int>
	{
	};

	template <>
	struct is_integral<unsigned int>: is_integral_type<true, unsigned int>
	{
	};

	template <>
	struct is_integral<unsigned long int>: is_integral_type<true, unsigned long int>
	{
	};

	template <>
	struct is_integral<unsigned long long int>: is_integral_type<true, unsigned long long int>
	{
	};

} 

#endif