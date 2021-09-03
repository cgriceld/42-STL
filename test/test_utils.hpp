#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "../vector.hpp"

template <typename T>
std::ostream & operator << (std::ostream &stream, ft::vector<T> &v)
{
	stream << "size : " << v.size() << ", capacity : " << v.capacity() << std::endl;
	stream << "[";
	for (typename ft::vector<T>::iterator it = v.begin(); it != v.end(); it++)
	{
		stream << *it;
		if (it != --v.end())
			stream << ", ";
	}
	stream << "]\n";
	return (stream);
}
