#pragma once

#include <memory>
#include "../iterator/iterator.h"
#include <stdexcept>

namespace ft
{
	template <bool>
	class vector_base_common
	{
	protected:
		inline vector_base_common() {}
		void throw_len_err() const;
		void throw_out_of_range() const;
	};

	template <bool b>
	void vector_base_common<b>::throw_len_err() const
	{
		throw std::length_error("vector");
	}

	template <bool b>
	void vector_base_common<b>::throw_out_of_range() const
	{
		throw std::out_of_range("vector");
	}

	template<class T, class A = std::allocator<T> >
		class vector : protected vector_base_common<true>
	{
	public:
		typedef A							allocator_type;
		typedef typename A::pointer			pointer;
		typedef typename A::const_pointer	const_pointer;
		typedef typename A::reference		reference;
		typedef typename A::const_reference	const_reference;
		typedef typename A::value_type		value_type;

		typedef ft::iterator<T>	iterator;
		typedef T1				const_iterator;
		typedef T2				size_type;
		typedef T3				difference_type;

		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		
		vector();
		explicit vector(const A& al);
		explicit vector(size_type n);
		vector(size_type n, const T& x);
		vector(size_type n, const T& x, const A& al);
		vector(const vector& x);
		template <class Iter>
			vector(Iter first, Iter last);
		template<class Iter>
			vector(Iter first, Iter last, const A& al);
	};
}