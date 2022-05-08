/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 00:40:06 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/05 00:40:06 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterators_traits.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
		public:
			typedef Iterator 												iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;

		private:
			iterator_type	_it;
		public:
			/* ===================================================================================================== */
			/*												constructors											 */
			/* ===================================================================================================== */
			reverse_iterator() : _it()
			{
				return;
			}
			explicit reverse_iterator(iterator_type it) : _it(it)
			{
				return ;
			}
			template <class IteratorCpy>
			reverse_iterator (const reverse_iterator<IteratorCpy> &rhs)
			{
				this->_it = rhs.base();
			}
			~reverse_iterator();
			/* ===================================================================================================== */
			/*												member functions										 */
			/* ===================================================================================================== */
			iterator_type base(void) const 
			{
				return this->_it;
			}
			reference operator*() const
			{
				iterator_type tmp (*this);
				return (*--tmp);
			}
			reverse_iterator operator+(difference_type n) const
			{
				return (this->_it - n);
			}
			reverse_iterator &operator++()
			{
				--this->_it;
				return (*this);
			}
			reverse_iterator operator++(int)
			{
				reverse_iterator tmp = *this;
				++(*this);
				return (tmp);
			}
			reverse_iterator &operator+=(difference_type n)
			{
				this->_it -= n;
				return (*this);
			}
			reverse_iterator operator-(difference_type n) const
			{
				return(this->_it + n);
			}
			reverse_iterator &operator --()
			{
				++this->_it;
				return (*this);
			}
			reverse_iterator operator--(int)
			{
				reverse_iterator tmp = *this;
				--(*this);
				return (tmp);
			}
			reverse_iterator operator-=(difference_type n)
			{
				this->_it += n;
				return (*this);
			}
			pointer operator->() const
			{
				return &(operator*());
			}
			reference operator[] (difference_type n) const
			{
				reutnr (this->_it - n - 1);
			}

	};
	/* ===================================================================================================== */
	/*									non-member function overloads									   	 */
	/* ===================================================================================================== */

	/* ===================================================================================================== */
	/*										relational overloads										   	 */
	/* ===================================================================================================== */
	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	}
	template <class Iterator>
	bool operator< (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() > rhs.base());
	}
	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}
	template <class Iterator>
	bool operator> (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() < rhs.base());
	}
	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}
	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it)
	{
		return(rev_it + n);
	};
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		reutrn (lhs.base() - rhs.base());
	}
}
#endif