/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:51:17 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/30 06:14:23 by emaugale         ###   ########.fr       */
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
		typedef	typename	ft::RedBlackTree<value_type, key_compare>::iterator		iterator;
		typedef	typename	ft::RedBlackTree<value_type, key_compare>::const_iterator			const_iterator;
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
			for (; first != last; ++first)
				insert(*first);
		}
		map (const map & copy)
		{
			*this = copy;
		}
		map	&operator= (const map & rhs)
		{
			this->_allocator = rhs._allocator;
			this->_compare = rhs._compare;
			this->_rbt.clear();
			this->insert(rhs.begin(), rhs.end());
			this->_size = rhs._size;
			return (*this);
		}
		
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
			return (this->_rbt.max_size());
		}
		/* ===================================================================================================== */
		/*													allocator										 	 */
		/* ===================================================================================================== */

		allocator_type get_allocator() const
		{
			return (this->_allocator);
		}

		/* ==================================================================================================== */
		/*												Element access											*/
		/* ==================================================================================================== */
		mapped_type	&operator[] (const key_type & key)
		{
			return insert(ft::make_pair(key, mapped_type())).first->second;
			/*
				if key is an element of the container
					: -	the function return a refference to its mapped value
				if key does not match any element of the container
					: -	the function insert a new element with that key and return a reference to its mapped value
			*/
		}
		/* ==================================================================================================== */
		/*													Iterators											*/
		/* ==================================================================================================== */
		iterator	begin(void)
		{
			return (this->_rbt.begin());
		}
		
		const_iterator	begin(void) const
		{
			return (this->_rbt.begin());
		}

		iterator	end(void)
		{
			return (this->_rbt.end());
		}
		
		const_iterator	end(void) const
		{
			return (this->_rbt.end());
		}
	
		reverse_iterator	rbegin(void)
		{
			return (reverse_iterator(this->_rbt.end()));
		}

		const_reverse_iterator	rbegin(void) const
		{
			return (const_reverse_iterator(this->_rbt.end()));
		}

		reverse_iterator	rend(void)
		{
			return (const_reverse_iterator(this->_rbt.begin()));
		}
		
		const_reverse_iterator	rend(void) const
		{
			return (const_reverse_iterator(this->_rbt.begin()));
		}
		
		/* ==================================================================================================== */
		/*													Modifiers											*/
		/* ==================================================================================================== */
		ft::pair<iterator, bool>		insert (const value_type &val)
		{
			ft::pair<iterator, bool> res = this->_rbt.insert(val);
			if (res.second)
				++this->_size;
			return (res);
		}
		
		iterator insert (iterator position, const value_type &val)
		{
			(void)position;
			return (this->insert(val).first);
		}
		template <class InputIterator>
		void	insert(InputIterator first, InputIterator last)
		{
			for (; first != last; ++first)
			{
				this->insert(*first);
			}
		}

		void	erase(iterator position)
		{
			this->erase(position->first);
		}
		
		void	erase(iterator first, iterator last)
		{
			iterator tmp;
			while (first != last)
			{
				tmp = first;
				first++;
				this->erase(tmp->first);
			}
		}

		size_type		erase(const key_type &key)
		{
			if (this->_rbt.find(key) == this->end())
				return (0);
			ft::pair<iterator, bool> res = this->_rbt.erase(key);
			if (res.second)
			{
				--this->_size;
				return (1);
			}
			return (0);
		}

		void	swap (map &x)
		{
			ft::swap(this->_allocator, x._allocator);
			ft::swap(this->_compare, x._compare);
			this->_rbt.swap(x._rbt);
			ft::swap(this->_size, x._size);
		}

		void	clear (void)
		{
			if (this->_size > 0)
			{
				this->_rbt.clear();
				this->_size = 0;
			}
		}
		
		/* ==================================================================================================== */
		/*													Observers											*/
		/* ==================================================================================================== */
		
		key_compare	key_comp(void) const
		{
			return (this->_compare);
		}

		value_compare	value_comp(void) const
		{
			return (value_compare(this->_compare));
		}
		
		/* ==================================================================================================== */
		/*													Operations											*/
		/* ==================================================================================================== */
		
		iterator	find (const value_type & key)
		{
			return (this->_rbt.find(key));
		}
		
		const_iterator	find (const value_type & key) const
		{
			return (this->_rbt.find(key));
		}
		
		size_type	count (const key_type &key) const
		{
			return (this->_rbt.find(key) != this->end());
		}
		
		iterator	lower_bound(const key_type &key)
		{
			return (this->_rbt.lower_bound(key));
		}
		
		const_iterator	lower_bound(const key_type &key) const
		{
			return (this->_rbt.lower_bound(key));
		}

		iterator	upper_bound(const key_type &key)
		{
			return (this->_rbt.upper_bound(key));
		}

		const_iterator	upper_bound(const key_type &key) const
		{
			return (this->_rbt.upper_bound(key));
		}
		
		ft::pair<iterator, iterator>	equal_range (const key_type &key)
		{
			return (ft::make_pair(this->lower_bound(key), this->upper_bound(key)));
		}
		
		ft::pair<const_iterator, const_iterator>	equal_range (const key_type &key) const
		{
			return (ft::make_pair(this->lower_bound(key), this->upper_bound(key)));
		}
		
		private:
		Compare															_compare;
		allocator_type													_allocator;
		size_type														_size;
		RedBlackTree<value_type, key_compare>							_rbt;	
	};
	
template <typename Key, typename T, typename Compare, typename Allocator>
	bool operator==(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs) {
		typename map<Key, T, Compare, Allocator>::const_iterator	it = lhs.begin();
		typename map<Key, T, Compare, Allocator>::const_iterator	ite = lhs.end();
		typename map<Key, T, Compare, Allocator>::const_iterator	it2 = rhs.begin();
		while (it != ite && it2 != rhs.end()) {
			if (it->first != it2->first || it->second != it2->second)
				return (false);
			it++;
			it2++;
		}
		return (it == ite && it2 == rhs.end());
	};
	template <typename Key, typename T, typename Compare, typename Allocator>
	bool operator!=(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs){return (!(lhs == rhs));};

	template <typename Key, typename T, typename Compare, typename Allocator>
	bool operator<(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs) {
		typename map<Key, T, Compare, Allocator>::const_iterator	it = lhs.begin();
		typename map<Key, T, Compare, Allocator>::const_iterator	ite = lhs.end();
		typename map<Key, T, Compare, Allocator>::const_iterator	it2 = rhs.begin();

		while (it != ite && it2 != rhs.end()) {
			if (it->first != it2->first)
				return (it->first < it2->first);
			else if (it->second != it2->second)
				return (it->second < it2->second);
			it++;
			it2++;
		}
		return (it == ite && it2 != rhs.end());
	};
	template <typename Key, typename T, typename Compare, typename Allocator>
	bool operator>(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs) {return ((rhs < lhs) and lhs != rhs);};
	template <typename Key, typename T, typename Compare, typename Allocator>
	bool operator<=(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs) {return (!(rhs < lhs));};
	template <typename Key, typename T, typename Compare, typename Allocator>
	bool operator>=(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs) {return (!(lhs < rhs));};

	template <typename Key, typename T, typename Compare, typename Allocator>
	void swap(map<Key, T, Compare, Allocator> &lhs, map<Key, T, Compare, Allocator> &rhs) {lhs.swap(rhs);};

}

#endif
