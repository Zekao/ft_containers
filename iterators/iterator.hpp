/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 00:48:39 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/05 00:48:39 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator>
# include <cstddef>

namespace ft
{
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	class iterator
	{
		public:
			typedef Category				iterator_category;
			typedef T						value_type;
			typedef Distance				difference_type;
			typedef Pointer					pointer;
			typedef	Reference				reference;
			typedef	const Reference			const_reference;
	};
}
#endif
