#ifndef SEQUENCE_ACCESS_HPP
# define SEQUENCE_ACCESS_HPP

# include "base_vec.hpp"
# include "../algorithm/algorithm.hpp"

namespace ft
{
	template <class T, class Alloc>
	typename vector<T, Alloc>::reference vector<T, Alloc>::operator[] (size_type n) {
		return (*(begin() + n));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[] (size_type n) const {
		return (*(begin() + n));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference vector<T, Alloc>::at(size_type n) {
		if (n >= size())
			Xran();
		return (*(begin() + n));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference vector<T, Alloc>::at(size_type n) const {
		if (n >= size())
			Xran();
		return (*(begin() + n));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference vector<T, Alloc>::front() {
		return *begin();
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference vector<T, Alloc>::front() const {
		return *begin();
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference vector<T, Alloc>::back() {
		return *(end() - 1);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference vector<T, Alloc>::back() const {
		return *(end() - 1);
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::clear() {
		erase(begin(), end());
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(iterator P, const T &X) {
		size_type off;
		if (size() == 0)
			off = 0;
		else
			off = P - begin();
		insert(P, (size_type)1, X);
		return (begin() + off);
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::insert(iterator P, size_type M, const T &X) {
		T Tx = X;
		size_type N = capacity();
		if (M == 0) {
			;
		}
		else if (max_size() - size() < M)
		{
			Xlen();
		}
		else if (N < size() + M)
		{
			N = (max_size() - N < N) ?
					0 : N + N;
			if (N < size() + M)
				N = size() + M;
			pointer new_first = Mybase::Alval.allocate(N);
			pointer new_last;
			try
			{
				new_last = ItCopy(begin(), P, new_first);
				new_last = Ufill(new_last, M, Tx);
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
		else if ((size_type) (end() - P) < M)
		{
			ItCopy(P, end(), P.base() + M);
			try
			{
				Ufill(Last, M - (end() - P), Tx);
			}
			catch (...)
			{
				Destroy(P.base() + M, Last + M);
				throw;
			}
			Last += M;
			ft::fill(P, end() - M, Tx);
		}
		else
		{
			iterator end = this->end();
			Last = ItCopy(end - M, end, Last);
			std::copy_backward(P, end - M, end);
			ft::fill(P, P + M, Tx);
		}
	}

	template <class T, class Alloc>
	template<class InputIt>
	void vector<T, Alloc>::insert(iterator P, InputIt F, InputIt L) {
		Insert(P, F, L, Iter_cat(F));
	}

// Removes element at P
	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator P) {
		std::copy(P + 1, end(), P);
		Destroy(Last - 1, Last);
		--Last;
		return (P);
	}


// Removes elements in the range
	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator F, iterator L) {
		if (F != L)
		{
			pointer new_last = std::copy(L, end(), F.base());
			Destroy(new_last, Last);
			Last = new_last;
		}
		return F;
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::push_back(const T &X) {
		insert(end(), X);
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::pop_back() {
		erase(end() - 1);
	}

	template <class T, class Alloc>
	void vector<T, Alloc>::swap(vector& X)
	{
		if (Mybase::Alval == X.Alval)
		{
			std::swap(First, X.First);
			std::swap(Last, X.Last);
			std::swap(End, X.End);
		}
		else
		{
			Myt temp = *this;
			*this = X, X = temp;
		}
	}

	template<class T, class Alloc>
	typename vector<T, Alloc>::allocator_type vector<T, Alloc>::get_allocator() const {
		return Mybase::Alval;
	}

	template<class T, class Alloc>
	void vector<T, Alloc>::assign(size_type N, const T& X) {
		T x = X;

		erase(begin(), end());
		insert(begin(), N, x);
	}

	template<class T, class Alloc>
	template<class It>
	void vector<T, Alloc>::assign(It F, It L) {
		Assign(F, L, ft::Iter_cat(F));
	}
}

#endif //SEQUENCE_ACCESS_HPP
