/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_function.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:23:55 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/28 02:01:16 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_FUNCTION_HPP
# define BINARY_FUNCTION_HPP

namespace ft
{	
	template<class Arg1, class Arg2, class Result>
	struct binary_function
	{
		Arg1	first_argument_type;
		Arg2	second_argument_type;
		Result	result_type;
	};
}


#endif
