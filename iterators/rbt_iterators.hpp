/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_iterators.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 00:24:41 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/30 07:28:04 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_ITERATORS_HPP
# define RBT_ITERATORS_HPP

#include "iterator.hpp"
#include "bidirectionnal_iterator.hpp"
#include "iterators_traits.hpp"
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft {

	template <typename T, class Compare>
	class MAP_const_iterator;
	template <typename T, class Compare>
	class MAP_iterator : ft::iterator<std::bidirectional_iterator_tag, T> 
	{
		public:
			typedef T *																						node_ptr;
			typedef typename T::value_type																	value_type;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::difference_type		difference_type;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::pointer				pointer;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::reference			reference;
			
			MAP_iterator(void) : _node(NULL), _parent(NULL) { }
			MAP_iterator(node_ptr node, node_ptr parent) : _node(node), _parent(parent) { }
			MAP_iterator(const MAP_iterator &it) : _node(it._node), _parent(it._parent) { }

			reference operator*(void) const
			{
				return(this->_node->value);
			}
			
			pointer operator->(void) const 
			{
				return(&(this->_node->value));
			}
			
			MAP_iterator &operator=(const MAP_iterator &it)
			{
				this->_node = it._node;
				this->_parent = it._parent;
				return (*this);
			}
			
			MAP_iterator &operator++(void)
			{
				if (this->_node)
				{
					this->_parent = this->_node;
					if (this->_node->rightChild)
					{
						this->_node = this->_node->rightChild;
						while (this->_node->leftChild)
							this->_node = this->_node->leftChild;
					}
					else
					{
						while (this->_node->parent and this->_node->parent->rightChild == this->_node)
							this->_node = this->_node->parent;
						this->_node = this->_node->parent;
					}
				}
				return (*this);
			}
			
			MAP_iterator operator++(int)
			{
				MAP_iterator tmp = *this;
				operator++();
				return (tmp);
			}
			
			MAP_iterator &operator--(void)
			{	
				if (this->_node)
				{
					this->_parent = this->_node;
					if (this->_node->leftChild)
					{
						this->_node = this->_node->leftChild;
						while (this->_node->rightChild)
							this->_node = this->_node->rightChild;
					}
					else
					{
						while (this->_node->parent and this->_node->parent->leftChild == this->_node)
							this->_node = this->_node->parent;
						this->_node = this->_node->parent;
					}
				}
				else
					this->_node = this->_parent;
				return (*this);
			}
			
			MAP_iterator operator--(int)
			{
				MAP_iterator tmp = *this;
				operator--();
				return (tmp);
			}
			
			bool operator==(const MAP_iterator &it) const
			{
				return(this->_node == it._node);
			}
			
			bool operator!=(const MAP_iterator &it) const
			{
				return(this->_node != it._node);
			}

			node_ptr	getNode(void) const 
			{
				return(this->_node);
			}
			
			node_ptr	getParent(void) const
			{
				return(this->_parent);
			}

		
		private:
			node_ptr	_node;
			node_ptr	_parent;
	};

	template <typename T, class Compare>
	class MAP_const_iterator : ft::iterator<std::bidirectional_iterator_tag, T>
	{
		public:
			typedef T *																						node_ptr;
			typedef typename T::value_type const															value_type;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::difference_type		difference_type;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::pointer				pointer;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::reference			reference;
			
			MAP_const_iterator(void) : _node(NULL), _parent(NULL) {}
			MAP_const_iterator(node_ptr node, node_ptr parent) : _node(node), _parent(parent) {}
			MAP_const_iterator(const MAP_const_iterator &it) : _node(it._node), _parent(it._parent) {}
			MAP_const_iterator(const MAP_iterator<T, Compare> &it) : _node(it.getNode()), _parent(it.getParent()) {}

			reference operator*(void) const 
			{
				return (this->_node->value);
			}
			
			pointer operator->(void) const
			{
				return (&(this->_node->value));
			}

			MAP_const_iterator &operator=(const MAP_const_iterator &it)
			{
				this->_node = it._node;
				this->_parent = it._parent;
				return (*this);
			}
			
			MAP_const_iterator &operator++(void)
			{
				if (this->_node)
				{
					this->_parent = this->_node;
					if (this->_node->rightChild) 
					{
						this->_node = this->_node->rightChild;
						while (this->_node->leftChild)
							this->_node = this->_node->leftChild;
					}
					else 
					{
						while (this->_node->parent and this->_node->parent->rightChild == this->_node)
							this->_node = this->_node->parent;
						this->_node = this->_node->parent;
					}
				}
				return (*this);
			}
			
			MAP_const_iterator operator++(int)
			{
				MAP_const_iterator tmp = *this;
				operator++();
				return (tmp);
			}
			
			MAP_const_iterator &operator--(void)
			{
				if (this->_node)
				{
					this->_parent = this->_node;
					if (this->_node->leftChild)
					{
						this->_node = this->_node->leftChild;
						while (this->_node->rightChild)
							this->_node = this->_node->rightChild;
					} 
					else 
					{
						while (this->_node->parent and this->_node->parent->leftChild == this->_node)
							this->_node = this->_node->parent;
						this->_node = this->_node->parent;
					}
				}
				else
					this->_node = this->_parent;
				return (*this);
			}
			
			MAP_const_iterator operator--(int)
			{
				MAP_const_iterator tmp = *this;
				operator--();
				return (tmp);
			}
			
			bool operator==(const MAP_const_iterator &it) const 
			{
				return(this->_node == it._node);
			}
	
			bool operator!=(const MAP_const_iterator &it) const 
			{
				return(this->_node != it._node);
			}

			node_ptr	getNode(void) const 
			{
				return(this->_node);
			}
			
			node_ptr	getParent(void) const 
			{
				return(this->_parent);
			}

		
		private:
			node_ptr	_node;
			node_ptr	_parent;
	};
}
#endif
