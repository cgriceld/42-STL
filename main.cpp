// #include "vector.hpp"
// #include "iterator.hpp"

#include <iostream>
#include <vector>

int main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	int arr1[] = {6, 7, 8};
	std::vector<int> v(arr, arr + 5);
	std::vector<int> v1(arr1, arr1 + 3);

	// std::vector<int> v3;

	// // v1.assign(v.begin(), v.end());
	// v1.insert(v1.end(), 9);
	// for(std::vector<int>::iterator i = v1.begin(); i != v1.end(); i++)
	// 	std::cout << *i << " ";

	std::cout << v1.capacity() << std::endl;
	v1.push_back(9);
	std::cout << v1.capacity() << std::endl;
	for(std::vector<int>::iterator i = v1.begin(); i != v1.end(); i++)
		std::cout << *i << " ";

	// std::cout << v.size() << std::endl;
	// std::cout << v.capacity() << std::endl;

	// std::vector<int>::iterator it = v.end() - 1;
	// std::vector<int>::iterator it2 = v.end();

	// std::cout << *it << std::endl;
	// std::cout << *it2 << std::endl;
	
	// std::vector<int>::iterator it3 = v.erase(it, it2);
	// std::cout << *it3 << std::endl;

	// for(std::vector<int>::iterator i = v.begin(); i != v.end(); i++)
	// 	std::cout << *i << " ";

	// std::cout << std::endl << *it << std::endl;
	// std::cout << *it2 << std::endl;
	
	// std::cout << v.size() << std::endl;
	// std::cout << v.capacity() << std::endl;
	
	
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