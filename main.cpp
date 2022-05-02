#include <stack>
#include <map>
#include <vector>
#include <iostream>
#include "vector.hpp"
int	main(void)
{
	std::map <size_t, std::string> test;
	std::map <size_t, std::string>::iterator map_iterator;
	std::vector <int> v;
	// test.insert("bonjour");
	test.insert(std::pair<size_t, std::string>(42, "oui"));
	map_iterator = test.begin();
	std::cout << "value of first elem " << map_iterator->first << " second elem " << map_iterator->second << std::endl;
	std::cout << "test : " << test.empty() << std::endl;
	
}