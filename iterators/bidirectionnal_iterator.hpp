/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:27:48 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/08 01:27:48 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONNAL_ITERATOR_HPP
# define BIDIRECTIONNAL_ITERATOR_HPP
# include "iterator.hpp"
# include "iterators_traits.hpp"
# include <iterator>

namespace ft
{
	template <class Iterator>
	class bidirectional_iterator : ft::iterator<std::bidirectional_iterator_tag, Iterator>
	{
		public:
			typedef Iterator																						iterator_type;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, Iterator>::iterator_category 			iterator_category;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, Iterator>::value_type 					value_type;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, Iterator>::difference_type 				difference_type;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, Iterator>::pointer 						pointer;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, Iterator>::reference 					reference;

			/*												constructors											*/
		
			bidirectional_iterator(void) : _p() {return;};
			bidirectional_iterator(pointer p) : _p(p) {return;};
			bidirectional_iterator(const bidirectional_iterator& cpy) : _p(cpy._p) {return;};
			pointer base(void) const {return this->_p;};

			/* ===================================================================================================== */
				
			/*												operators												*/
			reference operator*(void) const {return *this->_p;};
			pointer operator->(void) const {return &(this->operator*());};
		
			bidirectional_iterator &operator=(const bidirectional_iterator &rhs)
			{
				if (*this == rhs)
					return (*this);
				else
					this->_p = rhs._p;
				return (*this);
			}

			bidirectional_iterator &operator++(void)
			{
				++this->_p;
				return (*this);
			}

			bidirectional_iterator operator++(int)
			{
				bidirectional_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			bidirectional_iterator operator+(const difference_type n)
			{
				return (this->_p + n);
			}

			bidirectional_iterator operator-(const difference_type n)
			{
				return (this->_p - n);
			}

			bidirectional_iterator &operator--(void)
			{
				--this->_p;
				return (*this);
			}

			bidirectional_iterator operator--(int)
			{
				bidirectional_iterator tmp(*this);
				operator--();
				return (tmp);
			}

			difference_type operator-(const bidirectional_iterator &rhs) const
			{
				return (this->_p - rhs._p);
			}
			/* ===================================================================================================== */
			bool operator==(const bidirectional_iterator& op) const 
			{
				return (this->_p == op._p);
			};
			bool operator!=(const bidirectional_iterator& op) const 
			{
				return (this->_p != op._p);
			};
			bool operator<(const bidirectional_iterator& op) const 
			{
				return (this->_p < op._p);}
			;
			bool operator<=(const bidirectional_iterator& op) const 
			{
				return (this->_p <= op._p);
			};
			bool operator>(const bidirectional_iterator& op) const 
			{
				return (this->_p > op._p);}
			;
			bool operator>=(const bidirectional_iterator& op) const 
			{
				return (this->_p >= op._p);
			};
		
			reference operator[](const difference_type n) const 
			{
				return (this->_p[n]);
			};
			operator bidirectional_iterator<const value_type>() const 
			{
				return (bidirectional_iterator<const value_type>(_p));
			};

		private:
			pointer	_p;
	};

	template <class Iterator>
	bool operator<(const ft::bidirectional_iterator<Iterator>& lhs, const ft::bidirectional_iterator<Iterator>& rhs)
	{
		return (lhs < rhs);
	};
	
	template <class Iterator1, class Iterator2>
	bool operator<(const ft::bidirectional_iterator<Iterator1> lhs, const ft::bidirectional_iterator<Iterator2> rhs) 
	{
		return (lhs.base() < rhs.base());};
	
	template <class Iterator>
	bool operator>(const ft::bidirectional_iterator<Iterator>& lhs, const ft::bidirectional_iterator<Iterator>& rhs) 
	{
		return (lhs > rhs);
	};

	template <class Iterator1, class Iterator2>
	bool operator>(const ft::bidirectional_iterator<Iterator1> lhs, const ft::bidirectional_iterator<Iterator2> rhs) 
	{
		return (lhs.base() > rhs.base());
	};

	template <class Iterator>
	bool operator>=(const ft::bidirectional_iterator<Iterator>& lhs, const ft::bidirectional_iterator<Iterator>& rhs) 
	{
		return (lhs >= rhs);
	};

	template <class Iterator1, class Iterator2>
	bool operator>=(const ft::bidirectional_iterator<Iterator1> lhs, const ft::bidirectional_iterator<Iterator2> rhs) 
	{
		return (lhs.base() >= rhs.base());
	};

	template <class Iterator>
	bool operator<=(const ft::bidirectional_iterator<Iterator>& lhs, const ft::bidirectional_iterator<Iterator>& rhs) 
	{
		return (lhs <= rhs);
	};

	template <class Iterator1, class Iterator2>
	bool operator<=(const ft::bidirectional_iterator<Iterator1> lhs, const ft::bidirectional_iterator<Iterator2> rhs) 
	{
		return (lhs.base() <= rhs.base());
	};

	template <class Iterator>
	bool operator==(const ft::bidirectional_iterator<Iterator>& lhs, const ft::bidirectional_iterator<Iterator>& rhs) 
	{
		return (lhs == rhs);
	};

	template <class Iterator1, class Iterator2>
	bool operator==(const ft::bidirectional_iterator<Iterator1> lhs, const ft::bidirectional_iterator<Iterator2> rhs) 
	{
		return (lhs.base() == rhs.base());
	};

	template <class Iterator>
	bool operator!=(const ft::bidirectional_iterator<Iterator>& lhs, const ft::bidirectional_iterator<Iterator>& rhs) 
	{
		return (lhs != rhs);
	};

	template <class Iterator1, class Iterator2>
	bool operator!=(const ft::bidirectional_iterator<Iterator1> lhs, const ft::bidirectional_iterator<Iterator2> rhs) 
	{
		return (lhs.base() != rhs.base());
	};

	template <class Iterator>
	typename ft::bidirectional_iterator<Iterator>::difference_type operator-(const ft::bidirectional_iterator<Iterator>& lhs, const ft::bidirectional_iterator<Iterator>& rhs) 
	{
		return (lhs - rhs);
	};
	template <class Iterator1, class Iterator2>
	typename ft::bidirectional_iterator<Iterator1>::difference_type operator-(const ft::bidirectional_iterator<Iterator1> lhs, const ft::bidirectional_iterator<Iterator2> rhs) 
	{
		return (lhs.base() - rhs.base());
	};
	template <typename Iterator>
	ft::bidirectional_iterator<Iterator> operator-(typename bidirectional_iterator<Iterator>::difference_type n, const ft::bidirectional_iterator<Iterator>& lhs) 
	{
		return (lhs - n);
	};

	template <class Iterator>
	typename ft::bidirectional_iterator<Iterator>::difference_type operator+(const ft::bidirectional_iterator<Iterator>& lhs, const ft::bidirectional_iterator<Iterator>& rhs) 
	{
		return (lhs + rhs);
	};
	template <class Iterator1, class Iterator2>
	typename ft::bidirectional_iterator<Iterator1>::difference_type operator+(const ft::bidirectional_iterator<Iterator1> lhs, const ft::bidirectional_iterator<Iterator2> rhs) 
	{
		return (lhs.base() + rhs.base());
	};
	template <typename Iterator>
	ft::bidirectional_iterator<Iterator> operator+(typename bidirectional_iterator<Iterator>::difference_type n, ft::bidirectional_iterator<Iterator>& lhs) 
	{
		return (lhs + n);
	};

}

#endif