#pragma once

#include <cstddef>

namespace ft
{
	// Iterator tags

	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	// Iterator traits

	template<typename Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::iterator_category iterator_category;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
	};

	template<typename T>
	struct iterator_traits<T *>
	{
		typedef random_access_iterator_tag iterator_category;
		typedef T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef T *pointer;
		typedef T &reference;
	};

	template<typename T>
	struct iterator_traits<const T *>
	{
		typedef random_access_iterator_tag iterator_category;
		typedef T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef const T *pointer;
		typedef const T &reference;
	};

	// Base iterator class

	template<typename Category, typename T, typename Distance = std::ptrdiff_t,
		typename Pointer = T*, typename Reference = T&>
	struct iterator
	{
		typedef Category  iterator_category;
		typedef T        value_type;
		typedef Distance  difference_type;
		//typedef Pointer   pointer;
		typedef Reference reference;

		Pointer a;
	};

	// Vector iterator (LegacyRandomAccessIterator)

	template<typename T>
	class v_iterator : public iterator_traits<T *>
	{
		public:
			pointer _current;

		// typedef iterator_traits<T *> __traits_type;

		// public:
		// 	typedef typename __traits_type::reference reference;
		// 	typedef typename __traits_type::pointer pointer;
		// 	typedef typename __traits_type::difference_type difference_type;

		// 	v_iterator() : _current(Iterator()) {};
		// 	explicit v_iterator(const Iterator &i) : _current(i) {};

		// 	reference operator[](difference_type __n) const
		// 	{
		// 		return *(*this + __n);
		// 	}
	};
	}