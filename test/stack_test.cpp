#include "../stack.hpp"
#include <iostream>
#include <stack>

int main(void)
{
	ft::stack<int> s;
	ft::stack<int> s1;

	if (s == s1)
		std::cout << "equal\n";
	if (s.empty())
		std::cout << "empty\n";
	std::cout << "size : " << s.size();
	for (int i = 0; i < 4; i++)
		s.push(11);
	if (!s.empty())
		std::cout << "\nnot empty\n";
	std::cout << "size : " << s.size();
	if (s != s1)
		std::cout << "\nnot equal\n";
	if (s > s1)
		std::cout << "greater\n";
	std::cout << "top : " << s.top();
	s.push(21);
	s.push(42);
	std::cout << "\ntop : " << s.top();
	std::cout << "\nsize : " << s.size();
	s.pop();
	std::cout << "\ntop : " << s.top();
	std::cout << "\nsize : " << s.size();
	std::cout << std::endl;

	return (0);
}
