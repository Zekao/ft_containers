/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:54:54 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/28 02:01:13 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft
{	
	template< class InputIt1, class InputIt2>
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2 )
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1)
				return (false);
			else if (*first1<*first2)
				return (true);
			++first1; ++first2;
		}
		return (first2!=last2);
	}

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1!=last1)
		{
			if (comp(*first1, *first2))
				return (false);
			else if (comp(*first2, *first1))
				return (true);
			++first1; ++first2;
		}
		return (first2!=last2);
	}
}
#endif 
