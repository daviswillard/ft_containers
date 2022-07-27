#ifndef TEMPLATE_FUNCTIONS_H
# define TEMPLATE_FUNCTIONS_H

# include "base_vec.h"

namespace ft
{
	template<class T, class A>
	void	vector<T, A>::swap(const vector &X, const vector &Y)
	{
		X.swap(Y);
	}
}

#endif
