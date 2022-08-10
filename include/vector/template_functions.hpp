#ifndef TEMPLATE_FUNCTIONS_HPP
# define TEMPLATE_FUNCTIONS_HPP

# include "base_vec.hpp"

namespace ft
{
	template<class T, class A>
	void	vector<T, A>::swap(const vector &X, const vector &Y)
	{
		X.swap(Y);
	}
}

#endif
