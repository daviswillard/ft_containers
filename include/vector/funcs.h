#ifndef FUNCS_H
# define FUNCS_H

# include "base_vec.h"

namespace ft
{
	template <class T, class Al>
	typename vector<T, Al>::Myt& vector<T, Al>::operator=(const Myt& rhs)
	{
		if (this == &rhs)
			;
		else if (rhs.size() == 0)
			Clear();
		else if (rhs.size() <= size())
		{
			pointer Q = std::copy(rhs.begin(), rhs.end(), First);
			Destroy(Q, Last);
			Last = First + rhs.size();
		}
		else if (rhs.size() <= capacity())
		{
			const_iterator S = rhs.begin() + size();
			std::copy(rhs.begin(), S, First);
			Last = Ucopy(S, rhs.end(), Last);
		}
		else
		{
			Destroy(First, Last);
			Mybase::Alval.deallocate(First, End - First);
			if (Buy(rhs.size()))
				Last = Ucopy(rhs.begin(), rhs.end(), First);
		}
		return *this;
	}

	template <class T, class Al>
	void	vector<T, Al>::reserve(size_type N)
	{
		if (max_size() < N)
		Xlen();
		else if (capacity() < N)
		{
			pointer Q = Mybase::Alval.allocate(N, nullptr);
			try
		{
			Ucopy(begin(), end(), Q);
		}
		catch (...)
		{
		Mybase::Alval.deallocate(Q, N);
		throw;
		}
		if (First != 0)
		{
		Destroy(First, Last);
		Mybase::Alval.deallocate(First, End - First);
		}
		End = Q + N;
		Last = Q + size();
			First = Q;
		}
	}

	template <class T, class Al>
	typename vector<T, Al>::size_type	vector<T, Al>::capacity() const
	{
		return First == 0 ? 0 : End - First;
	}

	template <class T, class Al>
	typename vector<T, Al>::iterator	vector<T, Al>::begin()
	{
		return iterator(First);
	}

	template <class T, class Al>
	typename vector<T, Al>::const_iterator	vector<T, Al>::begin() const
	{
		return const_iterator(First);
	}

	template <class T, class Al>
	typename vector<T, Al>::iterator	vector<T, Al>::end()
	{
		return iterator(Last);
	}

	template <class T, class Al>
	typename vector<T, Al>::const_iterator	vector<T, Al>::end() const
	{
		return const_iterator(Last);
	}

	template <class T, class Al>
	typename vector<T, Al>::reverse_iterator	vector<T, Al>::rbegin()
	{
		return reverse_iterator(end());
	}

	template <class T, class Al>
	typename vector<T, Al>::const_reverse_iterator	vector<T, Al>::rbegin() const
	{
		return const_reverse_iterator(end());
	}

	template <class T, class Al>
	typename vector<T, Al>::reverse_iterator	vector<T, Al>::rend()
	{
		return reverse_iterator(begin());
	}

	template <class T, class Al>
	typename vector<T, Al>::const_reverse_iterator	vector<T, Al>::rend() const
	{
		return const_reverse_iterator(begin());
	}

	template <class T, class Al>
	void	vector<T, Al>::resize(typename vector<T, Al>::size_type N)
	{
		resize(N, T());
	}

	template <class T, class Al>
	void	vector<T, Al>::resize(typename vector<T, Al>::size_type N, T X)
	{
		if (size() < N)
			insert (end(), N - size(), X);
		else if (N < size())
			erase (begin() + N, end());
	}

	template <class T, class Al>
	typename vector<T, Al>::size_type	vector<T, Al>::size() const
	{
		return First == 0 ? 0 : Last - First;
	}

	template <class T, class Al>
	typename vector<T, Al>::size_type	vector<T, Al>::max_size() const
	{
		return Mybase::Alval.max_size();
	}

	template <class T, class Al>
	bool	vector<T, Al>::empty() const
	{
		return size() == 0;
	}
}

#endif
