// #include "vector.hpp"
// #include "iterator.hpp"

#include <iostream>
#include <vector>

int main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	std::vector<int> v(arr, arr + 5);
	try
	{
		std::cout << v.at(21);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	// std::vector<int>::reverse_iterator itr = v.rbegin();

	// std::cout << it.base() << " " << it.operator->() << std::endl;
	// std::cout << *it.base() << " " << *it.operator->() << std::endl;

	// it++;

	// std::cout << it.base() << " " << it.operator->() << std::endl;
	// std::cout << *it.base() << " " << *it.operator->() << std::endl;

	// printf("reverse\n");

	// std::cout << itr.operator->() << std::endl;
	// std::cout << *itr.operator->() << std::endl;
	// itr++;
	// std::cout << itr.operator->() << std::endl;
	// std::cout << *itr.operator->() << std::endl;
	// std::cout << itr[1] << std::endl;
	// std::cout << itr[-1] << std::endl;
	// ft::iterator_traits<ft::vector<int>::iterator>::pointer();
	// std::cout << *test.begin() << std::endl;
	// ft::iterator_traits<ft::vector<int>::const_iterator>::pointer();

	// std::vector<int>::iterator ite = v.end();
	// std::cout << ite - it << std::endl;

	return(0);
}