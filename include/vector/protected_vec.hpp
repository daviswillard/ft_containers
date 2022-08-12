#ifndef PROTECTED_VEC_HPP
# define PROTECTED_VEC_HPP

# include "base_vec.hpp"
# include "../algorithm/equal.hpp"
# include "../algorithm/lexicographical_compare.hpp"

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
			First = Mybase::Alval.allocate(N);
			Last = First;
			End = First + N;
			return true;
		}
	}

	template<class T, class Alloc>
	template<class It>
	void vector<T, Alloc>::Construct(It F, It L, Int_iterator_tag)
	{
		size_type N = (size_type)F;
		if (Buy(N))
			Last = Ufill(First, N, (T)L);
	}

	template <class T, class Alloc>
	template<class It>
	void	vector<T, Alloc>::Construct(It F, It L, input_iterator_tag)
	{
		Buy(0);
		insert(begin(), F, L);
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
	typename vector<T, Alloc>::pointer vector<T, Alloc>::ItCopy(It F, It L, pointer Ptr)
	{
		pointer ptr_copy = Ptr;
		try
		{
			for (; F != L; ++Ptr, ++F)
				Mybase::Alval.construct(Ptr, *F);
		}
		catch (...)
		{
			Destroy(ptr_copy, Ptr);
			throw;
		}
		return Ptr;
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::pointer vector<T, Alloc>::Ufill(pointer Q, size_type N, const T& X)
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

	template<class T, class Alloc>
	template <class It>
	void vector<T, Alloc>::Assign(It F, It L, Int_iterator_tag) {
		assign((size_type)F, (T)L);
	}

	template<class T, class Alloc>
	template<class It>
	void vector<T, Alloc>::Assign(It F, It L, input_iterator_tag) {
		erase(begin(), end());
		insert(begin(), F, L);
	}

	template <class T, class Alloc>
	template <class It>
	void    vector<T, Alloc>::Insert(iterator P, It F, It L, Int_iterator_tag) {
		insert(P, (size_type)F, (T)L);
	}

	template <class T, class Alloc>
	template <class It>
	void    vector<T, Alloc>::Insert(iterator P, It F, It L, input_iterator_tag) {
		for (; F != L; ++P, ++F) {
			P = insert(P, *F);
		}
	}

	template <class T, class Alloc>
	template <class It>
	void    vector<T, Alloc>::Insert(iterator P, It F, It L, forward_iterator_tag)
	{
		size_type	M = 0;
		Distance(F, L, M);
		size_type	N = capacity();
		if (M == 0)
		{
			;
		}
		else if (max_size() - size() < M)
		{
			Xlen();
		}
		else if (size() + M > N)
		{
			N = max_size() - N / 2 < N ? 0 : N / 2;
			if (N < size() + M)
				N = size() + M;
			pointer new_first = Mybase::Alval.allocate(N,  NULL);
			pointer new_last;
			try
			{
				new_last = ItCopy(begin(), P, new_first);
				new_last = ItCopy(F, L, new_last);
				ItCopy(P, end(), new_last);
			}
			catch (...)
			{
				Destroy(new_first, new_last);
				Mybase::Alval.deallocate(new_first, N);
				throw;
			}
			if (First)
			{
				Destroy(First, Last);
				Mybase::Alval.deallocate(First, End - First);
			}
			End = new_first + N;
			Last = new_first + size() + M;
			First = new_first;
		}
		else if (M > (size_type)(end() - P))
		{
			ItCopy(P, end(), P.base() + M);
			It Mid = F;
			ft::advance(Mid, end() - P);
			try
			{
				ItCopy(Mid, L, Last);
			}
			catch (...)
			{
				Destroy(P.base() + M, Last + M);
				throw;
			}
			Last += M;
			std::copy(F, Mid, P);
		}
		else if (M > 0)
		{
			iterator end = this->end();
			Last = ItCopy(end, end - M, Last);
			std::copy_backward(P, end - M, end);
			std::copy(F, L, P);
		}
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
