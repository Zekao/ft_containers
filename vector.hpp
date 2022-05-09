/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 23:13:30 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/09 11:15:36 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <vector>
# include <memory>
# include <stdexcept>
# include <iostream>
# include "iterators/iterators_traits.hpp"
# include "iterators/random_access_iterator.hpp"
# include "iterators/reverse_iterator.hpp"
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
			typedef				ft::random_access_iterator<value_type>						iterator;
			typedef				ft::random_access_iterator<const value_type>			const_iterator;
			typedef				ft::reverse_iterator<iterator>						reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>					const_reverse_iterator;
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
			/*													Iterators											 */
			/* ===================================================================================================== */

			iterator begin(void)
			{
				return (iterator(this->_vector));
			}
			
			const_iterator begin(void) const
			{
				return (const_iterator(this->_vector));
			}

			iterator end(void)
			{
				return (iterator(this->_vector + this->_size));
			}
			
			const_iterator end(void) const
			{
				return (const_iterator(this->_vector + this->_size));
			}
			
			reverse_iterator rbegin(void)
			{
				return (reverse_iterator(this->_vector + this->_size));
			}

			const_reverse_iterator rbegin(void) const
			{
				return (const_reverse_iterator(this->_vector + this->_size));
			}
			
			reverse_iterator rend(void)
			{
				return (reverse_iterator(this->_vector));
			}

			const_reverse_iterator rend(void) const
			{
				return (const_reverse_iterator(this->_vector));
			}

			/* ===================================================================================================== */
			/*										Capacity member functions										 */
			/* ===================================================================================================== */

			size_type	size(void) const
			{
				return (this->_size);
			}

			size_type	max_size(void) const
			{
				return (this->_allocator.max_size());
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

			void reserve(size_type n) 
			{
											/*				differents cas				*/
					// - si n > la capacity la fonction realloue la taille demandée pour augmenter la capacity a n
					// - dans les autres cas on ne realloue pas et on supprime juste la quantitée d'elements apres n (vector::erase)
				if (n > this->max_size())
					throw std::length_error("vector::reserve");
				else if (n > this->_capacity)
				{
					pointer tmp = this->_allocator.allocate(n);
					if (this->_capacity > 0) 
					{
						for (size_type i = 0; i < this->_size; i++)
						{
							this->_allocator.construct(&tmp[i], this->_vector[i]);
							this->_allocator.destroy(&this->_vector[i]);
						}
						this->_allocator.deallocate(this->_vector, this->_capacity);
					}
					this->_capacity = n;
					this->_vector = tmp;
				}
			}
			
			void	resize(size_t n, value_type val = value_type())
			{
				if (n < this->_size)
				{
					for (size_type i = n; i < this->_size; i++)
					{
						this->_allocator.destroy(&this->_vector[i]);
					}
					this->_size = n;
				}
				else if (n > this->_size)
				{
						if (n > this->_size * 2)
							this->reserve(n);
						else 
							this->reserve (this->_size * 2);
						for (size_type i = this->_size; i < n; i++)
								this->_allocator.construct(&this->_vector[i], val);
						this->_size = n;
				}		
				std::cout << "value of size : " << _size << std::endl;		
			}
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
			reference		front(void) // return a reference to the first element in the vector
			{
				return (this->_vector[0]);
			}; 
			const_reference	front(void) const
			{
				return (this->_vector[0]);
			};
			reference		back(void) // return a reference to the last element in the vector
			{
				return (this->_vector[_size - 1]);
			}; 
			const_reference	back(void) const
			{
				return (this->_vector[_size - 1]);
			};
			/* ===================================================================================================== */
			
			/*												modifiers												*/

			template <class InputIterator>
  			void assign (InputIterator first, InputIterator last)
			{
				// TO DO
				(void)first;
				(void)last;
			}
			void assign (size_type n, const value_type& val) // Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
			{
				clear();
				reserve(n);
				(void)val;
				// insert(begin(), n, val); // BEGIN -> DO ITERATORS
				
			}

			void	clear(void)
			{
				for (size_type i = 0; i < _size; i++)
					this->_allocator.destroy(&this->_vector[i]);
				this->_size = 0;
			}
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
