#pragma once

namespace ft
{
	template <class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return (false);
			++first1; ++first2;
		}
		return (true);
	}

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, \
									InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1<*first2)
				return (true);
			++first1; ++first2;
		}
		return (first2 != last2);
	}

	template <class T> struct remove_const { typedef T type; };
	template <class T> struct remove_const<const T> { typedef T type; };

	template <typename>
	struct is_integral_helper
	{
		static const bool value = false;
	};

	template <>
	struct is_integral_helper<bool>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral_helper<char>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral_helper<unsigned char>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral_helper<wchar_t>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral_helper<char16_t>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral_helper<char32_t>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral_helper<short>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral_helper<unsigned short>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral_helper<int>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral_helper<unsigned int>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral_helper<long>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral_helper<unsigned long>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral_helper<long long>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral_helper<unsigned long long>
	{
		static const bool value = true;
	};

	template<typename T>
	struct is_integral : public is_integral_helper<typename remove_const<T>::type> {};

	template<bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };
}