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

			//				Do all expresions of RandomAccessIterator

			/* ===================================================================================================== */
		private:
			pointer	_p;
	};
}

#endif