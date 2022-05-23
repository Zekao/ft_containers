/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:51:17 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/23 21:16:01 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <stdexcept>
# include <iostream>
# include "iterators/iterators_traits.hpp"
# include "iterators/random_access_iterator.hpp"
# include "iterators/reverse_iterator.hpp"
# include "utils/type_traits.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class map
	{
		public:
		typedef				T									value_type;
		typedef				Allocator							allocator_type;
		typedef typename	allocator_type::reference			allocator_type;
		typedef typename 	allocator_type::const_reference		const_reference;
		typedef typename	allocator_type::pointer				pointer;
		typedef typename	allocator_type::const_pointer		const_pointer;
		typedef	typename	ft::random_access_iterator			iterator;
		typedef	typename	ft::random_access_iterator			const_iterator;
		typedef	typename	ft::
		
	};
}

#endif