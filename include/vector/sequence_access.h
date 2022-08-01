#ifndef SEQUENCE_ACCESS_H
# define SEQUENCE_ACCESS_H

# include "base_vec.h"
# include "../iterator/iterator.h"
# include "../algorithm/fill.h"

namespace ft
{
	template <typename T, class Al>
	typename vector<T, Al>::reference vector<T, Al>::operator[] (size_type n) {
		return (*(begin() + n));
	}

	template <typename T, class Al>
	typename vector<T, Al>::const_reference vector<T, Al>::operator[] (size_type n) const {
		return (*(begin() + n));
	}

	template <typename T, class Al>
	typename vector<T, Al>::reference vector<T, Al>::at(size_type n) {
		if (n >= (u_int64_t)(Last - First))
			throw std::out_of_range("vector");
		return (*(begin() + n));
	}

	template <typename T, class Al>
	typename vector<T, Al>::const_reference vector<T, Al>::at(size_type n) const {
		if (n >= Last - First)
			throw std::out_of_range("vector");
		return (*(begin() + n));
	}

	template <typename T, class Al>
	typename vector<T, Al>::reference vector<T, Al>::front() {
		return *(begin());
	}

	template <typename T, class Al>
	typename vector<T, Al>::const_reference vector<T, Al>::front() const {
		return *(begin());
	}

	template <typename T, class Al>
	typename vector<T, Al>::reference vector<T, Al>::back() {
		return *(end() - 1);
	}

	template <typename T, class Al>
	typename vector<T, Al>::const_reference vector<T, Al>::back() const {
		return *(end() - 1);
	}

	template <typename T, class Al>
	void vector<T, Al>::clear() {
		erase(begin(), end());
	}

	template <typename T, class Al>
	typename vector<T, Al>::iterator vector<T, Al>::insert(iterator P, const T &X) {
		size_type off = size() == 0 ? 0 : P - begin();
		insert(P, 1, X);
		return (begin() + off);
	}

	template <typename T, class Al>
	void vector<T, Al>::insert(iterator P, size_type M, const T &X) {
		T Tx = X;
		size_type N = capacity();
		if (M == 0) {
			;
		}
		else if (M > max_size() - size())
		{
			Xlen();
		}
		else if (N < size() + M)
		{
			N = max_size() - N / 2 < N ? 0 : N + N / 2;
			if (N < size() + M)
				N = size() + M;
			pointer new_first = Mybase::Alval.allocate(N, nullptr);
			pointer new_last;
			try
			{
				new_last = Ucopy(begin(), P, new_first);
				new_last = Ufill(new_last, M, Tx);
				Ucopy(P, end(), new_last);
			}
			catch (...)
			{
				Destroy(new_first, new_last);
				Mybase::Alval.deallocate(new_first, N);
				throw;
			}
			if (First)
			{
				Clear();
			}
			First = new_first;
			Last = new_first + size() + M;
			End = new_first + N;
		}
		else if ((size_type) (end() - P) < M)
		{
			Ucopy(P, end(), P.base() + M);
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
			Last = Ucopy(end - M, end, Last);
			std::copy_backward(P, end - M, end);
			ft::fill(P, P + M, Tx);
		}
	}

	template <typename T, class Al>
	template<class InputIt>
	void vector<T, Al>::insert(iterator P, InputIt F, InputIt L) {
		Insert(P, F, L, Iter_cat(F));
	}

// Removes the element at P
	template <typename T, class Al>
	typename vector<T, Al>::iterator vector<T, Al>::erase(iterator P) {
		std::copy(P + 1, end(), P);
		Destroy(Last - 1, Last);
		--Last;
		return (P);
	}


// Removes the elements in the range
	template <typename T, class Al>
	typename vector<T, Al>::iterator vector<T, Al>::erase(iterator F, iterator L) {
		if (F != L) {
			pointer new_last = std::copy(L, end(), F.base());
			Destroy(new_last, Last);
			Last = new_last;
		}
		return F;
	}

	template <typename T, class Al>
	void vector<T, Al>::push_back(const T &X) {
		insert(end(), X);
	}

	template <typename T, class Al>
	void vector<T, Al>::pop_back() {
		erase(end() - 1);
	}

	template <typename T, class Al>
	void vector<T, Al>::swap(vector& X) {
		if (Mybase::Alval == X.Alval) {
			std::swap(First, X.First);
			std::swap(Last, X.Last);
			std::swap(End, X.End);
		} else {
			Myt temp = *this;
			*this = X;
			X = temp;
		}
	}

	template<typename T, class Al>
	typename vector<T, Al>::A vector<T, Al>::get_allocator() const {
		return Mybase::Alval;
	}

	template<typename T, class Al>
	void vector<T, Al>::assign(size_type N, const T& X) {
		T x = X;

		erase(begin(), end());
		insert(begin(), N, x);
	}

	template<typename T, class Al>
	template <class It>
	void vector<T, Al>::Assign(It F, It L, Int_iterator_tag) {
		assign((size_type)F, (T)L);
	}

	template<typename T, class Al>
	template<class It>
	void vector<T, Al>::Assign(It F, It L, input_iterator_tag) {
		erase(begin(), end());
		insert(begin(), F, L);
	}

	template<typename T, class Al>
	template<class It>
	void vector<T, Al>::assign(It F, It L) {
		Assign(F, L, Iter_cat(F));
	}

	template <typename T, class Alloc>
	template <class It>
	void    vector<T, Alloc>::Insert(iterator P, It F, It L, Int_iterator_tag) {
		insert(P, (size_type)F, (T)L);
	}

	template <typename T, class Alloc>
	template <class It>
	void    vector<T, Alloc>::Insert(iterator P, It F, It L, input_iterator_tag) {
		for (; F != L; ++P, ++F) {
			P = insert(P, *F);
		}
	}

	template <typename T, class Alloc>
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
		else if (M > max_size() - size())
		{
			throw std::length_error("vector");
		}
		else if (size() + M > N)
		{
			N = max_size() - N / 2 < N ? 0 : N * 2;
			if (N < size() + M)
				N = size() + M;
			pointer new_first = Mybase::Alval.allocate(N, nullptr);
			pointer new_last;
			try
			{
				new_last = Ucopy(begin(), P, new_first);
				new_last = Ucopy(F, L, new_last);
				Ucopy(P, end(), new_last);
			}
			catch (...)
			{
				Destroy(new_first, new_last);
				Mybase::Alval.deallocate(new_first, N);
				throw;
			}
			if (First)
			{
				Clear();
			}
			End = new_first + N;
			Last = new_first + size() + M;
			First = new_first;
		}
		else if (M > (size_type)(end() - P))
		{
			Ucopy(P, end(), P.base() + M);
			It Mid = F;
			advance(Mid, end() - P);
			try
			{
				Ucopy(Mid, L, Last);
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
			Last = Ucopy(end, end - M, Last);
			std::copy_backward(P, end - M, end);
			std::copy(F, L, P);
		}
	}
}

#endif //SEQUENCE_ACCESS_H
