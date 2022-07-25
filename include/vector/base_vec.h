#ifndef BASE_VEC_H
#define BASE_VEC_H

# include <memory>
# include <stdexcept>
# include "../iterator/iterator.h"

namespace ft
{
	template <class T, class A>
	class Vector_val
	{
	protected:
		explicit Vector_val(A Al = A()): Alval(Al)
		{
		}
		typedef typename A::template rebind<T>::
				other Alty;
		Alty Alval;
	};

	template <class T, class Ax = std::allocator<T> >
	class vector: public Vector_val<T, Ax>
	{
	public:
		typedef vector<T, Ax> 								Myt;
		typedef Vector_val<T, Ax>							Mybase;
		typedef typename Mybase::Alty						A;
		typedef A 											allocator_type;
		typedef typename A::size_type						size_type;
		typedef typename A::difference_type					difference_type;
		typedef typename A::pointer							Tptr;
		typedef typename A::const_pointer					Ctptr;
		typedef Tptr										pointer;
		typedef Ctptr										const_pointer;
		typedef typename A::reference						reference;
		typedef typename A::const_reference					const_reference;
		typedef typename A::value_type						value_type;
		typedef random_access_iterator<value_type,
				difference_type, Tptr,
				reference, Tptr, reference>					iterator;
		typedef random_access_iterator<value_type,
				difference_type, Ctptr,
				const_reference, Tptr, reference>			const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

		vector();
		explicit vector(const A& Al);
		explicit vector(size_type N);
		vector(size_type N, const T& V);
		vector(size_type N, const T& V, const A& Al);
		vector(const Myt& X);

		template <class It>
		vector(It First, It Last);

		template <class It>
		vector(It First, It Last, const A& Al);

		template <class It>
		void	Construct(It First, It Last, Int_iterator_tag);

		template<class It>
		void	Construct(It First, It Last, input_iterator_tag);

		~vector();

		Myt& operator= (const Myt& rhs)
		{
			if (this == rhs)
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
				if (But(rhs.size()))
					Last = Ucopy(rhs.begin, rhs.end(), First);
			}
			return *this;
		}

		void	reserve(size_type N)
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


	protected:
		bool	Buy(size_type N);
		void	Clear();
		void	Destroy(pointer F, pointer L);

		template <class It>
		pointer Ucopy(It F, It L, pointer Q);
		pointer Ufill(pointer Q, size_type N, const T &X);
		void	Xlen() const;
		void	Xran() const;

		pointer First;
		pointer Last;
		pointer End;
	};
}

# include "protected_vec.h"

#endif //BASE_VEC_H
