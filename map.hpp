/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:51:17 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/28 04:05:41 by emaugale         ###   ########.fr       */
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
# include "utils/binary_function.hpp"
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
		class value_compare : public ft::binary_function<value_type, value_type, bool>
		{
			friend class ft::map<Key, T, Compare, Allocator>;
			protected:
				Compare comp;
				value_compare(Compare c) : comp(c) { }
				bool operator()( const value_type& lhs, const value_type& rhs ) const
				{
					return (comp(lhs, rhs));
				}
		};
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
		map (InputIterator first, InputIterator last, const key_compare & comp = key_compare(), const allocator_type &alloc = allocator_type(), 
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
		{
			this->_allocator = alloc;
			this->_compare = comp;
			this->_size = 0;
			(void)first;
			(void)last;
		}
		map (const map & copy)
		{
			(void)copy;
		};
		map	&operator= (map &_map)
		{
			std::cout<< &this->_rbt << std::endl;
			this->_rbt = _map._rbt;
			std::cout<< &_map._rbt << std::endl;
			std::cout<< &this->_rbt << std::endl;
			return (*this);
		}
		key_compare		key_comp(void) const {return this->_compare;};
		/* ==================================================================================================== */
		/*												Capacity												*/
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
		/* ==================================================================================================== */
		/*												Element access											*/
		/* ==================================================================================================== */
		mapped_type	&operator[] (const key_type & key)
		{
			/*
				if key is an element of the container
					: -	the function return a refference to its mapped value
				if key does not match any element of the container
					: -	the function insert a new element with that key and return a reference to its mapped value
			*/
			(void)key;
			return (NULL);
		}
		/* ==================================================================================================== */
		/*													Iterators											*/
		/* ==================================================================================================== */
		/* To do in my red_black_tree :
			-	Begin function
			-	End function
		^*/
		iterator	begin(void)
		{
			return (NULL);
			// return (_rbt.begin());
		}
		
		const_iterator	begin(void) const
		{
			return (NULL);
			// return (_rbt.begin());
		}

		iterator	end(void)
		{
			return (NULL);
		// 	return (_rbt.end());
		}
		
		const_iterator	end(void) const
		{
			return (NULL);
		// 	return (_rbt.end());
		}
	
		reverse_iterator	rbegin(void)
		{
			return (NULL);
		}

		const_reverse_iterator	rbegin(void) const
		{
			return (NULL);
		}

		reverse_iterator	rend(void)
		{
			return (NULL);
		}
		
		const_reverse_iterator	rend(void) const
		{
			return (NULL);
		}
		
		private:
		Compare									_compare;
		allocator_type							_allocator;
		size_type								_size;
		RedBlackTree							_rbt;	
	};
}

#endif
