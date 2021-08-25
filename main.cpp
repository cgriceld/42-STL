#include "vector.hpp"
#include <iostream>
#include "iterator.hpp"
#include <vector>

int main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	std::vector<int> v(arr, arr + 5);
	std::vector<int>::iterator it = v.begin();
	std::vector<int>::reverse_iterator itr = v.rbegin();

	std::cout << it.base() << " " << it.operator->() << std::endl;
	std::cout << *it.base() << " " << *it.operator->() << std::endl;

	it++;

	std::cout << it.base() << " " << it.operator->() << std::endl;
	std::cout << *it.base() << " " << *it.operator->() << std::endl;

	printf("reverse\n");

	std::cout << itr.operator->() << std::endl;
	std::cout << *itr.operator->() << std::endl;
	itr++;
	std::cout << itr.operator->() << std::endl;
	std::cout << *itr.operator->() << std::endl;
	std::cout << itr[1] << std::endl;
	std::cout << itr[-1] << std::endl;
	// ft::iterator_traits<ft::vector<int>::iterator>::pointer();
	// std::cout << *test.begin() << std::endl;
	// ft::iterator_traits<ft::vector<int>::const_iterator>::pointer();

	return(0);
}