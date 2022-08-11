#ifndef FT_CONTAINERS_STACK_HPP
#define FT_CONTAINERS_STACK_HPP

#include <iostream>
#include <deque>
#include "../vector/vector.hpp"

namespace ft {

	template<class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		typedef Container						container_type;
		typedef typename Container::value_type	value_type;
		typedef typename Container::size_type	size_type;

		stack();
		explicit stack(const container_type& cont);
		~stack();
		stack& operator=(const stack& other);

		value_type& top();
		const value_type& top() const;

		bool empty() const;
		size_type size() const;

		void push(const value_type& x);
		void pop();

		bool operator== (const stack<T,Container>& rhs);
		bool operator!= (const stack<T,Container>& rhs);
		bool operator< (const stack<T,Container>& rhs);
		bool operator<= (const stack<T,Container>& rhs);
		bool operator> (const stack<T,Container>& rhs);
		bool operator>= (const stack<T,Container>& rhs);

	protected:
		Container container;
		bool Eq(const stack<T, Container>& X) const;
		bool Lt(const stack<T, Container>& X) const;
	};

}
#include "stack_capacity.hpp"
#include "stack_protected.hpp"
#include "stack_element_access.hpp"
#include "stack_member_functions.hpp"
#include "stack_modifiers.hpp"
#include "stack_non_member_functions.hpp"

#endif //FT_CONTAINERS_STACK_HPP
