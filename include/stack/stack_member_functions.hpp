#ifndef STACK_MEMBER_FUNCTIONS_HPP
#define STACK_MEMBER_FUNCTIONS_HPP

namespace ft
{
	// constructs the stack
	template<class T, class Container>
	stack<T, Container>::stack() : container() {}

	// constructs the stack
	template<class T, class Container>
	stack<T, Container>::stack(const container_type& cont) : container(cont) {}

	// destructs the stack
	template<class T, class Container>
	stack<T, Container>::~stack() {}

	// assigns values to the container adaptor
	template<class T, class Container>
	ft::stack<T, Container>& stack<T, Container>::operator=(const stack& other)
	{
		container = other.container;
		return *this;
	}
}

#endif // STACK_MEMBER_FUNCTIONS_HPP
