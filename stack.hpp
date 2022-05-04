/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:06:19 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/04 18:29:07 by emaugale         ###   ########.fr       */
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
			typedef				Container				container_type;
			typedef	typename	Container::size_type	size_type;
			typedef	typename	Container::value_type	value_type;
			bool	empty(void) const
			{
				if (_container.size() != 0)
					return (false);
				return (true);
			}
			 // return true if stack is empty
			size_type	size(void) const
			{
				return (_container.size());
			}
			 // return the number of elements in the stack
			value_type &top(void)
			{
				return (_container.back());	
			}
			 // return a reference to the data at the first element of the stack
			const value_type &top(void) const
			{
				return (_container.back());
			} // return a const reference to the data at the first element of the stack
			void	push(const value_type & val)
			{
				_container.push_back(val);
			} // add a value to the stack
			void	pop()
			{
				_container.pop_back();
			}
			
		protected:
			container_type		_container;
			
	};
	/*						Operators Overload					*/
	template< class T, class Container >
	bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		if (lhs < rhs)
			return (true);
		return (false);
	}
	
	template< class T, class Container >
	bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		if (lhs !=rhs)
			return (true);
		return (false);
	}

	template< class T, class Container >
	bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		if (lhs < rhs)
			return (true);
		return (false);
	}

	template< class T, class Container >
	bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		if (lhs == rhs)
			return (true);
		return (false);
	}

	template< class T, class Container >
	bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		if (lhs > rhs)
			return (true);
		return (false);
	}

		template< class T, class Container >
	bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		if (lhs >= rhs)
			return (true);
		return (false);
	}

	/*						Operators Overload					*/
}

#endif