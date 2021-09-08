#include "stack.hpp"
#include <iostream>

int main(void)
{

	ft::stack<int> s;
	ft::stack<int> s1;

	if (s < s1)
		std::cout << "less\n";

	return(0);
}