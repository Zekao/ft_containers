/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 02:06:10 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/29 07:18:47 by emaugale         ###   ########.fr       */
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

// struct Node
// {
// 	int		data;
// 	Node	*leftChild;
// 	Node	*rightChild;
// 	Node	*parent;
// 	int		color;

// };

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
		typedef typename ft::bidirectional_iterator<ft::pair<Node, key_compare> >		iterator;
		typedef typename ft::bidirectional_iterator<const ft::pair<Node, key_compare> >	const_iterator;
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
				y = this->_minValue(deletedNode->right);
				y_original_color = y->color;
				x = y->right;
				if (x && y->parent == deletedNode)
					x->parent = y;
				else
				{
					this->_transplant(y, y->right);
					y->right = deletedNode->rightl;
					if (y->right)
						y->right->parent = y;
				}
				this->_transplant(deletedNode, y);
				y->left = deletedNode->left;
				if (y->left)
					y->left->parent = y;
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
		size_type	max_size(void)
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
			y->left = x;
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

		void	_insertFix(node_pointer k)
		{
			node_pointer	u;

			while (k->parent->color == RED)
			{
				if (k->parent == k->parent->parent->rightChild)
				{
					u = k->parent->parent->leftChild;
					if (u->color == RED)
					{
						u->color = BLACK;
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						k = k->parent->parent;
					}
					else
					{
						if (k == k->parent->leftChild)
						{
							k = k->parent;
							_rightRotate(k);
						}
					k->parent->color = BLACK;
					k->parent->parent->color = RED;
					_leftRotate(k->parent->parent);
					}
				}
				else
				{
					u = k->parent->parent->rightChild;
					if (u->color == RED)
					{
						u->color = BLACK;
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						k = k->parent->parent;
					}
					else
					{
						if (k == k->parent->rightChild)
						{
							k = k->parent;
							_leftRotate(k);
						}
					k->parent->color = BLACK;
					k->parent->parent->color = RED;
					_rightRotate(k->parent->parent);
					}
				}
				if (k == _root)
					break;
			}
			_root->color = BLACK;
		}

		void	_transplant(node_pointer u, node_pointer v)
		{
			if (!u->parent)
				_root = v;
			else if (u == u->parent->leftChild)
				u->parent->leftChild = v;
			else
				u->parent->rightChild = v;
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
						x = node->parent->rightRotate;
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
						if (!x->left || x->leftChild->color == BLACK)
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
		// void	deleteNodeHelper(node_pointer node, int data)
		// {
		// 	node_pointer z = _null;
		// 	node_pointer x;
		// 	node_pointer y;
		// 	while (node != _null)
		// 	{
		// 		if (node->data == data)
		// 			z = node;

		// 		if (node->data <= data)
		// 			node = node->rightChild;
		// 		else
		// 			node = node->leftChild;
		// 	}

		// 	if (z == _null)
		// 	{
		// 		std::cout << "Key not found" << std::endl;
		// 		return ;
		// 	}

		// 	y = z;
		// 	int tmp = y->color;
		// 	if (z->leftChild == _null)
		// 	{
		// 		x = z->rightChild;
		// 		Transplant(z, z->rightChild);
		// 	}
		// 	else if (z->rightChild == _null)
		// 	{
		// 		x = z->leftChild;
		// 		Transplant(z, z->leftChild);
		// 	}
		// 	else
		// 	{
		// 		y = min(z->rightChild);
		// 		tmp = y->color;
		// 		x = y->rightChild;
		// 		if (y->parent == z)
		// 			x->parent = y;
		// 		else
		// 		{
		// 			Transplant(y, y->rightChild);
		// 			y->rightChild = z->rightChild;
		// 			y->rightChild->parent = y;
		// 		}

		// 		Transplant(z, y);
		// 		y->leftChild = z->leftChild;
		// 		y->leftChild->parent = y;
		// 		y->color = z->color;
		// 	}
		// 	delete z;
		// 	if (tmp == BLACK)
		// 		deleteFix(x);
		// }

		// void	_deleteFix(int data)
		// {
		// 	deleteNodeHelper(this->_root, data);
		// }

// 		void	deleteFix(NodePtr x)
// 		{
// 			NodePtr	s;

// 			while (x != _root && x->color == BLACK)
// 			{
// 				if (x == x->parent->leftChild)
// 				{
// 					s = x->parent->rightChild;
// 					if (s->color == RED)
// 					{
// 						s->color = BLACK;
// 						x->parent->color = RED;
// 						leftRotate(x->parent);
// 						s = x->parent->rightChild;
// 					}

// 					if (s->leftChild->color == BLACK && s->rightChild->color == BLACK)
// 					{
// 						s->color = RED;
// 						x = x->parent;
// 					}
// 					else
// 					{
// 						if (s->rightChild->color == BLACK)
// 						{
// 							s->leftChild->color = BLACK;
// 							s->color = RED;
// 							rightRotate(s);
// 							s = x->parent->rightChild;
// 						}

// 						s->color = x->parent->color;
// 						x->parent->color = BLACK;
// 						s->rightChild->color = BLACK;
// 						leftRotate(x->parent);
// 						x = _root;
// 					}
// 				}

// 				else
// 				{
// 					s = x->parent->leftChild;
// 					if (s->color == RED)
// 					{
// 						s->color = BLACK;
// 						x->parent->color = RED;
// 						rightRotate(x->parent);
// 						s = x->parent->leftChild;
// 					}

// 					if (s->rightChild->color == BLACK && s->rightChild->color == BLACK)
// 					{
// 						s->color = RED;
// 						x = x->parent;
// 					}
// 					else
// 					{
// 						if (s->rightChild->color == BLACK)
// 						{
// 							s->leftChild->color = BLACK;
// 							s->color = RED;
// 							rightRotate(s);
// 							s = x->parent->rightChild;
// 						}

// 						s->color = x->parent->color;
// 						x->parent->color = BLACK;
// 						s->leftChild->color = BLACK;
// 						rightRotate(x->parent);
// 						x = _root;
// 					}
// 					// todo: else case + right rotate of the end
// 				}
// 			}
// 			x->color = BLACK;
// 		}

// void printHelper(NodePtr root, std::string indent, bool last) {
// 	if (root != _null) {
// 	  std::cout << indent;
// 	  if (last) {
// 		std::cout << "R----";
// 		indent += "   ";
// 	  } else {
// 		std::cout << "L----";
// 		indent += "|  ";
// 	  }

// 	  std::string sColor = root->color ? "RED" : "BLACK";
// 	  std::cout << root->data << "(" << sColor << ")" << std::endl;
// 	  printHelper(root->leftChild, indent, false);
// 	  printHelper(root->rightChild, indent, true);
// 	}
//   }
// 		void	insert(int	key)
// 		{
// 			NodePtr node = new Node;
// 			node->parent = NULL;
// 			node->data = key;
// 			node->rightChild = _null;
// 			node->leftChild = _null;
// 			node->color = RED;

// 			NodePtr x = this->_root;
// 			NodePtr y = NULL;
// 			while (x != _null)
// 			{
// 				y = x;
// 				if (node->data < x->data)
// 					x = x->leftChild;
// 				else
// 					x = x->rightChild;
// 			}
	
// 			node->parent = y;
// 			if (y == NULL)
// 				_root = node;
// 			else if (node->data < y->data)
// 				y->leftChild = node;
// 			else
// 				y->rightChild = node;
// 			if (node->parent == NULL)
// 			{
// 				node->color = BLACK;
// 				return ;
// 			}

// 			if (node->parent->parent == NULL)
// 				return ;
// 			insertFix(node);
// 		}
// 	void printTree()
// 	{
// 		if (_root)
// 		{
// 			printHelper(this->_root, "", true);
// 		}
// 	}
};

#endif
