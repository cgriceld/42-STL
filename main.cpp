#include "map.hpp"
#include <iostream>
#include <map>

int main(void)
{
	ft::map<int, char> t;
	std::cout << "INSERT 1\n";
	t.insert(ft::make_pair(1, 'a'));
	std::cout << "----------\n";
	std::cout << "INSERT 3\n";
	t.insert(ft::make_pair(3, 'a'));
	std::cout << "----------\n";
	std::cout << "INSERT 4\n";
	t.insert(ft::make_pair(4, 'a'));
	std::cout << "----------\n";
	std::cout << "INSERT 5\n";
	t.insert(ft::make_pair(5, 'a'));
	std::cout << "----------\n";
	std::cout << "INSERT -3\n";
	t.insert(ft::make_pair(-3, 'a'));
	std::cout << "----------\n";
	std::cout << "INSERT 10\n";
	t.insert(ft::make_pair(10, 'a'));
	std::cout << "----------\n";
	std::cout << "INSERT 2\n";
	ft::pair<ft::map<int, char>::iterator, bool> p = t.insert(ft::make_pair(2, 'a'));
	std::cout << p.first->first << "," << p.second << std::endl;

	ft::pair<ft::map<int, char>::iterator, bool> pi = t.insert(ft::make_pair(2, 'a'));
	std::cout << pi.first->first << "," << pi.second << std::endl;
	// std::cout << "----------\n";
	// std::cout << "INSERT 10\n";
	// t.insert(ft::make_pair(1, 'a'));
	
	std::cout << "============\n";

	// ft::Rb_tree<int, std::less<int> >::iterator it = t.begin();
	// std::cout << *it << std::endl;
	// it++;
	// std::cout << *it << std::endl;
	// it++;
	// std::cout << *it << std::endl;
	// it++;
	// std::cout << *it << std::endl;
	// it++;
	// std::cout << *it << std::endl;
	// it++;
	// std::cout << *it << std::endl;
	// it++;
	// std::cout << *it << std::endl;
	// it++;
	// std::cout << *it << std::endl;
	// std::cout << "----------\n";

	// ft::Rb_tree<int, std::less<int> >::iterator ite = t.end();
	// std::cout << *ite << std::endl;
	// ite--;
	// std::cout << *ite << std::endl;
	// ite--;
	// std::cout << *ite << std::endl;
	// ite--;
	// std::cout << *ite << std::endl;
	// ite--;
	// std::cout << *ite << std::endl;
	// // ite--;
	// // std::cout << *ite << std::endl;
	// // ite--;
	// // std::cout << *ite << std::endl;
	// // ite--;
	// // std::cout << *ite << std::endl;
	// // ite--;
	// // std::cout << *ite << std::endl;
	// // std::cout << "----------\n";

	// ft::Rb_tree<int, std::less<int> >::reverse_iterator itr = t.rend();
	// //std::cout << *itr << std::endl;
	// itr--;
	// std::cout << *itr << std::endl;
	// itr--;
	// std::cout << *itr << std::endl;
	// itr--;
	// std::cout << *itr << std::endl;
	// itr--;
	// std::cout << *itr << std::endl;

	// std::map<char, int> t;
	// t.insert(std::pair<char, int>('a', 4));
	// t.insert(std::pair<char, int>('b', 4));
	// t.insert(std::pair<char, int>('c', 4));
	// t.insert(std::pair<char, int>('d', 4));

	// std::map<char, int>::reverse_iterator itr = t.rend();
	// //std::cout << itr->first << std::endl;
	// itr--;
	// std::cout << itr->first << std::endl;
	// itr--;
	// std::cout << itr->first << std::endl;
	// itr--;
	// std::cout << itr->first << std::endl;
	// itr--;
	// std::cout << itr->first << std::endl;
	// itr--;
	// std::cout << itr->first << std::endl;

	// std::map<char, int>::reverse_iterator itr = t.rbegin();
	// std::cout << itr->first << std::endl;
	// itr++;
	// std::cout << itr->first << std::endl;
	// itr++;
	// std::cout << itr->first << std::endl;
	// itr++;
	// std::cout << itr->first << std::endl;
	// itr++;
	// std::cout << itr->first << std::endl;

	// std::map<char, int>::iterator it = t.begin();
	// std::cout << it->first << std::endl;
	// it++;
	// it++;
	// it++;
	// std::cout << it->first << std::endl;
	// it++;
	// std::cout << it->first << std::endl;
	// it++;
	// std::cout << it->first << std::endl;
	// std::cout << "----------\n";

	// std::map<char, int>::iterator ite = t.end();
	// ite++;
	// ite--;
	// std::cout << ite->first << std::endl;
	// ite--;
	// std::cout << ite->first << std::endl;
	// ite--;
	// ite--;
	// ite--;
	// std::cout << ite->first << std::endl;
	// ite--;
	// std::cout << ite->first << std::endl;

	return (0);
}