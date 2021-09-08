#pragma once

#include "vector.hpp"

namespace ft
{
	template < class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef Container container_type;
			typedef typename Container::value_type value_type;
			typedef typename Container::size_type size_type;
		
		protected:
			container_type __c;

		public:

		// ========================== CONSTRUCTOR & DESTRUCTOR ========================== //

			explicit stack(const Container &cont = Container()) : __c(cont) {};
			~stack() {};

		// ========================== MEMBER FUNCTIONS ========================== //

		// ---------------- ACCESS / INFO ---------------- //

		bool empty(void) const { return (__c.empty()); }

		size_type size() const { return (__c.size()); }

		value_type &top() { return (__c.back()); }
		const value_type &top() const { return (__c.back()); }

		template <class T1, class Container1>
		friend bool operator == (const stack<T1,Container1> &lhs, const stack<T1,Container1> &rhs);

		template <class T1, class Container1>
		friend bool operator < (const stack<T1,Container1> &lhs, const stack<T1,Container1> &rhs);

		// ---------------- MODIFIERS ---------------- //

		void pop(void) { __c.pop_back(); };

		void push (const value_type &val) { __c.push_back(val); };
	};

	template <class T, class Container>
	bool operator == (const stack<T,Container> &lhs, const stack<T,Container> &rhs)
	{
		return (lhs.__c == rhs.__c);
	}

	template <class T, class Container>
	bool operator < (const stack<T,Container> &lhs, const stack<T,Container> &rhs)
	{
		return (lhs.__c < rhs.__c);
	}

	template <class T, class Container>
	bool operator != (const stack<T,Container> &lhs, const stack<T,Container> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Container>
	bool operator <= (const stack<T,Container> &lhs, const stack<T,Container> &rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T, class Container>
	bool operator > (const stack<T,Container> &lhs, const stack<T,Container> &rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Container>
	bool operator >= (const stack<T,Container> &lhs, const stack<T,Container> &rhs)
	{
		return (!(lhs < rhs));
	}
}
