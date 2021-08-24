#pragma once

#include <cstddef>

namespace ft
{
	// ========================== TAGS ========================== //

	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	// ========================== TRAITS ========================== //

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

	// ========================== BASE ITERATOR CLASS ========================== //

	template<typename Category, typename T, typename Distance = std::ptrdiff_t,
		typename Pointer = T*, typename Reference = T&>
	struct iterator
	{
		typedef Category iterator_category;
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
	};

	// ========================== [const] LegacyRandomAccessIterator ========================== //

	template<typename T>
	class v_iterator : public iterator <random_access_iterator_tag, T>
	{
		public:
			typedef typename iterator<random_access_iterator_tag, T>::reference reference;
			typedef typename iterator<random_access_iterator_tag, T>::pointer pointer;
			typedef typename iterator<random_access_iterator_tag, T>::difference_type difference_type;

			v_iterator(pointer current = NULL) : _current(current) {};
			explicit v_iterator(const v_iterator &copy) : _current(copy._current) {};
			~v_iterator() {};

			v_iterator &operator = (const v_iterator &copy)
			{
				if (this != copy)
					_current = copy._current;
				return (*this);
			}

			reference operator [] (difference_type __n) const
			{
				return (*(_current + __n));
			}

			reference operator * (void) const
			{
				return (*_current);
			}

			pointer operator -> (void) const
			{
				return (_current);
			}

			v_iterator &operator ++ (void)
			{
				++_current;
				return (*this);
			}

			v_iterator operator ++ (int)
			{
				return (v_iterator(_current++));
			}

			v_iterator &operator += (difference_type __n)
			{
				_current += __n;
				return (*this);
			}

			v_iterator &operator + (difference_type __n) const
			{
				return (v_iterator(_current + __n));
			}

			v_iterator &operator -- (void)
			{
				--_current;
				return (*this);
			}

			v_iterator operator -- (int)
			{
				return (v_iterator(_current--));
			}

			v_iterator &operator -= (difference_type __n)
			{
				_current -= __n;
				return (*this);
			}

			v_iterator &operator - (difference_type __n) const
			{
				return (v_iterator(_current - __n));
			}

			// difference_type operator - (const v_iterator &other) const
			// {
			// 	return (_current - other._current);
			// }

			const pointer &base(void) const
			{
				return (_current);
			}
		
		private:
			pointer _current;
	};

	template<typename T>
	bool operator == (const v_iterator<T> &l, const v_iterator<T> &r)
	{
		return (l.base() == r.base());
	}

	template<typename lT, typename rT>
	bool operator == (const v_iterator<lT> &l, const v_iterator<rT> &r)
	{
		return (l.base() == r.base());
	}

	template<typename T>
	bool operator != (const v_iterator<T> &l, const v_iterator<T> &r)
	{
		return (l.base() != r.base());
	}

	template<typename lT, typename rT>
	bool operator != (const v_iterator<lT> &l, const v_iterator<rT> &r)
	{
		return (l.base() != r.base());
	}

	template<typename T>
	bool operator < (const v_iterator<T> &l, const v_iterator<T> &r)
	{
		return (l.base() < r.base());
	}

	template<typename lT, typename rT>
	bool operator < (const v_iterator<lT> &l, const v_iterator<rT> &r)
	{
		return (l.base() < r.base());
	}

	template<typename T>
	bool operator <= (const v_iterator<T> &l, const v_iterator<T> &r)
	{
		return (l.base() <= r.base());
	}

	template<typename lT, typename rT>
	bool operator <= (const v_iterator<lT> &l, const v_iterator<rT> &r)
	{
		return (l.base() <= r.base());
	}

	template<typename T>
	bool operator > (const v_iterator<T> &l, const v_iterator<T> &r)
	{
		return (l.base() > r.base());
	}

	template<typename lT, typename rT>
	bool operator > (const v_iterator<lT> &l, const v_iterator<rT> &r)
	{
		return (l.base() > r.base());
	}

	template<typename T>
	bool operator >= (const v_iterator<T> &l, const v_iterator<T> &r)
	{
		return (l.base() >= r.base());
	}

	template<typename lT, typename rT>
	bool operator >= (const v_iterator<lT> &l, const v_iterator<rT> &r)
	{
		return (l.base() >= r.base());
	}

	template<typename T>
	typename v_iterator<T>::difference_type operator - (const v_iterator<T> &l, const v_iterator<T> &r)
	{
		return (l.base() - r.base());
	}

	template<typename lT, typename rT>
	bool operator - (const v_iterator<lT> &l, const v_iterator<rT> &r)
	{
		return (l.base() - r.base());
	}
}