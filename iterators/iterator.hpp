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
	template <class Iterator>
	struct iterator
	{
		typedef typename	Iterator::iterator_category			iterator_category;
		typedef typename	Iterator::value_type				value_type;
		typedef typename	Iterator::difference_type			difference_type;
		typedef typename	Iterator::pointer					pointer;
		typedef	typename	Iterator::reference					reference;
	};
}
#endif