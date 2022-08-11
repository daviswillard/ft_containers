#ifndef BASE_VEC_HPP
# define BASE_VEC_HPP

# include <memory>
# include <stdexcept>
# include "../iterator/iterator.hpp"

namespace ft
{
	template <class T, class A>
	class Vector_val
	{
	protected:
		Vector_val(A Al = A()): Alval(Al)
		{
		}
		typedef typename A::
		template rebind<T>::other Alty;
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

		~vector();

		A 						get_allocator() const;
		Myt&					operator= (const Myt& rhs);
		size_type				capacity() const;

		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;

		void					resize(size_type N);
		void					resize(size_type N, T X);
		void					reserve(size_type N);
		size_type				size() const;
		size_type				max_size() const;
		bool 					empty() const;

		const_reference			at(size_type n) const;
		reference 				at(size_type n);
		const_reference			operator[](size_type n) const;
		reference				operator[](size_type n);
		reference				front();
		const_reference			front() const;
		reference				back();
		const_reference			back() const;
		void					push_back(const T& X);
		void					pop_back();

		template<class It>
		void					assign(It First, It Last);
		void					assign(size_type N, const T& X);

		iterator				insert(iterator P, const T& X);
		void					insert(iterator P, size_type M, const T& X);
		template <class It>
		void					insert(iterator P, It First, It Last);

		iterator				erase(iterator P);
		iterator				erase(iterator First, iterator Last);
		void					clear();

		void					swap(Myt& X);
		void 					swap(const vector &X, const vector& Y);

	protected:
		template <class It>
		void	Construct(It First, It Last, Int_iterator_tag);

		template<class It>
		void	Construct(It First, It Last, input_iterator_tag);

		template <class It>
		void	Insert(iterator P, It First, It Last, Int_iterator_tag);
		template <class It>
		void	Insert(iterator P, It First, It Last, input_iterator_tag);
		template <class It>
		void	Insert(iterator P, It First, It Last, forward_iterator_tag);

		bool	Buy(size_type N);
		void	Clear();
		void	Destroy(pointer First, pointer Last);

		template<class It>
		void	Assign(It First, It Last, Int_iterator_tag);
		template<class It>
		void	Assign(It First, It Last, input_iterator_tag);

		bool 	Eq(const Myt& X) const;
		bool	Lt(const Myt& X) const;

		template <class It>
		pointer ItCopy(It First, It Last, pointer Ptr);
		pointer Ufill(pointer Q, size_type N, const T &X);
		void	Xlen() const;
		void	Xran() const;

		pointer First;
		pointer Last;
		pointer End;
	};

	template<class T, class allocator_type> inline
	bool operator==(const vector<T, allocator_type>& X, const vector<T, allocator_type>& Y)
	{
		return (X.size() == Y.size() && equal(X.begin(), X.end(), Y.begin()));
	}

	template<class T, class allocator_type> inline
	bool operator!=(const vector<T, allocator_type>& X, const vector<T, allocator_type>& Y)
	{
		return (!(X == Y));
	}

	template<class T, class allocator_type> inline
	bool operator<(const vector<T, allocator_type>& X, const vector<T, allocator_type>& Y)
	{
		return (lexicographical_compare(X.begin(), X.end(), Y.begin(), Y.end()));
	}

	template<class T, class allocator_type> inline
	bool operator>(const vector<T, allocator_type>& X, const vector<T, allocator_type>& Y)
	{
		return (Y < X);
	}

	template<class T, class allocator_type> inline
	bool operator>=(const vector<T, allocator_type>& X, const vector<T, allocator_type>& Y)
	{
		return (!(X < Y));
	}

	template<class T, class allocator_type> inline
	bool operator<=(const vector<T, allocator_type>& X, const vector<T, allocator_type>& Y)
	{
		return (!(Y < X));
	}
}

# include "constructors_vec.hpp"
# include "protected_vec.hpp"
# include "funcs.hpp"
# include "sequence_access.hpp"
# include "template_functions.hpp"

#endif //BASE_VEC_HPP
