/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:06:19 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/01 04:58:47 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <stack>
# include <deque>

namespace ft
{
	
	template <class T, class Container = std::deque<T> >
	class stack
	{
		public:
			typedef		Container				container_type;
			typedef		Container::size_type	size_type;
			typedef		Container::value_type	value_type;
			stack(/* args */);
			bool	empty(void) const; // return true if stack is empty
			size_type	size(void) const; // return the number of elements in the stack
			value_type &top(void); // return a reference to the data at the first element of the stack
			const value_type &top(void) const; // return a const reference to the data at the first element of the stack
			void	push(const value_type & val); // add a value to the stack
			void	pop();
			
			~stack();
	};
	
}

#endif