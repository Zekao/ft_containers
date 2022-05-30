/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 05:05:47 by emaugale          #+#    #+#             */
/*   Updated: 2022/05/31 00:36:00 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include "vector.hpp"
#include <stack>
#include <vector>
#include <iostream>

int	main(void)
{
	ft::stack<int> yo;
	std::cout << "=============\t\tft::stack\t=============" << std::endl;
	std::cout << "is it empty ? " << (yo.empty() == 1 ? "yes." : "no.") << std::endl;
	std::cout << "size of my stack before adding 3 values : " << yo.size() << std::endl;
	yo.push(42);
	yo.push(666);
	yo.push(21);
	std::cout << yo.size() << std::endl;
	std::cout << "trying to show all values of present on my stack " << std::endl;
    for (ft::stack<int> dump = yo; !dump.empty(); dump.pop())
		std::cout << dump.top() << std::endl;
	std::cout << "is it empty ? " << (yo.empty() == 1 ? "yes." : "no.") << std::endl;
	std::cout << "\t\ttesting operators" << std::endl;
	
	ft::stack<int> yo2;
	yo2.push(84);
	yo2.push(1337);
	yo2.push(2727);

	std::cout << "================================" << std::endl;
	std::cout << "operator : " << "<=" << std::endl;
	if (yo <= yo2)
		std::cout << "stack1 is <= than stack2" << std::endl;
	else
		std::cout << "stack1 is not <= than stack2" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "operator : " << "<" << std::endl;
	if (yo < yo2)
		std::cout << "stack1 is < than stack2" << std::endl;
	else
		std::cout << "stack1 is not < than stack2" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "operator : " << "==" << std::endl;
	if (yo == yo2)
		std::cout << "both stacks are equal" << std::endl;
	else
		std::cout << "both stacks are not equal" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "operator : " << ">" << std::endl;
	if (yo > yo2)
		std::cout << "stack1 is > than stack2" << std::endl;
	else
		std::cout << "stack1 is not > than stack2" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "operator : " << ">=" << std::endl;
	if (yo >= yo2)
		std::cout << "stack1 is >= than stack2" << std::endl;
	else
		std::cout << "stack 1 is not >= than stack2" << std::endl;

	std::cout << "================================" << std::endl;
	std::cout << "operator : " << "!=" << std::endl;
	if (yo != yo2)
		std::cout << "both stacks are differents" << std::endl;
	else
		std::cout << "both stacks are equal" << std::endl;
	std::cout << "================================" << std::endl;

	std::cout << "\tNow testing with real STD::STACK" << std::endl;

	std::stack<int> lo;
	std::cout << "=============\t\tstd::stack\t=============" << std::endl;
	std::cout << "is it empty ? " << (lo.empty() == 1 ? "yes." : "no.") << std::endl;
	std::cout << "size of my stack before adding 3 values : " << lo.size() << std::endl;
	lo.push(42);
	lo.push(666);
	lo.push(21);
	std::cout << lo.size() << std::endl;
	std::cout << "trying to show all values of present on my stack " << std::endl;
    for (std::stack<int> dump = lo; !dump.empty(); dump.pop())
		std::cout << dump.top() << std::endl;
	std::cout << "is it empty ? " << (lo.empty() == 1 ? "yes." : "no.") << std::endl;
	std::cout << "\t\ttesting operators" << std::endl;
	
	std::stack<int> lo2;
	lo2.push(84);
	lo2.push(1337);
	lo2.push(2727);

	std::cout << "================================" << std::endl;
	std::cout << "operator : " << "<=" << std::endl;
	if (lo <= lo2)
		std::cout << "stack1 is <= than stack2" << std::endl;
	else
		std::cout << "stack1 is not <= than stack2" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "operator : " << "<" << std::endl;
	if (lo < lo2)
		std::cout << "stack1 is < than stack2" << std::endl;
	else
		std::cout << "stack1 is not < than stack2" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "operator : " << "==" << std::endl;
	if (lo == lo2)
		std::cout << "both stacks are equal" << std::endl;
	else
		std::cout << "both stacks are not equal" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "operator : " << ">" << std::endl;
	if (lo > lo2)
		std::cout << "stack1 is > than stack2" << std::endl;
	else
		std::cout << "stack1 is not > than stack2" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "operator : " << ">=" << std::endl;
	if (lo >= lo2)
		std::cout << "stack1 is >= than stack2" << std::endl;
	else
		std::cout << "stack 1 is not >= than stack2" << std::endl;

	std::cout << "================================" << std::endl;
	std::cout << "operator : " << "!=" << std::endl;
	if (lo != lo2)
		std::cout << "both stacks are differents" << std::endl;
	else
		std::cout << "both stacks are equal" << std::endl;
	std::cout << "================================" << std::endl;
}
