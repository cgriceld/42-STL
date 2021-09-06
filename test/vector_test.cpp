#include "test_utils.hpp"

int main(void)
{
	std::cout << "\n\033[1;33m============= CONSTRUCTORS TESTS =============\033[0m\n\n";

	{
		std::cout << "\033[0;36mDEFAULT\n\n\033[0m";
		ft::vector<int> v;
		traverse(v, v.begin(), v.end());
		std::cout << "v.empty() - " << (v.empty() ? "vector is empty" : "vector isn't empty") << '\n';
	}
	{
		std::cout << "\n\n\033[0;36mFILL DEFAULT (int, string)\n\n\033[0m";
		ft::vector<int> v(5);
		ft::vector<std::string> s(3);
		traverse(v, v.begin(), v.end());
		traverse(s, s.begin(), s.end());
	}
	{
		std::cout << "\n\n\033[0;36mFILL VALUE\n\n\033[0m";
		ft::vector<int> v(5, 10);
		traverse(v, v.begin(), v.end());
	}

	int arr[] = {1, -2, 3, 6, 21, 0, 9};
	ft::vector<int> ptr_v(arr, arr + 7);
	ft::vector<int> v_iter(ptr_v.begin(), ptr_v.end());

	{
		std::cout << "\n\n\033[0;36mFILL RANGE\n\n\033[0m";

		ft::vector<int> v_arr(arr, arr + 4);
		std::cout << "fill by pointers : \n";
		traverse(v_arr, v_arr.begin(), v_arr.end());

		std::cout << "\nvector range iterators : \n";
		traverse(v_iter, v_iter.begin(), v_iter.end());

		ft::vector<int> v_iter_same(ptr_v.begin(), ptr_v.begin());
		std::cout << "\nvector same iterators : \n";
		traverse(v_iter_same, v_iter_same.begin(), v_iter_same.end());

		std::cout << "\n\n\033[0;36mCOPY & =\n\n\033[0m";
		ft::vector<int> copy(v_arr);
		std::cout << "copy : \n";
		traverse(copy, copy.begin(), copy.end());
		v_arr = v_iter;
		std::cout << "\nassignment :  \n";
		traverse(v_arr, v_arr.begin(), v_arr.end());
	}

	std::cout << "\n\n\033[1;33m============= ACCESS TESTS =============\033[0m\n\n";

	traverse(v_iter, v_iter.begin(), v_iter.end());
	try
	{
		std::cout << "\nindex [3] : " << v_iter[3] << ", index [0] : " << v_iter[0] << '\n';
		std::cout << "index at(6) : " << v_iter.at(6) << ", index at(21) : " << v_iter.at(21);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "index at(-1) : " << v_iter.at(-1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	{
		std::cout << "\n\033[0;36mFRONT\n\033[0m";
		int &f = v_iter.front();
		std::cout << "front : " << f;
		f = 4;
		std::cout << "\nchange front to 4 : " << v_iter.front();

		std::cout << "\n\n\033[0;36mBACK\n\033[0m";
		int &b = v_iter.back();
		std::cout << "back : " << b;
		b = 17;
		std::cout << "\nchange front to 17 : " << v_iter.back();
	}

	std::cout << "\n\n\033[0;36mMAX SIZE\n\033[0m";
	std::cout << v_iter.max_size() << '\n';

	std::cout << "\n\n\033[1;33m============= ITERATORS TESTS =============\033[0m\n\n";

	std::cout << "\033[0;36mFORWARD TRAVERSE --> \n\033[0m";
	traverse(v_iter, v_iter.begin(), v_iter.end());
	std::cout << "\033[0;36m\n<-- REVERSE TRAVERSE \n\033[0m";
	traverse(v_iter, v_iter.rbegin(), v_iter.rend());

	std::cout << "\033[0;36m\n/start point is in the middle, value 6/";
	std::cout << "\nITERATOR TEST\033[0m\n";
	iterator_test(v_iter.begin() + 3);
	std::cout << "\n\033[0;36mREVERSE ITERATOR TEST\033[0m\n";
	iterator_test(v_iter.rbegin() + 3);

	std::cout << "\n\n\033[1;33m============= ASSIGN TESTS =============\033[0m\n\n";
	{
		std::cout << "\033[0;36mEMPTY VECTOR\n\033[0m";
		ft::vector<int> v;
		std::cout << "\nassign(0, 6) : \n";
		v.assign(0, 6);
		traverse(v, v.begin(), v.end());
		std::cout << "\nassign(3, 4) : \n";
		v.assign(3, 4);
		traverse(v, v.begin(), v.end());
		std::cout << "\nassign(1, 1) : \n";
		v.assign(1, 1);
		traverse(v, v.begin(), v.end());

		std::cout << "\033[0;36m\nNOT EMPTY VECTOR\n\033[0m";
		int arr[] = {13, 21, 42, 7, -9};
		int arr1[] = {3, 4, 0, -1, 1, 11};
		ft::vector<int> r(arr, arr + 5);
		ft::vector<int> r1(arr1, arr1 + 6);
		traverse(r, r.begin(), r.end());
		std::cout << "\nassign(arr + 1, arr + 4) : \n";
		r.assign(arr + 1, arr + 4);
		traverse(r, r.begin(), r.end());
		std::cout << "\nassign(arr, arr) : \n";
		r.assign(arr, arr);
		traverse(r, r.begin(), r.end());
		std::cout << "\nassign(r1.begin(), r1.end()) : \n";
		r.assign(r1.begin(), r1.end());
		traverse(r, r.begin(), r.end());
		r.assign(0, 0);
		traverse(r, r.begin(), r.end());
	}

	return (0);
}
