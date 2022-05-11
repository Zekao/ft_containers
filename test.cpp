#include "vector.hpp"
#include <vector>
// #define TESTED_NAMESPACE std
#define TESTED_TYPE int

#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

template <typename T>
void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

void	is_empty(TESTED_NAMESPACE::vector<TESTED_TYPE> const &vct)
{
	std::cout << "is_empty: " << vct.empty() << std::endl;
}

int		main(void)
{
	const int start_size = 7;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(start_size, 20);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();

	for (int i = 2; i < start_size; ++i)
		it[i] = (start_size - i) * 3;
	printSize(vct, true);

	vct.resize(10, 42);
	printSize(vct, true);

	vct.resize(18, 43);
	printSize(vct, true);
	vct.resize(10);
	printSize(vct, true);
	vct.resize(23, 44);
	printSize(vct, true);
	vct.resize(5);
	printSize(vct, true);
	vct.reserve(5);
	vct.reserve(3);
	printSize(vct, true);
	vct.resize(87);
	vct.resize(5);
	printSize(vct, true);

	is_empty(vct2);
	vct2 = vct;
	is_empty(vct2);
	vct.reserve(vct.capacity() + 1);
	printSize(vct, true);
	std::cout << "DEBUG" << std::endl;
	printSize(vct2, true);

	vct2.resize(0);
	is_empty(vct2);
	printSize(vct2, true);
	return (0);
}

// int main ()
// {
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> foo(3, 15);
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> bar(5, 42);
	
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator it_foo = foo.begin();
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator it_bar = bar.begin();

// 	std::cout << "BEFORE SWAP" << std::endl;

// 	std::cout << "foo contains:" << std::endl;
// 	printSize(foo);
// 	std::cout << "bar contains:" << std::endl;
// 	printSize(bar);

// 	foo.swap(bar);

// 	std::cout << "AFTER SWAP" << std::endl;

// 	std::cout << "foo contains:" << std::endl;
// 	printSize(foo);
// 	std::cout << "bar contains:" << std::endl;
// 	printSize(bar);

// 	std::cout << "Iterator validity:" << std::endl;
// 	std::cout << (it_foo == bar.begin()) << std::endl;
// 	std::cout << (it_bar == foo.begin()) << std::endl;

// 	return (0);
// }
