/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:32:27 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/30 05:56:53 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		public:
		// types
		typedef T1 first_type;
		typedef T2 second_type;
		first_type first;
		second_type second;

		// construtors
		pair () : first(first_type()), second(second_type()) {}
		pair (const first_type &a, const second_type &b) : first(a), second(b) {}
		template <class U1, class U2>
		pair (const pair<U1, U2> & src) : first(src.first), second(src.second) {}

		pair & operator=(const pair & rhs)
		{
			if (this == &rhs)
				return (*this);
			this->first = rhs.first;
			this->second = rhs.second;
			return (*this);
		}
	
	};
	template <class T1, class T2>
	bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first==rhs.first and lhs.second==rhs.second);
	}
	template <class T1, class T2>
	bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) 
	{
		return (!(lhs==rhs));
	
	}
	template <class T1, class T2>
	bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) 
	{
		return (lhs.first<rhs.first or (!(rhs.first<lhs.first) and lhs.second<rhs.second));
	}
	template <class T1, class T2>
	bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) 
	{
		return (!(rhs<lhs));
	}
	template <class T1, class T2>
	bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) 
	{
		return (rhs<lhs);
	}
	template <class T1, class T2>
	bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) 
	{
		return (!(lhs<rhs));
	}
		
}

#endif
