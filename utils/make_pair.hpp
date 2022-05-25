/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 01:37:28 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/25 01:38:29 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_PAIR_HPP
# define MAKE_PAIR_HPP
# include "utils/pair.hpp"

namespace ft
{
    template< class T1, class T2 >
    ft::pair<T1,T2> make_pair( T1 t, T2 u );
}

#endif