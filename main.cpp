//#include "vector.hpp"

#include <iostream>
#include <vector>
// #include "utils.hpp"

int main(void)
{
	std::vector<int> v;
	try
	{
		v.reserve(-1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	// std::cout << "\ninsert(v.begin(), 1) : \n";
	// auto it = v.insert(v.end(), 1);
	// if (it == v.begin())
	// 	std::cout << "correct\n";
	// for(auto it = v.begin(); it != v.end(); it++)
	// 	std::cout << *it;
	// std::cout << std::endl;

	// std::cout << "\ninsert(v.end(), 2) : \n";
	// it = v.insert(v.end(), 2);
	// if (it == v.begin() + 1)
	// 	std::cout << "correct\n";
	// for(auto it = v.begin(); it != v.end(); it++)
	// 	std::cout << *it;
	// std::cout << std::endl;
	// std::cout << v.capacity() << v.size();

	return(0);
}