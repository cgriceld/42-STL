#include "vector.hpp"
#include <iostream>

int main(void)
{
	ft::vector<int>::iterator it;
	std::cout << ft::iterator_traits<ft::vector<int>::iterator>::pointer();
	return(0);
}