#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "../vector.hpp"

template <typename T>
void iterator_test(T it)
{
	T init = it;

	std::cout << "*it++ : " << *it++ << '\n';
	std::cout << "*(++it) : " << *(++it) << '\n';
	std::cout << "*it-- : " << *it-- << '\n';
	std::cout << "*(--it) : " << *(--it) << '\n';
	it += 2;
	std::cout << "it += 2 : " << *it << '\n';
	std::cout << "*(it + 1) : " << *(it + 1) << '\n';
	it -= 2;
	std::cout << "it -= 2 : " << *it << '\n';
	std::cout << "*(it - 1) : " << *(it - 1) << '\n';
	std::cout << "*it.base() : " << *it.base() << '\n';
	std::cout << "it[2] : " << it[2] << '\n';
	std::cout << "it[-2] : " << it[-2] << '\n';

	std::cout << (init == it ? "equal" : "not equal") << '\n';
	init++;
	std::cout << (init != it ? "not equal" : "equal") << '\n';
	std::cout << (init > it ? "greater" : "less") << '\n';
	std::cout << (it < init ? "less" : "greater") << '\n';
	std::cout << init - it << '\n';
}

template <typename T, typename It>
void traverse(ft::vector<T> &v, It begin, It end)
{
	std::cout << "size : " << v.size() << ", capacity : " << v.capacity() << std::endl;
	std::cout << "[";
	for (; begin != end; begin++)
	{
		std::cout << *begin;
		if (begin != (end - 1))
			std::cout << ", ";
	}
	std::cout << "]\n";
}
