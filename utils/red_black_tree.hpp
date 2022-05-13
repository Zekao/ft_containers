/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 02:06:10 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/13 03:50:05 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define REB_BLACK_TREE_HPP

# define RED 1
# define BLACK 0
class red_black_tree
{
	private:
		int	_color;
		int	_key;
		int	_leftChild;
		int	_rightChild;
		int	_parent;
		/* data */
	public:
		red_black_tree(/* args */);
		~red_black_tree();
};

#endif