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
			node->data = 0;
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
		/*					Comparaison				*/
		/*==========================================*/
		NodePtr min(NodePtr node)
		{
			while (node->leftChild != _null)
				node = node->leftChild;
			return (node);
		}
		
		NodePtr max(NodePtr node)
		{
			while (node->rightChild != _null)
				node = node->rightChild;
			return (node);
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
							leftRotate(k);
						}
					}
					k->parent->color = BLACK;
					k->parent->color = RED;
					rightRotate(k->parent->parent);
				}
			}
			
		}

		void	Transplant(NodePtr u, NodePtr v)
		{
			if (u->parent == _null)
				_root = v;
			else if (u == u->parent->leftChild)
				u->parent->leftChild = v;
			else
				u->parent->rightChild = v;
			v->parent = u->parent;
		}

		void	deleteNodeHelper(NodePtr node, int data)
		{
			NodePtr z = _null;
			NodePtr x;
			NodePtr y;
			while (node != _null)
			{
				if (node->data == data)
					z = node;

				if (node->data <= data)
					node = node->rightChild;
				else
					node = node->leftChild;
			}

			if (z == _null)
			{
				std::cout << "Key not found" << std::endl;
				return ;
			}

			y = z;
			int tmp = y->color;
			if (z->leftChild == _null)
			{
				x = z->rightChild;
				Transplant(z, z->rightChild);
			}
			else if (z->rightChild == _null)
			{
				x = z->leftChild;
				Transplant(z, z->leftChild);
			}
			else
			{
				y = min(z->rightChild);
				tmp = y->color;
				x = y->rightChild;
				if (y->parent == z)
					x->parent = y;
				else
				{
					Transplant(y, y->rightChild);
					y->rightChild = z->rightChild;
					y->rightChild->parent = y;
				}

				Transplant(z, y);
				y->leftChild = z->leftChild;
				y->leftChild->parent = y;
				y->color = z->color;
			}
			delete z;
			if (tmp == BLACK)
				deleteFix(x);
		}

		void	deleteNode(int data)
		{
			deleteNodeHelper(this->_root, data);
		}

		void	deleteFix(NodePtr x)
		{
			NodePtr	s;

			while (x != _root && x->color == BLACK)
			{
				if (x == x->parent->leftChild)
				{
					s = x->parent->rightChild;
					if (s->color == RED)
					{
						s->color = BLACK;
						x->parent->color = RED;
						leftRotate(x->parent);
						s = x->parent->rightChild;
					}

					if (s->leftChild->color == BLACK && s->rightChild->color == BLACK)
					{
						s->color = RED;
						x = x->parent;
					}
					else
					{
						if (s->rightChild->color == BLACK)
						{
							s->leftChild->color = BLACK;
							s->color = RED;
							rightRotate(s);
							s = x->parent->rightChild;
						}

						s->color = x->parent->color;
						x->parent->color = BLACK;
						s->rightChild->color = BLACK;
						leftRotate(x->parent);
						x = _root;
					}
				}

				else
				{
					s = x->parent->leftChild;
					if (s->color == RED)
					{
						s->color = BLACK;
						x->parent->color = RED;
						rightRotate(x->parent);
						s = x->parent->leftChild;
					}

					if (s->rightChild->color == BLACK && s->rightChild->color == BLACK)
					{
						s->color = RED;
						x = x->parent;
					}
					else
					{
						if (s->rightChild->color == BLACK)
						{
							s->leftChild->color = BLACK;
							s->color = RED;
							rightRotate(s);
							s = x->parent->rightChild;
						}

						s->color = x->parent->color;
						x->parent->color = BLACK;
						s->leftChild->color = BLACK;
						rightRotate(x->parent);
						x = _root;
					}
					// todo: else case + right rotate of the end
				}
			}
			x->color = BLACK;
		}

void printHelper(NodePtr root, std::string indent, bool last) {
	if (root != _null) {
	  std::cout << indent;
	  if (last) {
		std::cout << "R----";
		indent += "   ";
	  } else {
		std::cout << "L----";
		indent += "|  ";
	  }

	  std::string sColor = root->color ? "RED" : "BLACK";
	  std::cout << root->data << "(" << sColor << ")" << std::endl;
	  printHelper(root->leftChild, indent, false);
	  printHelper(root->rightChild, indent, true);
	}
  }
		void	insert(int	key)
		{
			NodePtr node = new Node;
			node->parent = NULL;
			node->data = key;
			node->rightChild = _null;
			node->leftChild = _null;
			node->color = RED;

			NodePtr x = this->_root;
			NodePtr y = NULL;
			while (x != _null)
			{
				y = x;
				if (node->data < x->data)
					x = x->leftChild;
				else
					x = x->rightChild;
			}
	
			node->parent = y;
			if (y == NULL)
				_root = node;
			else if (node->data < y->data)
				y->leftChild = node;
			else
				y->rightChild = node;
			if (node->parent == NULL)
			{
				node->color = BLACK;
				return ;
			}

			if (node->parent->parent == NULL)
				return ;
/*			if (y == NULL)
			{
				node->color = RED;
				return ;
			}
			if (node->parent->parent == NULL)
				return ;
*/			insertFix(node);
		}
		void printTree()
		{
			if (_root)
			{
				printHelper(this->_root, "", true);
			}
		}
};

int main()
{
  RedBlackTree bst;
  bst.insert(55);
  bst.insert(40);
  bst.insert(65);
  std::cout << "OK" << std::endl;
//   bst.insert(60);
//   bst.insert(75);
//   bst.insert(57);

  bst.printTree();
  std::cout << std::endl
	 << "After deleting" << std::endl;
  bst.deleteNode(40);
  bst.printTree();
}