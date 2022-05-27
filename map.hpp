/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:51:17 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/27 18:16:19 by emaugale         ###   ########.fr       */
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
# include "utils/less.hpp"
# include "utils/red_black_tree.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
		typedef				Key														key_type;
		typedef				T														mapped_type;
		typedef				ft::pair<const key_type, mapped_type>					value_type;
		typedef				Compare													key_compare;
		typedef				Allocator												allocator_type;
		typedef typename	allocator_type::reference								reference;
		typedef typename 	allocator_type::const_reference							const_reference;
		typedef typename	allocator_type::pointer									pointer;
		typedef typename	allocator_type::const_pointer							const_pointer;
		typedef	typename	ft::bidirectional_iterator<value_type>					iterator;
		typedef	typename	ft::bidirectional_iterator<const value_type>			const_iterator;
		typedef	typename	ft::reverse_iterator<iterator>							reverse_iterator;
		typedef	typename	ft::reverse_iterator<const iterator>					const_reverse_iterator;
		typedef	typename	allocator_type::difference_type							difference_type;
		typedef	typename	allocator_type::size_type								size_type;
		
		/* ==================================================================================================== */
		/*												Constructors											*/
		/* ==================================================================================================== */

		explicit map (const key_compare& comp = key_compare(), const allocator_type &alloc = allocator_type())
		{
			this->_allocator = alloc;
			this->_size = 0;
			this->_compare = comp;
		}
		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare & comp = key_compare())
		{
			(void)first;
			(void)last;
			(void)comp;
		}
		map (const map & copy);
		key_compare		key_comp(void) const {return this->_compare;};
		/* ==================================================================================================== */
		/*												Capacity											*/
		/* ==================================================================================================== */
		bool empty(void) const
		{
			if (this->_size == 0)
				return (true);
			return (false);	
		}
		
		size_type	size(void) const
		{
			return (this->_size);
		}
		
		size_type	max_size(void) const
		{
			return (this->_allocator.max_size());
		}
		private:
		Compare									_compare;
		allocator_type							_allocator;
		size_type								_size;
		RedBlackTree							_rbt;	
	};
}

#endif