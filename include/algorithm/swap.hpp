#ifndef SWAP_HPP
# define SWAP_HPP

namespace ft
{
	template <class T> inline
	void swap(T& X, T& Y)
	{
		T tmp = X;
		X = Y;
		Y = tmp;
	}
}

#endif //SWAP_HPP
