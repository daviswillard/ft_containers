#ifndef CONSTRUCTORS_VEC_H
# define CONSTRUCTORS_VEC_H

# include "base_vec.h"

namespace ft
{
	template <class T, class Al>
	vector<T, Al>::vector(): Mybase()
	{
		Buy(0);
	}

	template <class T, class Al>
	vector<T, Al>::vector(const A& Alloc): Mybase(Alloc)
	{
		Buy(0);
	}

	template <class T, class Al>
	vector<T, Al>::vector(size_type N): Mybase()
	{
		if (Buy(N))
			Last = Ufill(First, N, T());
	}

	template <class T, class Al>
	vector<T, Al>::vector(size_type N, const T& V): Mybase()
	{
		if (Buy(N))
			Last = Ufill(First, N, V);
	}

	template <class T, class Al>
	vector<T, Al>::vector(size_type N, const T& V, const A& Alloc): Mybase()
	{
		if (Buy(N))
			Last = Ufill(First, N, V);
	}

	template <class T, class Al>
	vector<T, Al>::vector(const Myt& X): Mybase(X.Alval)
	{
		if (Buy(X.size()))
			Last = Ucopy(X.begin(), X.end(), First);
	}

	template <class T, class Al>
	template <class It>
	vector<T, Al>::vector(It F, It L): Mybase()
	{
		Construct(F, L, Iter_cat(F));
	}

	template <class T, class Al>
	template <class It>
	vector<T, Al>::vector(It F, It L, const A& Alloc)
	: Mybase(Alloc)
	{
		Construct(F, L, Iter_cat(F));
	}

	template<class T, class Al>
	template<class It>
	void vector<T, Al>::Construct(It F, It L, Int_iterator_tag)
	{
		size_type N = (size_type)F;
		if (Buy(N))
			L = Ufill(F, N, (T)L);
	}

	template <class T, class Al>
	template<class It>
	void	vector<T, Al>::Construct(It F, It L, input_iterator_tag)
	{
		Buy(0);
		insert(begin(), F, L);
	}

	template <class T, class Al>
	vector<T, Al>::~vector()
	{
		Clear();
	}
}

#endif
