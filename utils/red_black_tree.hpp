/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 02:06:10 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/30 06:18:44 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE
# define RED_BLACK_TREE
# include <iostream>
# define BLACK 0
# define RED 1
# include "node.hpp"
# include "make_pair.hpp"
# include "type_traits.hpp"
#include "../iterators/iterator.hpp"
#include "../iterators/bidirectionnal_iterator.hpp"
#include "../iterators/iterators_traits.hpp"
#include "../iterators/random_access_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../iterators/rbt_iterators.hpp"

namespace ft
{
	template <class Type, class Compare, class Node = Node<Type>, class Type_Alloc = std::allocator<Type>, class Node_Alloc = std::allocator<Node> >
	class RedBlackTree
	{
		public:
			typedef	Type																	value_type;
			typedef typename value_type::first_type											key_type;
			typedef typename value_type::second_type										mapped_type;
			typedef	Compare																	key_compare;
			typedef Type_Alloc																type_allocator;
			typedef typename type_allocator::size_type										size_type;
			typedef Node_Alloc																node_allocator;
			typedef typename ft::MAP_iterator<Node, key_compare>							iterator;
			typedef typename ft::MAP_const_iterator<Node, key_compare>							const_iterator;
			typedef typename Node::node_pointer												node_pointer;
			typedef typename Node::const_node_pointer										const_node_pointer;
			typedef typename Node::node_reference											node_reference;
			typedef typename Node::const_node_reference										const_node_reference;
		private:
			node_pointer	_root;
			key_compare		_cmp;
			node_allocator	_allocator;
		public:		
			/* ==================================================================================================== */
			/*											Constructors / Destructor									*/
			/* ==================================================================================================== */
			RedBlackTree(void) : _root(NULL), _cmp(key_compare()), _allocator(node_allocator()) {}
			explicit RedBlackTree(const key_compare &cmp) : _root(NULL), _allocator(node_allocator())
			{
				this->_cmp = cmp;
			}
			RedBlackTree(const RedBlackTree &src)
			{
				this->_root = src._root;
				this->_cmp = src._cmp;
				this->_allocator = src._allocator;
			}
			~RedBlackTree(void)
			{
				this->_clear(this->_root);
			}
			/* ==================================================================================================== */
			/*													Operators											*/
			/* ==================================================================================================== */
			RedBlackTree &operator=(RedBlackTree const &rhs)
			{
				if (this != rhs)
					this->_root = rhs._root;
				return (*this);
			}
			node_reference operator*(void) const 
			{
				return (this->_root);
			}
			node_pointer operator->(void) const
			{
				return (&this->_root);
			}
			/* ==================================================================================================== */
			/*											Public member functions										*/
			/* ==================================================================================================== */
			ft::pair<iterator, bool> insert(const value_type &value)
			{
				if (!this->_root)
				{
					this->_root = this->_allocator.allocate(1);
					this->_allocator.construct(this->_root, Node(value));
					this->_root->color = BLACK;
					return (ft::make_pair<iterator, bool>(iterator(this->_root, NULL), true));
				}
				node_pointer	x = this->_root;
				node_pointer	parent = NULL;
				while (x)
				{
					parent = x;
					if (this->_cmp(x->value.first, value.first))
						x = x->rightChild;
					else if (this->_cmp(value.first, x->value.first))
						x = x->leftChild;
					else
						return (ft::make_pair<iterator, bool>(iterator(x, NULL), false));
				}
				x = this->_allocator.allocate(1);
				this->_allocator.construct(x, Node(value));
				x->parent = parent;
				if (this->_cmp(parent->value.first, x->value.first))
					parent->rightChild = x;
				else
					parent->leftChild = x;
				this->_insertFix(x);
				return (ft::make_pair<iterator, bool>(iterator(x, NULL), true));
			}

