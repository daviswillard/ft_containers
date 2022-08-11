/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:44:44 by dwillard          #+#    #+#             */
/*   Updated: 2022/06/04 17:58:31 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"
# include "base.hpp"

namespace ft
{
	template <class RanIt>
		class reverse_iterator : public iterator<
				typename ft::iterator_traits<RanIt>::iterator_category,
				typename ft::iterator_traits<RanIt>::value_type,
				typename ft::iterator_traits<RanIt>::difference_type,
				typename ft::iterator_traits<RanIt>::pointer,
				typename ft::iterator_traits<RanIt>::reference>
	{
	public:
		typedef reverse_iterator<RanIt>									Myt;
		typedef RanIt													iterator_type;
		typedef typename ft::iterator_traits<RanIt>::difference_type	Diff;
		typedef typename ft::iterator_traits<RanIt>::reference			reference;
		typedef typename ft::iterator_traits<RanIt>::pointer			pointer;

		/*Default constructor, copy constructors*/

		reverse_iterator()
		{
		}
		explicit reverse_iterator(RanIt _x) :
		current(_x)
		{
		}
		template <class U>
		explicit reverse_iterator(const reverse_iterator<U>& _u) :
		current(_u.base())
		{
		}
		RanIt base() const
		{
			return current;
		}


		/*Operators*/

		reference	operator*() const { RanIt tmp = current; return *--tmp; }
		pointer		operator->() const { return &**this; }
		Myt&		operator++() { --current; return *this; }
		Myt			operator++(int) { Myt tmp(*this); --current; return tmp; }
		Myt&		operator--() { ++current; return *this; }
		Myt			operator--(int) { Myt tmp(*this); ++current; return tmp; }
		Myt  		operator+ (Diff n) const { return Myt(current - n); }
		Myt& 		operator+=(Diff n) { current -= n; return *this; }
		Myt			operator- (Diff n) const { return Myt(current + n); }
		Myt&		operator-=(Diff n) { current += n; return *this; }
		reference	operator[](Diff n) const { return *(*this + n); }
		protected:
			RanIt current;
	};

	template <class It1, class It2>
		inline bool
		operator==(const reverse_iterator<It1>& x, const reverse_iterator<It2>& y) { return x.base() == y.base(); }
	template <class It1, class It2>
		inline bool
		operator<(const reverse_iterator<It1>& x, const reverse_iterator<It2>& y) { return x.base() > y.base(); }
	template <class It1, class It2>
		inline bool
		operator>(const reverse_iterator<It1>& x, const reverse_iterator<It2>& y) { return x.base() < y.base(); }
	template <class It1, class It2>
		inline bool
		operator!=(const reverse_iterator<It1>& x, const reverse_iterator<It2>& y) { return !(x.base() == y.base()); }
	template <class It1, class It2>
		inline bool
		operator<=(const reverse_iterator<It1>& x, const reverse_iterator<It2>& y) { return x.base() >= y.base(); }
	template <class It1, class It2>
		inline bool
		operator>=(const reverse_iterator<It1>& x, const reverse_iterator<It2>& y) { return x.base() <= y.base(); }
	template <class It1, class It2>
		inline typename reverse_iterator<It1>::Diff
		operator-(const reverse_iterator<It1> &x, const reverse_iterator<It2>& y) { return x.base() >= y.base(); }
}

#endif
