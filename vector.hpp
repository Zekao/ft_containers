/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 23:13:30 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/01 23:13:30 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <vector>
# include <memory>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> > // generic template
	class vector
	{
		public:
			typedef				Type													value_type;
			typedef				Allocator												allocator_type;
			typedef	typename 	allocator_type::reference								reference;
			typedef	typename 	allocator_type::const_reference							const_reference;	
			typedef	typename 	allocator_type::pointer									pointer;
			typedef	typename	allocator_type::const_pointer							const_pointer;
			typedef				ft::random_access_iterator<value_type>					iterator;
			typedef				ft::random_access_iterator<const value_type>			const_iterator;
			typedef				ft::reverse_iterator<value_type>						reverse_iterator;
			typedef				ft::reverse_iterator<const value_type>					const_reverse_iterator;
			typedef typename	Allocator::size_t										size_type;
			typedef typename	Allocator::ptrdiff_t									difference_type;
			// difference type
			// size_type
			/*									Capacity member functions											*/
			size_t	size(void) const
			{
				return (this->_size);
			}
			size_t	max_size(void) const
			{
				return (this->_size);
			}
			void	resize(size_t n, value_type val = value_type()) const;
			bool	empty(void) const
			{
				if (this->_size != 0)
					return (true);
				else
					return (false);
			}
			void	reserve (size_type n);
			/*											element access												*/
			reference operator[](size_type n)
			{
				return (this->_vector[n]);
			}
			const_reference operator[](size_type n) const
			{
				return (this->_vector[n]);
			}
			reference 		at(size_t n) // return a reference to the element n in the vector -> throw execption if n > size
			{
				if (n > this->_size)
					throw std::out_of_range("vector::at");
				return (this->_vector[n]);
			}
			const_reference at(size_type n) const; // return a reference to the element n in the vector
			{
				if (n > this->_size)
					throw std::out_of_range("vector::at");
				return (this->_vector[n]);
			}
			reference		front(); // return a reference to the first element in the vector
			const_reference	front();
			reference		back(); // return a reference to the last element in the vector
			const_reference	back();
			/*												modifiers												*/

		
		
			vector(/* args */);
			~vector();
		private:
		allocator_type	_allocator;
		pointer			_vector;
		size_type		_size;
		size_type		_capacity;
	};
}

#endif