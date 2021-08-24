#include "vector.hpp"
#include <iostream>
#include "iterator.hpp"

int main(void)
{
	ft::vector<int> test;
	ft::vector<int>::iterator it;
	ft::iterator_traits<ft::vector<int>::iterator>::pointer();
	std::cout << *test.begin() << std::endl;
	ft::iterator_traits<ft::vector<int>::const_iterator>::pointer();

	return(0);
}