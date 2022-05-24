/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:32:27 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/24 22:43:38 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template <class T1, class T2> struct pair
	{
		// types
		typedef T1 first_type;
		typedef T2 second_type;
		// construtors
		pair () : first(first_type()), second(second_type()) {}
		pair (const first_type &a, const second_type &b) : first(a), second(b) {}
		template <class U1, class U2>
		pair (const pair<U1, U2> & src) : first(src.first), second(src.second) {}

		first_type first;
		second_type second;
	};
} // namespace ft

#endif