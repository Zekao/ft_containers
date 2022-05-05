/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:06:19 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/05 00:01:09 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <stack>
# include <vector>

namespace ft
{
	
	template <class T, class Container = std::vector<T> >
	class stack
	{
		public:
			typedef				Container				container_type;
			typedef	typename	Container::size_type	size_type;
			typedef	typename	Container::value_type	value_type;
			
		/*						Constructors/Destructor					*/
		explicit stack (const container_type& container = container_type()) : _container(container){}
		stack(const stack & other)
		{
			_container = other._container;
		}
		~stack() {}
		/*						Member functions					*/
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
		/*						friend overloads (access to overloads of the given container)					*/
		template <class Tf, class Containerf>
		friend bool operator==(const stack<Tf, Containerf> &lhs, const stack<Tf, Containerf> &rhs);
		template <class Tf, class Containerf>
		friend bool operator!=(const stack<Tf, Containerf> &lhs, const stack<Tf, Containerf> &rhs);
		template <class Tf, class Containerf>
		friend bool operator<(const stack<Tf, Containerf> &lhs, const stack<Tf, Containerf> &rhs);
		template <class Tf, class Containerf>
		friend bool operator<=(const stack<Tf, Containerf> &lhs, const stack<Tf, Containerf> &rhs);
		template <class Tf, class Containerf>
		friend bool operator>(const stack<Tf, Containerf> &lhs, const stack<Tf, Containerf> &rhs);
		template <class Tf, class Containerf>
		friend bool operator>=(const stack<Tf, Containerf> &lhs, const stack<Tf, Containerf> &rhs);

		protected:
			container_type		_container;
			
	};
	
	/*						Non-member function overloads					*/
	template< class T, class Container >
	bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (lhs._container <= rhs._container);
	}
	
	template< class T, class Container >
	bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (lhs._container < rhs._container);
	}

	template< class T, class Container >
	bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (lhs._container == rhs._container);
	}

	template< class T, class Container >
	bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (lhs._container > rhs._container);
	}

	template< class T, class Container >
	bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (lhs._container >= rhs._container);
	}

	template< class T, class Container >
	bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (lhs._container != rhs._container);
	}
}

#endif