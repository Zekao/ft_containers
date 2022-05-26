/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:55:30 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/26 16:00:47 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LESS_HPP
# define LESS_HPP

template <class T>
struct less
{
    bool operator()( const T& lhs, const T& rhs ) const
    {
        return (lhs < rhs);
    }

};

#endif