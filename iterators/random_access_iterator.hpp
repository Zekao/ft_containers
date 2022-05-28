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

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP
# include "iterator.hpp"
# include "iterators_traits.hpp"
# include <iterator>

namespace ft
{
	template <class Iterator>
	class random_access_iterator : ft::iterator<std::random_access_iterator_tag, Iterator>
	{
		public:
			typedef Iterator																						iterator_type;
			typedef typename ft::iterator<std::random_access_iterator_tag, Iterator>::iterator_category 			iterator_category;
			typedef typename ft::iterator<std::random_access_iterator_tag, Iterator>::value_type 					value_type;
			typedef typename ft::iterator<std::random_access_iterator_tag, Iterator>::difference_type 				difference_type;
			typedef typename ft::iterator<std::random_access_iterator_tag, Iterator>::pointer 						pointer;
			typedef typename ft::iterator<std::random_access_iterator_tag, Iterator>::reference 					reference;

			/*												constructors											*/
		
			random_access_iterator(void) : _p() {return;};
			random_access_iterator(pointer p) : _p(p) {return;};
			random_access_iterator(const random_access_iterator& cpy) : _p(cpy._p) {return;};
			pointer base(void) const {return this->_p;};

			/* ===================================================================================================== */
				
			/*												operators												*/
			reference operator*(void) const {return *this->_p;};
			pointer operator->(void) const {return &(this->operator*());};
		
			random_access_iterator &operator=(const random_access_iterator &rhs)
			{
				if (*this == rhs)
					return (*this);
				else
					this->_p = rhs._p;
				return (*this);
			}

			random_access_iterator &operator++(void)
			{
				++this->_p;
				return (*this);
			}

			random_access_iterator operator++(int)
			{
				random_access_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			random_access_iterator &operator+=(const difference_type n)
			{
				this->_p += n;
				return (*this);
			}

			random_access_iterator operator+(const difference_type n)
			{
				return (this->_p + n);
			}

			random_access_iterator &operator-=(const difference_type n)
			{
				this->_p -= n;
				return (*this);
			}

			random_access_iterator operator-(const difference_type n)
			{
				return (this->_p - n);
			}

			random_access_iterator &operator--(void)
			{
				--this->_p;
				return (*this);
			}

			random_access_iterator operator--(int)
			{
				random_access_iterator tmp(*this);
				operator--();
				return (tmp);
			}

			difference_type operator-(const random_access_iterator &rhs) const
			{
				return (this->_p - rhs._p);
			}
			/* ===================================================================================================== */
			bool operator==(const random_access_iterator& op) const 
			{
				return (this->_p == op._p);
			};
			bool operator!=(const random_access_iterator& op) const 
			{
				return (this->_p != op._p);
			};
			bool operator<(const random_access_iterator& op) const 
			{
				return (this->_p < op._p);}
			;
			bool operator<=(const random_access_iterator& op) const 
			{
				return (this->_p <= op._p);
			};
			bool operator>(const random_access_iterator& op) const 
			{
				return (this->_p > op._p);}
			;
			bool operator>=(const random_access_iterator& op) const 
			{
				return (this->_p >= op._p);
			};
		
			reference operator[](const difference_type n) const 
			{
				return (this->_p[n]);
			};
			operator random_access_iterator<const value_type>() const 
			{
				return (random_access_iterator<const value_type>(_p));
			};

		private:
			pointer	_p;
	};

	template <class Iterator>
	bool operator<(const ft::random_access_iterator<Iterator>& lhs, const ft::random_access_iterator<Iterator>& rhs)
	{
		return (lhs < rhs);
	}
	
	template <class Iterator1, class Iterator2>
	bool operator<(const ft::random_access_iterator<Iterator1> lhs, const ft::random_access_iterator<Iterator2> rhs) 
	{
		return (lhs.base() < rhs.base());
	}
	
	template <class Iterator>
	bool operator>(const ft::random_access_iterator<Iterator>& lhs, const ft::random_access_iterator<Iterator>& rhs) 
	{
		return (lhs > rhs);
	}

	template <class Iterator1, class Iterator2>
	bool operator>(const ft::random_access_iterator<Iterator1> lhs, const ft::random_access_iterator<Iterator2> rhs) 
	{
		return (lhs.base() > rhs.base());
	}

	template <class Iterator>
	bool operator>=(const ft::random_access_iterator<Iterator>& lhs, const ft::random_access_iterator<Iterator>& rhs) 
	{
		return (lhs >= rhs);
	}

	template <class Iterator1, class Iterator2>
	bool operator>=(const ft::random_access_iterator<Iterator1> lhs, const ft::random_access_iterator<Iterator2> rhs) 
	{
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator>
	bool operator<=(const ft::random_access_iterator<Iterator>& lhs, const ft::random_access_iterator<Iterator>& rhs) 
	{
		return (lhs <= rhs);
	}

	template <class Iterator1, class Iterator2>
	bool operator<=(const ft::random_access_iterator<Iterator1> lhs, const ft::random_access_iterator<Iterator2> rhs) 
	{
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator>
	bool operator==(const ft::random_access_iterator<Iterator>& lhs, const ft::random_access_iterator<Iterator>& rhs) 
	{
		return (lhs == rhs);
	}

	template <class Iterator1, class Iterator2>
	bool operator==(const ft::random_access_iterator<Iterator1> lhs, const ft::random_access_iterator<Iterator2> rhs) 
	{
		return (lhs.base() == rhs.base());
	}

	template <class Iterator>
	bool operator!=(const ft::random_access_iterator<Iterator>& lhs, const ft::random_access_iterator<Iterator>& rhs) 
	{
		return (lhs != rhs);
	}

	template <class Iterator1, class Iterator2>
	bool operator!=(const ft::random_access_iterator<Iterator1> lhs, const ft::random_access_iterator<Iterator2> rhs) 
	{
		return (lhs.base() != rhs.base());
	}

	template <class Iterator>
	typename ft::random_access_iterator<Iterator>::difference_type operator-(const ft::random_access_iterator<Iterator>& lhs, const ft::random_access_iterator<Iterator>& rhs) 
	{
		return (lhs - rhs);
	}
	template <class Iterator1, class Iterator2>
	typename ft::random_access_iterator<Iterator1>::difference_type operator-(const ft::random_access_iterator<Iterator1> lhs, const ft::random_access_iterator<Iterator2> rhs) 
	{
		return (lhs.base() - rhs.base());
	}
	template <typename Iterator>
	ft::random_access_iterator<Iterator> operator-(typename random_access_iterator<Iterator>::difference_type n, const ft::random_access_iterator<Iterator>& lhs) 
	{
		return (lhs - n);
	}

	template <class Iterator>
	typename ft::random_access_iterator<Iterator>::difference_type operator+(const ft::random_access_iterator<Iterator>& lhs, const ft::random_access_iterator<Iterator>& rhs) 
	{
		return (lhs + rhs);
	}
	template <class Iterator1, class Iterator2>
	typename ft::random_access_iterator<Iterator1>::difference_type operator+(const ft::random_access_iterator<Iterator1> lhs, const ft::random_access_iterator<Iterator2> rhs) 
	{
		return (lhs.base() + rhs.base());
	}
	template <typename Iterator>
	ft::random_access_iterator<Iterator> operator+(typename random_access_iterator<Iterator>::difference_type n, ft::random_access_iterator<Iterator>& lhs) 
	{
		return (lhs + n);
	}

}

#endif
