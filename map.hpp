/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:51:17 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/24 22:43:21 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <stdexcept>
# include <iostream>
# include "iterators/iterators_traits.hpp"
# include "iterators/random_access_iterator.hpp"
# include "iterators/bidirectionnal_iterator.hpp"
# include "iterators/reverse_iterator.hpp"
# include "utils/type_traits.hpp"
# include "utils/pair.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
		typedef				T											value_type;
		typedef				Allocator									allocator_type;
		typedef typename	allocator_type::reference					reference;
		typedef typename 	allocator_type::const_reference				const_reference;
		typedef typename	allocator_type::pointer						pointer;
		typedef typename	allocator_type::const_pointer				const_pointer;
		typedef	typename	ft::bidirectional_iterator<value_type>					iterator;
		typedef	typename	ft::bidirectional_iterator<const value_type>		const_iterator;
		typedef	typename	ft::reverse_iterator<iterator>				reverse_iterator;
		typedef	typename	ft::reverse_iterator<const iterator>		const_reverse_iterator;
		typedef	typename	allocator_type::difference_type				difference_type;
		typedef	typename	allocator_type::size_type					size_type;
		
	};
}

#endif