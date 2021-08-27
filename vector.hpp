#pragma once

#include <memory>
#include <algorithm>
#include "iterator.hpp"
#include "utils.hpp"

namespace ft
{
	template < class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T value_type;
			typedef Allocator allocator_type;
			typedef std::size_t size_type;
			typedef std::ptrdiff_t difference_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename ft::v_iterator<T> iterator;
			typedef typename ft::v_iterator<const T> const_iterator;
			typedef typename ft::reverse_iterator<iterator> reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
		
		protected:
			pointer __begin_;
			pointer __end_; // past-the-one elem
			pointer __end_cap_;
			allocator_type __alloc_;

		private:
			void realloc(size_type n)
			{
				pointer begin_new, end_new;
				begin_new = end_new = alloc.allocate(n);
				if (!empty())
				{
					for(; __begin_ != __end_; __begin_++, end_new++)
						alloc.construct(end_new, *__begin_);
				}
				~vector();
				__begin_ = begin_new;
				__end_ = end_new;
				__end_cap_ = __begin_ + n;
			}

			void range_init(iterator position, iterator first, iterator last)
			{
				for(; first != last; position++, first++)
					alloc.construct(position, *first);
			}

			void val_init(iterator position, size_type n, const value_type &val)
			{
				for(size_t i = 0; i < n; position++)
					alloc.construct(position, val);
			}

			void insert_shared(iterator position, size_type n)
			{
				if (!n)
					return;
				if (__end_ + n > __end_cap_)
				{
					difference_type index = position - __begin_;
					realloc(std::max(size() + n, capacity() * 2);
					position = __begin_ + index;
				}
				for (difference_type move = __end_ - position - 1; move-- >= 0)
				{
					alloc.destroy(position + move);
					alloc.construct(position + move + 1, *(position + move));
				}
				__end_ += n;
			}

			void constr_range(iterator first, iterator last)
			{
				size_t count = static_cast<size_type>(last - first);
				__begin_ = alloc.allocate(count);
				range_init(__begin_, first, last);
				__end_cap_ = __end_ += count;
			}

		public:

		// ========================== CONSTRUCTORS & DESTRUCTOR ========================== //

			explicit vector (const allocator_type &alloc = allocator_type())
			: __begin_(NULL), __end_(NULL), __end_cap_(NULL), __alloc_(alloc) {};

			explicit vector (size_type n, const value_type &val = value_type(),
			const allocator_type &alloc = allocator_type()) : __alloc_(alloc)
			{
				__begin_ = alloc.allocate(n);
				val_init(__begin_, n, val);
				__end_cap_ = __end_ += n;
			}

			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type())  : __alloc_(alloc)
			{
				constr_range(first, last);
			}

			vector (const vector &x) : __alloc_(x.alloc)
			{
				constr_range(x.begin(), x.end());
			}

			~vector() 
			{
				clear();
				alloc.deallocate(__begin_, capacity());
			}

		// ========================== OPERATORS ========================== //

			vector &operator = (const vector &x)
			{
				if (this != &x)
					assign(x.begin(), x.end());
				return (*this);
			};

			reference operator[] (size_type n) { return (__begin_[n]); };

			const_reference operator[] (size_type n) const { return (__begin_[n]); };

		// ========================== ITERATORS ========================== //

			iterator begin(void) { return (__begin_); };
			const_iterator begin(void) const { return (__begin_); };

			reverse_iterator rbegin(void) { return (__end_); };
			const_reverse_iterator rbegin(void) const { return (__end_); };

			iterator end(void) { return (__end_); };
			const_iterator end(void) const { return (__end_); };

			reverse_iterator rend(void) { return (__begin_); };
			const_reverse_iterator rend(void) const { return (__begin_); };

		// ========================== MEMBER FUNCTIONS ========================== //

		// ---------------- ACCESS / INFO ---------------- //

			reference at (size_type n)
			{
				if (n < 0 || n >= size())
					throw std::out_of_range("index is out of range");
				return (__begin_[n]);
			}

			const_reference at (size_type n) const
			{
				if (n < 0 || n >= size())
					throw std::out_of_range("index is out of range");
				return (__begin_[n]);
			}

			reference front(void) { return (*__begin_); };

			const_reference front(void) const { return (*__begin_); };

			reference back(void) { return (*(__end_ - 1)); };

			const_reference back(void) const { return (*(__end_ - 1)); };

			size_type capacity(void) const { return (static_cast<size_type>(__end_cap_ - __begin_)); };

			bool empty(void) const { return (__begin_ == __end_); };

			size_type size(void) const { return (static_cast<size_type>(__end_ - __begin_)); };

			size_type max_size(void) const { return (__alloc_.max_size()); };

			allocator_type get_allocator(void) const { return (__alloc_); };

		// ---------------- MODIFIERS ---------------- //

			iterator erase (iterator first, iterator last)
			{
				if (first == last)
					return;
				difference_type diff = last - first;
				for(; first != last; first++)
					alloc.destroy(first);
				for (; last != __end_; last++)
				{
					alloc.construct(last - diff, *last);
					alloc.destroy(last);
				}
				__end_ -= diff;
				return (first);
			}

			iterator erase (iterator position) { return (erase(position, position + 1)); };

			void clear(void) { erase(__begin_, __end_); };

			void pop_back(void) { erase(__end_ - 1, __end_); };

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last)
			{
				insert_shared(position, last - first);
				range_init(position, first, last);
			}

			void insert (iterator position, size_type n, const value_type &val)
			{
				insert_shared(position, n);
				val_init(position, n, val);
			}

			iterator insert (iterator position, const value_type &val)
			{
				insert(position, 1, val);
				return (position);
			}

			template<class InputIt>
			void assign(InputIt first, InputIt last)
			{
				size_t count = static_cast<size_type>(last - first);
				if (!count)
					return;
				clear();
				reserve(count);
				range_init(__begin_, first, last);
				__end_ += count;
			}

			void assign(size_type count, const T &value)
			{
				if (!count)
					return;
				clear();
				reserve(count);
				val_init(__begin_, count, value);
				__end_ += count;
			}

			void resize (size_type n, value_type val = value_type())
			{
				if (n < size())
					erase(__begin_ + n, __end_);
				else
					insert(end(), n, val);
			}

			void reserve (size_type n)
			{
				if (n > capacity())
					realloc(n);
			}

			void push_back (const value_type &val)
			{
				insert(end(), val);
			}

			void swap (vector &x)
			{
				std::swap(__begin_, x.__begin_);
				std::swap(__end_, x.__end_);
				std::swap(__end_cap_, x.__end_cap_);
				std::swap(__alloc_, x.__alloc_);
			}
	};

	template <class T, class Alloc>
	void swap (vector<T, Alloc> &x, vector<T, Alloc> &y)
	{
		x.swap(y);
	}

	template<class T, class Alloc >
	bool operator == (const std::vector<T, Alloc> &lhs, const std::vector<T, Alloc> &rhs)
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template<class T, class Alloc>
	bool operator != (const std::vector<T, Alloc> &lhs, const std::vector<T, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}
}