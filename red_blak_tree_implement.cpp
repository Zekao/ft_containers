/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_blak_tree_implement.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 04:03:27 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/13 04:03:27 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

# define BLACK 1
# define RED 2

struct Node
{
	int		data;
	Node	*leftChild;
	Node	*rightChild;
	Node	*parent;
	int		color;

};

typedef	Node	*NodePtr;

class RedBlackTree
{
	private:
		NodePtr	_root;
		NodePtr	_null;
		/*==========================================*/
		/*					Init Node				*/
		/*==========================================*/
		void	initNode(NodePtr node, NodePtr Parent)
		{
			node->data = NULL;
			node->parent = Parent;
			node->leftChild = NULL;
			node->rightChild = NULL;
			node->color = BLACK; 
		}

	public:
		/*==========================================*/
		/*					Constructor				*/
		/*==========================================*/
		RedBlackTree() 
		{
			_null = new Node;
			_null->color = 0;
			_null->leftChild = NULL;
			_null->rightChild = NULL;
			_root = _null;
		}
		/*==========================================*/
		/*					Rotations				*/
		/*==========================================*/
		void	leftRotate(NodePtr x)
		{
			/* Steps:
			1 - Init
			2 - If y has a left subtree, assign x as the parent of the left subtree of y
			3 - If the parent of x is NULL, make y as the root of the tree.
			4 - Else if x is the left child of p, make y as the left child of p.
			5 - Else assign y as the right child of p
			6 - Make y as the parent of x.
			*/
			NodePtr y = x->rightChild;
			x->rightChild = y->rightChild;
			if (y->leftChild != _null)
			{
				y->leftChild->parent = x;
			}
			y->parent = x->parent;
			if (x->parent == NULL)
			{
				this->_root = y;
			}
			else if (x == x->parent->leftChild)
			{
				x->parent->leftChild = y;
			}
			else
				x->parent->rightChild = y;
			y->leftChild = x;
			x->parent = y;
		}

		void	rightRotate(NodePtr x)
		{
			NodePtr y = x->leftChild;
			x->leftChild = y->leftChild;
			if (y->rightChild != _null)
			{
				y->rightChild->parent = x;
			}
			y->parent = x->parent;
			if (x->parent == NULL)
			{
				this->_root = y;
			}
			else if (x == x->parent->rightChild)
			{
				x->parent->rightChild = y;
			}
			else
				x->parent->leftChild = y;
			y->rightChild = x;
			x->parent = y;
		}

		void	insertFix(NodePtr k)
		{
			NodePtr	u;

			while (k->parent->color == RED)
			{
				if (k->parent == k->parent->parent->rightChild)
				{
					u = k->parent->leftChild;
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
							rightRotate(k);
						}
					}
					k->parent->color = BLACK;
					k->parent->parent->color = RED;
					leftRotate(k->parent->parent);
				}
				else
				{
					
				}
			}
			
		}
		void	insert(int	key)
		{
			NodePtr node = new Node;
			node->parent = NULL;
			node->data = key;
			node->rightChild = _null;
			node->leftChild = _null;

			NodePtr x = this->_root;
			NodePtr y = NULL;
			while (x != _null)
			{
				y = x;
				if (node->data < x->data)
				{
					x = x->leftChild;
				}
				else
					x = x->rightChild;
			}

			node->parent = y;
			if (y == NULL)
			{
				node->color = RED;
				return ;
			}
			if (node->parent->parent == NULL)
			{
				return ;
			}

			insertFix(node);
		}
	public:
		RedBlackTree(/* args */);
		~RedBlackTree();
};