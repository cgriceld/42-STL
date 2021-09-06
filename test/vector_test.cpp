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
	{
		std::cout << "\nFILL RANGE\n";
		int arr[] = {1, -2, 3, 6};
		ft::vector<int> std_v(arr, arr + 4);
		ft::vector<int> v_arr(arr, arr + 4);
		ft::vector<int> v_iter(std_v.begin(), std_v.end() - 1);
		std::cout << v_arr << v_iter;
	}

	return (0);
}