			ft::pair<iterator, bool> erase(const key_type& value)
			{
				node_pointer	deletedNode = this->_root;
				node_pointer	x;	
				while (deletedNode && deletedNode->value.first != value)
				{
					if (this->_cmp(value, deletedNode->value.first))
						deletedNode = deletedNode->leftChild;
					else if (this->_cmp(deletedNode->value.first, value))
						deletedNode = deletedNode->rightChild;
				}
				if (!deletedNode)
					return (ft::make_pair<iterator, bool>(this->end(), false));
				node_pointer	y = deletedNode;
				int				y_original_color = y->color;
				if (deletedNode->leftChild == NULL)
				{
					x = deletedNode->rightChild;
					this->_transplant(deletedNode, deletedNode->rightChild);
				}
				else if (deletedNode->rightChild == NULL)
				{
					x = deletedNode->leftChild;
					this->_transplant(deletedNode, deletedNode->leftChild);
				}
				else
				{
					y = this->_minValue(deletedNode->rightChild);
					y_original_color = y->color;
					x = y->rightChild;
					if (x && y->parent == deletedNode)
						x->parent = y;
					else
					{
						this->_transplant(y, y->rightChild);
						y->rightChild = deletedNode->rightChild;
						if (y->rightChild)
							y->rightChild->parent = y;
					}
					this->_transplant(deletedNode, y);
					y->leftChild = deletedNode->leftChild;
					if (y->leftChild)
						y->leftChild->parent = y;
					y->color = deletedNode->color;
				}
				this->_allocator.destroy(deletedNode);
				this->_allocator.deallocate(deletedNode, 1);
				if (y_original_color == BLACK)
					this->_deleteFix(x);
				return (ft::make_pair<iterator, bool> (this->end(), true));
			}
			
			iterator	upper_bound(const key_type & key)
			{
				iterator it = begin();
				iterator ite = end();
				while (it != ite)
				{
					if (this->_cmp(key, it->first))
						return (it);
					it++;
				}
				return (it);
			}
			
			const_iterator	upper_bound(const key_type & key) const
			{
				const_iterator it = begin();
				const_iterator ite = end();
				while (it != ite)
				{
					if (this->_cmp(key, it->first))
						return (it);
					it++;
				}
				return (it);
			}

			iterator	lower_bound(const key_type & key)
			{
				iterator it = begin();
				iterator ite = end();
				while (it != ite)
				{
					if (!(this->_cmp(it->first, key)))
						break;
					it++;
				}
				return (it);
			}
			
			const_iterator	lower_bound(const key_type & key) const
			{
				const_iterator it = begin();
				const_iterator ite = end();
				while (it != ite)
				{
					if (!(this->_cmp(it->first, key)))
						break;
					it++;
				}
				return (it);
			}
			
			iterator	find (const key_type & k)
			{
				return (this->_find(k, this->_root));
			}

			const_iterator	find (const key_type & k) const
			{
				return (this->_cfind(k, this->_root));
			}
			
			void	swap(RedBlackTree &rhs)
			{
				ft::swap(this->_root, rhs._root);
				ft::swap(this->_allocator, rhs._allocator);
				ft::swap(this->_cmp, rhs._cmp);
			}

			node_pointer minValue(void) const
			{
				return (this->_minValue(this->_root));
			}

			node_pointer	maxValue(void) const
			{
				return (this->_maxValue(this->_root));
			}

			void	clear(void)
			{
				this->_root = this->_clear(this->_root);
			}
			size_type	max_size(void) const
			{
				return (this->_allocator.max_size());	
			}

			iterator begin(void)
			{
				return (iterator(minValue(), NULL));
			}

			const_iterator begin(void) const
			{
				return (const_iterator(minValue(), NULL));
			}

			iterator end(void)
			{
				return (iterator(NULL, maxValue()));
			}

			const_iterator end(void) const
			{
				return (const_iterator(NULL, maxValue()));
			}
			
			/* ==================================================================================================== */
			/*											Private member functions									*/
			/* ==================================================================================================== */

			iterator		_find(const key_type &to_find, node_pointer node)
			{
				if (!node)
					return (this->end());
				if (this->_cmp(to_find, node->value.first))
					return (this->_find(to_find, node->leftChild));
				if (this->_cmp(node->value.first, to_find))
					return (this->_find(to_find, node->rightChild));
				return (iterator(node, node->parent));
			}
			const_iterator		_cfind(const key_type &to_find, node_pointer node) const
			{
				if (!node)
					return (this->end());
				if (this->_cmp(to_find, node->value.first))
					return (this->_cfind(to_find, node->leftChild));
				if (this->_cmp(node->value.first, to_find))
					return (this->_cfind(to_find, node->rightChild));
				return (iterator(node, node->parent));
			}

			node_pointer	_minValue(node_pointer node) const
			{
				if (!node)
					return (NULL);
				if (node->leftChild)
					return (this->_minValue(node->leftChild));
				return (node);
			}
			
			node_pointer	_maxValue(node_pointer node) const
			{
				if (!node)
					return (NULL);
				if (node->rightChild)
					return (this->_maxValue(node->rightChild));
				return (node);
			}
			
			node_pointer	_clear(node_pointer node)
			{
				if (!node)
					return (NULL);
				if (node->leftChild)
					this->_clear(node->leftChild);
				if (node->rightChild)
					this->_clear(node->rightChild);
				this->_allocator.destroy(node);
				this->_allocator.deallocate(node, 1);
				return (NULL);
			}
			
