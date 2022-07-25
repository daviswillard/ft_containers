#ifndef PROTECTED_VEC_H
# define PROTECTED_VEC_H

# include "base_vec.h"

namespace ft
{
	template <class T, class Alloc>
	bool	vector<T, Alloc>::Buy(size_type N)
	{
		First = 0, Last = 0, End = 0;
		if (N == 0)
			return false;
		else
		{
			First = Mybase::Alval.allocate(N, nullptr);
			Last = First;
			End = First + N;
			return true;
		}
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::Clear()
	{
		if (First != 0)
		{
			Destroy(First, Last);
			Mybase::Alval.deallocate(First, End - First);
		}
		First = 0, Last = 0, End = 0;
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::Destroy(pointer F, pointer L)
	{
		for (;F != L; ++F)
		{
			Mybase::Alval.destroy(F);
		}
	}

	template <class T, class Alloc>
	template <class It>
	typename vector<T, Alloc>::pointer vector<T, Alloc>::Ucopy(It F, It L, pointer Q)
	{
		pointer Qs = Q;
		try
		{
			for (; F != L; ++Q, ++F)
				Mybase::Alval.construct(Q, *F);
		}
		catch (...)
		{
			Destroy(Qs, Q);
			throw;
		}
		return Q;
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::pointer vector<T, Alloc>::Ufill(pointer Q, size_type N, const T &X)
	{
		pointer Qs = Q;
		try
		{
			for (; 0 < N; --N, ++Q)
				Mybase::Alval.construct(Q, X);
		}
		catch (...)
		{
			Destroy(Qs, Q);
			throw;
		}
		return Q;
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::Xlen() const
	{
		throw std::length_error("vector<T> too long");
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::Xran() const
	{
		throw std::out_of_range("vector<T> subscript");
	}
}

#endif
