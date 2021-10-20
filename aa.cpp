#include <iostream>
#include <map>

int main (void)
{
	std::map<int, int> m;
	std::map<int, int>::iterator it = m.begin();
	std::map<int, int>::iterator it1 = m.end();

	if (it == it1)
		std::cout << "equal\n";
	else
		std::cout << "not equal\n";

	return (0);
}