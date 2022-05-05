/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 00:25:15 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/05 00:25:15 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_TRAITS_HPP
# define ITERATORS_TRAITS_HPP

# include <iterator>
# include <cstddef>

namespace ft
{
	template <class Iterator>
	struct iterator_traits
	{
		typedef typename	Iterator::difference_type			difference_type;
		typedef typename	Iterator::value_type				value_type;
		typedef typename	Iterator::pointer					pointer;
		typedef	typename	Iterator::reference					reference;
		typedef typename	Iterator::iterator_category			iterator_category;
	};

	template <class T>
	struct iterator_traits<T*>
	{
		typedef typename	ptrdiff_t							difference_type;
		typedef typename	T									value_type;
		typedef typename	T*									pointer;
		typedef	typename	T&									reference;
		typedef typename	std::random_access_iterator_tag		iterator_category;
	};

	template <class T>
	struct iterator_traits<const T*>
	{
		typedef typename	ptrdiff_t							difference_type;
		typedef typename	T									value_type;
		typedef typename	const T*							pointer;
		typedef	typename	const T&									reference;
		typedef typename	std::random_access_iterator_tag		iterator_category;
	};

}
#endif