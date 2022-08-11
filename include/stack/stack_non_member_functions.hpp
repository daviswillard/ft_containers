#ifndef STACK_NON_MEMBER_FUNCTIONS_HPP
#define STACK_NON_MEMBER_FUNCTIONS_HPP

namespace ft
{

	template<class T, class Container>
	bool stack<T, Container>::operator== (const stack<T,Container>& rhs)
	{
		return this->Eq(rhs);
	}

	template<class T, class Container>
	bool stack<T, Container>::operator!= (const stack<T,Container>& rhs)
	{
		return (!(*this == rhs));
	}

	template<class T, class Container>
	bool stack<T, Container>::operator< (const stack<T,Container>& rhs)
	{
		return this->Lt(rhs);
	}

	template<class T, class Container>
	bool stack<T, Container>::operator<= (const stack<T,Container>& rhs)
	{
		return !this->Lt(rhs);
	}


	template<class T, class Container>
	bool stack<T, Container>::operator> (const stack<T,Container>& rhs)
	{
		return rhs.Lt(*this);
	}

	template<class T, class Container>
	bool stack<T, Container>::operator>= (const stack<T,Container>& rhs)
	{
		return !rhs.Lt(*this);
	}


//	template<class T, class Container>
//	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
//	{
//		return (lhs == rhs);
//	}
//
//	template<class T, class Container>
//	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
//	{
//		return (!(lhs == rhs));
//	}
//
//	template<class T, class Container>
//	bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
//	{
//		return (lhs < rhs);
//	}
//
//	template<class T, class Container>
//	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
//	{
//		return (lhs <= rhs);
//	}
//
//
//	template<class T, class Container>
//	bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
//	{
//		return (lhs > rhs);
//	}
//
//	template<class T, class Container>
//	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
//	{
//		return (lhs >= rhs);
//	}
}

#endif // STACK_NON_MEMBER_FUNCTIONS_HPP
