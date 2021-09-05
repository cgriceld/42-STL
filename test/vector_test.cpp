#include "test_utils.hpp"

int main(void)
{
	std::cout << "============= CONSTRUCTORS TESTS =============\n\n";

	{
		std::cout << "DEFAULT\n";
		ft::vector<int> v;
		std::cout << v;
	}
	{
		std::cout << "\nFILL DEFAULT\n";
		ft::vector<int> v(5);
		ft::vector<std::string> s(3);
		std::cout << v << s;
	}
	{
		std::cout << "\nFILL VALUE\n";
		ft::vector<int> v(5, 10);
		std::cout << v;
	}


	return (0);
}
