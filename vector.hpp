/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 23:13:30 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/07 18:41:52 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <vector>
# include <memory>
# include <stdexcept>
# include <iostream>
// # include "iterators/iterators_traits.hpp"

namespace ft
{
	
	template < class T, class Allocator = std::allocator<T> > // generic template
	class vector
	{
		public:
			typedef				T														value_type;
			typedef				Allocator												allocator_type;
			typedef	typename 	allocator_type::reference								reference;
			typedef	typename 	allocator_type::const_reference							const_reference;	
			typedef	typename 	allocator_type::pointer									pointer;
			typedef	typename	allocator_type::const_pointer							const_pointer;
			// typedef				std::random_access_iterator<value_type>						iterator;
			// typedef				ft::random_access_iterator<const value_type>			const_iterator;
			// typedef				ft::reverse_iterator<iterator>						reverse_iterator;
			// typedef				ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef typename	Allocator::size_type										size_type;
			typedef typename	Allocator::difference_type									difference_type;
			
			/*												Constructors											*/
			
			explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0)
			{
				this->_allocator = alloc;
			};
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{
				this->_size = n;
				this->_vector = val;
				this->_allocator = alloc;				
				// Construct a container with n elements
				// each element is a copy of val
			}
			template <class InputIterator>
         	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			vector (const vector& x)
			{
				*this = x;
			}
			~vector()
			{
				
			}
			
			/* ===================================================================================================== */

			/*									Capacity member functions											*/
			size_type	size(void) const
			{
				return (this->_size);
			}
			size_type	max_size(void) const
			{
				return (this->_allocator.max_size());
			}
			void	resize(size_t n, value_type val = value_type()) const
			{
				(void)val;
				if (n < this->_size)
				{
					for (size_type i = n; i < this->_size; i++)
					{
						this->_allocator.destroy(&this->_vector[i]);
					}
					this->_size = n;
				}
			}
			size_type	capacity(void) const
			{
				return (this->_capacity);
			}
			bool	empty(void) const
			{
				if (this->_size != 0)
					return (false);
				else
					return (true);
			}
			void	reserve (size_type n)
			{
			// 	/*				differents cas				*/
					// - si n > la capacity la fonction realloue la taille demandée pour augmenter la capacity a n
					// - dans les autres cas on ne realloue pas et on supprime juste la quantitée d'elements apres n (vector::erase)
				if (n > this->_capacity)
				{
					// vector::resize(n, this->_vector);
					// ft::resize(this->_vector);
				}
				else if (n < this->_capacity)
				{
					while (n < this->_size)
					{
						// vector::erase(n);
						// ft::erase(this->_vector[n]);
						n--;
					}
				}
			};
			/* ===================================================================================================== */

			/*											element access												*/
			reference operator[](size_type n)
			{
				return (this->_vector[n]);
			};
			const_reference operator[](size_type n) const
			{
				return (this->_vector[n]);
			};
			reference 		at(size_t n) // return a reference to the element n in the vector -> throw execption if n > size
			{
				if (n > this->_size)
					throw std::out_of_range("vector::at");
				return (this->_vector[n]);
			};
			const_reference at(size_type n) const // return a reference to the element n in the vector
			{
				if (n > this->_size)
					throw std::out_of_range("vector::at");
				return (this->_vector[n]);
			};
			// reference		front(); // return a reference to the first element in the vector
			// const_reference	front();
			// reference		back(); // return a reference to the last element in the vector
			// const_reference	back();
			/* ===================================================================================================== */
			
			/*												modifiers												*/

		
		
		// template <class InputIterator>
		// explicit vector (const allocator_type& alloc = allocator_type()); // default constructor
		// explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()); // fill constructor
        // vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()); // range constructor
		// vector (const vector &x){ *this = x; } // copy constructor
		
			/* ===================================================================================================== */
		
			/*												allocator												*/
		
			allocator_type get_allocator() const
			{
				return (this->_allocator);
			}

			/* ===================================================================================================== */
		
		private:
		allocator_type	_allocator;
		pointer			_vector;
		size_type		_size;
		size_type		_capacity;
	};
	/*											operators overload												*/
template< class T, class Alloc >
bool operator==( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	if (lhs.size() == rhs.size())
		return (false);
	return(std::equal(lhs.begin(), rhs.begin()));
}

template< class T, class Alloc >
bool operator!=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	return (!(lhs == rhs));
}

template< class T, class Alloc >
bool operator<( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template< class T, class Alloc >
bool operator<=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	return (!(rhs < lhs));
}

template< class T, class Alloc >
bool operator>( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	return (rhs < lhs);
}

template< class T, class Alloc >
bool operator>=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	if (lhs > rhs)
		return (true);
	return (false);
}
	/* ===================================================================================================== */

}


#endif
