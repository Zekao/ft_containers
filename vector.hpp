/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 23:13:30 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/30 10:07:32 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept>
# include <iostream>
# include "iterators/iterators_traits.hpp"
# include "iterators/random_access_iterator.hpp"
# include "iterators/reverse_iterator.hpp"
# include "utils/type_traits.hpp"
# include "utils/lexicographical_compare.hpp"
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
				this->_vector = NULL;
				this->_allocator = alloc;
			} // default constructor 
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{
				this->_allocator = alloc;
				this->_size = n;
				this->_capacity = n;
				this->_vector = NULL;
				if (this->_capacity)
					this->_vector = this->_allocator.allocate(n);
				for (size_type i = 0; i < n; i++) this->_allocator.construct(&this->_vector[i], val);

			}; // fill constructor
			template <class InputIterator>
         	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				this->_allocator = alloc;
				this->_size = 0;
				this->_capacity = ft::distance(first, last);
				if (this->_capacity)
					this->_vector = this->_allocator.allocate(this->_capacity);
				for (; first != last; first++) 
					this->_allocator.construct(&this->_vector[this->_size++], *first);
			}
			vector (const vector& x)
			{
				this->_allocator = x._allocator;
				this->_capacity = x._size;
				this->_size = x._size;
				this->_vector = x._vector;
				if (this->_capacity)
					this->_vector = this->_allocator.allocate(this->_capacity);
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.construct(&this->_vector[i], x._vector[i]);

			}
			~vector()
			{
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.destroy(&this->_vector[i]);
				if (this->_vector != NULL)
					this->_allocator.deallocate(this->_vector, this->_capacity);

			};
			
			vector& operator=(const vector& x)
			{
				if (x == *this)
					return *this;
				this->clear();
				this->insert(begin(), x.begin(), x.end());
				return (*this);
			};

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
			}
			/* ===================================================================================================== */
			/*											element access												 */
			/* ===================================================================================================== */
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
			/*													modifiers										 	 */
			/* ===================================================================================================== */

			template <class InputIterator>
  			void assign (typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type first, InputIterator last)
			{
				this->clear();
				this->reserve (ft::distance(first, last));
				this->insert (begin(), first, last);
			}
			void assign (size_type n, const value_type& val) // Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
			{
				clear();
				reserve(n);
				insert(begin(), n, val); // BEGIN -> DO ITERATORS
				
			}

			void	clear(void)
			{
				if (this->_vector)
					for (size_type i = 0; i < _size; i++)
						this->_allocator.destroy(&this->_vector[i]);
				this->_size = 0;
			}

			void push_back (const value_type& val) 
			{
				if (this->_capacity > 0 and this->_size == this->_capacity)
				{
					pointer new_vector = this->_allocator.allocate(this->_capacity * 2);
					for (size_type i = 0; i < this->_size; i++)
					{
						this->_allocator.construct(&new_vector[i], this->_vector[i]);
						this->_allocator.destroy(&this->_vector[i]);
					}
					this->_allocator.deallocate(this->_vector, this->_capacity);
					this->_capacity *= 2;
					this->_vector = new_vector;
				}
				else if (this->_capacity == 0)
				{
					this->_capacity = 1;
					this->_vector = this->_allocator.allocate(this->_capacity);
				}
				this->_allocator.construct(&this->_vector[this->_size], val);
				this->_size++;
			}
			
			void	pop_back()
			{
				if (this->_size > 0)
				{
					this->_allocator.destroy(&this->_vector[this->_size - 1]);
					this->_size--;
				}
			}
			
			iterator insert(iterator position, const value_type &val)
			{
				difference_type pos = position - this->_vector;
				
				reserve(this->_size + 1);
				for (difference_type i = this->_size; i > pos; i--)
				{
					this->_allocator.construct(&this->_vector[i], this->_vector[i - 1]);
					this->_allocator.destroy(&this->_vector[i - 1]);
				}
				this->_allocator.construct(&this->_vector[pos], val);
				this->_size++;
				return (&this->_vector[pos]);
			} 
			

			void insert (iterator position, size_type n, const value_type& val)			
			{
				if (!n)
					return ;
				difference_type pos = position - this->_vector ;

				if (n + this->_size > this->_capacity)
				{
					if (this->_size + n > this->_size * 2)
						reserve(this->_size + n);
					else
						reserve(this->_size * 2);
				}
				for (difference_type i = this->_size; i > pos; i--)
				{
					this->_allocator.construct(&this->_vector[i + n - 1], this->_vector[i - 1]);
					this->_allocator.destroy(&this->_vector[i - 1]);
				}
				for (size_type i = 0; i < n; i++)
				{
					this->_allocator.construct(&this->_vector[pos + i], val);
				}
				this->_size += n;
				
			} 
			
			template<class InputIterator>
			void	insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				difference_type pos = position - this->_vector;
				size_type n = ft::distance(first, last);

				if (n + this->_size > this->_capacity)
				{
					if (this->_size + n > this->_size * 2)
						reserve(this->_size + n);
					else
						reserve(this->_size * 2);
				}
				for (difference_type i = this->_size; i > pos; i--)
				{
					this->_allocator.construct(&this->_vector[i + n - 1], this->_vector[i - 1]);
					this->_allocator.destroy(&this->_vector[i - 1]);
				}
				for (size_type i = 0; first != last; first++, i++)
				{
					this->_allocator.construct(&this->_vector[pos + i], *first);
				}
				this->_size += n;
			}

			iterator erase(iterator position)
			{
				for (size_type i = position - this->_vector; i < this->_size - 1; i++) 
				{
					this->_allocator.destroy(&this->_vector[i]);
					this->_allocator.construct(&this->_vector[i], this->_vector[i + 1]);
				}
				this->_allocator.destroy(&this->_vector[this->_size - 1]);
				this->_size--;
				return (position);
			}

			iterator erase(iterator first, iterator last)
			{
				size_type	pos = ft::distance(first, last);
				for (size_type i = first - this->_vector; i < this->_size - pos; i++)
				{
					this->_allocator.destroy(&this->_vector[i]);
					this->_allocator.construct(&this->_vector[i], this->_vector[i + pos]);
				}
				for (size_type i = this->_size - pos; i < this->_size; i++)
					this->_allocator.destroy(&this->_vector[i]);
				this->_size -= pos;
				return  (first);
			}

			void swap (vector& x) {
				ft::swap(_vector, x._vector);
				ft::swap(_size, x._size);
				ft::swap(_capacity, x._capacity);
			};
			/* ===================================================================================================== */
			/*													allocator										 	 */
			/* ===================================================================================================== */
		
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
	/* ===================================================================================================== */
	/*												operators overload										 */
	/* ===================================================================================================== */
	
template< class T, class Alloc >
bool operator==( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	if (lhs.size() != rhs.size())
		return (false);
	for (size_t i = 0; i < lhs.size(); i++)
	{
		if (lhs[i] != rhs[i])
			return (false);
	}
		return (true);
}

template< class T, class Alloc >
bool operator!=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	return (!(lhs == rhs));
}

template< class T, class Alloc >
bool operator<( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
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
	return (!(lhs < rhs));
}

template <class T, class Alloc>
void swap(vector<T, Alloc>& x, vector<T, Alloc>& y) 
{
	x.swap(y);
}

}


#endif
