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
			typedef typename v_iterator<T>::reference reference;
			typedef typename v_iterator<T>::pointer pointer;
			typedef typename v_iterator<T>::difference_type difference_type;

		// ---------------- CONSTRUCTORS & DESTRUCTOR ---------------- //

			v_iterator() : _current(NULL) {};
			explicit v_iterator(pointer current) : _current(current) {};
			v_iterator(const v_iterator &copy) : _current(copy._current) {};

			v_iterator &operator = (const v_iterator &copy)
			{
				if (this != &copy)
					_current = copy._current;
				return (*this);
			};

			~v_iterator() {};

		// ---------------- ACCESS ---------------- //

			reference operator [] (difference_type __n) const
			{
				return (_current[__n]);
			}

			reference operator * (void) const
			{
				return (*_current);
			}

			pointer operator -> (void) const
			{
				return (_current);
			}

			pointer base(void) const
			{
				return (_current);
			}

		// ---------------- PLUS ---------------- //

			v_iterator &operator ++ (void)
			{
				++_current;
				return (*this);
			}

			v_iterator operator ++ (int)
			{
				return (_current++);
			}

			v_iterator &operator += (difference_type __n)
			{
				_current += __n;
				return (*this);
			}

			v_iterator operator + (difference_type __n) const
			{
				return (_current + __n);
			}

			// ---------------- MINUS ---------------- //

			v_iterator &operator -- (void)
			{
				--_current;
				return (*this);
			}

			v_iterator operator -- (int)
			{
				return (_current--);
			}

			v_iterator &operator -= (difference_type __n)
			{
				_current -= __n;
				return (*this);
			}

			v_iterator operator - (difference_type __n) const
			{
				return (_current - __n);
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
	typename v_iterator<lT>::difference_type operator - (const v_iterator<lT> &l, const v_iterator<rT> &r)
	{
		return (l.base() - r.base());
	}

	template<typename T>
	v_iterator<T> operator + (typename v_iterator<T>::difference_type __n, const v_iterator<T> &i)
	{
		return (i + __n);
	}

	// ========================== REVERSE_ITERATOR ========================== //

	template<typename _Iterator>
	class reverse_iterator : public iterator<typename iterator_traits<_Iterator>::iterator_category,
							typename iterator_traits<_Iterator>::value_type,
							typename iterator_traits<_Iterator>::difference_type,
							typename iterator_traits<_Iterator>::pointer,
							typename iterator_traits<_Iterator>::reference>
	{
		protected:
			_Iterator _current;

			typedef iterator_traits<_Iterator> __traits_type;

		public:
			typedef _Iterator iterator_type;
			typedef typename __traits_type::difference_type difference_type;
			typedef typename __traits_type::pointer pointer;
			typedef typename __traits_type::reference reference;

		// ---------------- CONSTRUCTORS & DESTRUCTOR ---------------- //

			reverse_iterator() : _current() {};
			explicit reverse_iterator(iterator_type __x) : _current(__x) {};

			template<class U>
			reverse_iterator(const reverse_iterator<U> &__x) : _current(__x.current) {};

			template<class U>
			reverse_iterator &operator = (const reverse_iterator<U> &other)
			{
				if (this != &other)
					_current = other._current;
				return (*this);
			}

		// ---------------- ACCESS ---------------- //

			iterator_type base(void) const { return (_current); };

			reference operator * (void) const
			{
				iterator_type tmp = _current;
				return (*--tmp);
			};

			pointer operator->() const
			{
				return (&(operator*()));
			}

			reference operator [] (difference_type n)
			{
				return (base()[-n - 1]);
			}
	};
}