			void			_leftRotate(node_pointer x)
			{
				/* Steps:
				1 - Init
				2 - If y has a left subtree, assign x as the parent of the left subtree of y
				3 - If the parent of x is NULeL, make y as the root of the tree.
				4 - Else if x is the left child of p, make y as the left child of p.
				5 - Else assign y as the right child of p
				6 - Make y as the parent of x.
				*/
				node_pointer	y = x->rightChild;
				x->rightChild = y->leftChild;			
				if (y->leftChild)
					y->leftChild->parent = x;
				y->parent = x->parent;
				if (!x->parent)
					this->_root = y;
				else if (x == x->parent->leftChild)
					x->parent->leftChild = y;
				else
					x->parent->rightChild = y;
				y->leftChild = x;
				x->parent = y;
			}
			void	_rightRotate(node_pointer x)
			{
				node_pointer y = x->leftChild;
				x->leftChild = y->rightChild;
				if (y->rightChild)
					y->rightChild->parent = x;
				y->parent = x->parent;
				if (!x->parent)
					this->_root = y;
				else if (x == x->parent->rightChild)
					x->parent->rightChild = y;
				else
					x->parent->leftChild = y;
				y->rightChild = x;
				x->parent = y;
			}

			void			_insertFix(node_pointer node)
			{
				while (node->parent and node->parent->color == RED)
				{
					if (node->parent->parent->leftChild == node->parent)
					{	
						if (node->parent->parent->rightChild and node->parent->parent->rightChild->color == RED)
						{
							node->parent->parent->leftChild->color = node->parent->parent->rightChild->color = BLACK;
							node->parent->parent->color = RED;
							node = node->parent->parent;
						}
						else
						{
							if (node == node->parent->rightChild)
							{
								node = node->parent;
								this->_leftRotate(node);
							}
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						this->_rightRotate(node->parent->parent);
						}
						}
						else
						{
							if (node->parent->parent->leftChild and node->parent->parent->leftChild->color == RED)
							{
								node->parent->parent->leftChild->color = node->parent->parent->rightChild->color = BLACK;
								node->parent->parent->color = RED;
								node = node->parent->parent;
							}
						else
						{
							if (node == node->parent->leftChild)
							{
								node = node->parent;
								this->_rightRotate(node);
							}
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						this->_leftRotate(node->parent->parent);
						}
					}
				}
				this->_root->color = BLACK;
				return;
			}

			void	_transplant(node_pointer u, node_pointer v)
			{
				if (!u->parent)
					_root = v;
				else if (u == u->parent->leftChild)
					u->parent->leftChild = v;
				else
					u->parent->rightChild = v;
				if (v)
					v->parent = u->parent;
			}

			void	_deleteFix(node_pointer node)
			{
				node_pointer x;
				
				while (node && node != this->_root && node->color == BLACK)
				{
					if (node->parent->leftChild == node)
					{
						x = node->parent->rightChild;
						if (x->color == RED)
						{
							x->color = BLACK;
							node->parent->color = RED;
							this->_leftRotate(node->parent);
							x = node->parent->rightChild;
						}
						if ((!x->leftChild || x->leftChild->color == BLACK ) && (!x->rightChild || x->rightChild->color == BLACK))
						{
							x->color = RED;
							node = node->parent;
						}
						else
						{
							if (!x->rightChild || x->rightChild->color == BLACK)
							{
								x->leftChild->color = BLACK;
								x->color = RED;
								this->_rightRotate(x);
								x = node->parent->rightChild;
							}
							x->color = node->parent->color;
							node->parent->parent->color = BLACK;
							if (x->rightChild)
								x->rightChild->color = BLACK;
							this->_leftRotate(node->parent);
							node = this->_root;
						}
					}
					else
					{
						x = node->parent->rightChild;
						if (x->color == RED)
						{
							x->color = BLACK;
							node->parent->color = RED;
							this->_rightRotate(node->parent);
							x = node->parent->leftChild;
						}
						if ((!x->leftChild || x->leftChild->color == BLACK) && (!x->rightChild || x->rightChild->color == BLACK))
						{
							x->color = RED;
							x = x->parent;
						}
						else
						{
							if (!x->leftChild || x->leftChild->color == BLACK)
							{
								x->rightChild->color = BLACK;
								x->color = RED;
								this->_leftRotate(x);
								x = node->parent->leftChild;
							}
							x->color = node->parent->color;
							if (node->parent->parent)
								node->parent->parent->color = BLACK;
							if (x->leftChild)
								x->leftChild->color = BLACK;
							this->_rightRotate(node->parent);
							node = this->_root;
						}
					}
				}
				if (node)
					node->color = BLACK;
			}
	};
}

#endif
