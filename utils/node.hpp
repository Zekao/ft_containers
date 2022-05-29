/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 04:07:14 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/29 04:07:14 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

template	<class Type>
class	Node
{
	public:
		typedef	Type			value_type;
		typedef	Node*			node_pointer;
		typedef	const Node*		const_node_pointer;
		typedef	Node&			node_reference;
		typedef const Node&		const_node_reference;
		value_type				value;
		node_pointer			parent;
		node_pointer			leftChild;
		node_pointer			rightChild;
		int						color;

	Node() : value(), parent(NULL), leftChild(NULL), rightChild(NULL), color(RED)
	{
		return ;
	}
	Node(const value_type val, node_pointer parent = NULL, node_pointer leftChild = NULL, node_pointer rightChild = NULL)
	{
		this->value = val;
		this->parent = parent;
		this->leftChild = leftChild;
		this->rightChild = rightChild;
		this->color = RED;
	}
	Node(const_node_reference src)
	{
		this->value = src.value;
		this->parent = src.parent;
		this->leftChild = src.leftChild;
		this->rightChild = src.rightChild;
		this->color = src.color;
	}
	bool operator==(const_node_reference rhs)
	{
		return (this->value == rhs.value);
	}
};

#endif
