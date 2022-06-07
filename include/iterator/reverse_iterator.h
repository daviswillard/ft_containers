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

#ifndef REVERSE_ITERATOR_H
# define REVERSE_ITERATOR_H

# include "iterator.h"

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
	protected:
		RanIt current;
	public:
		typedef RanIt													iterator_type;
		typedef typename ft::iterator_traits<RanIt>::difference_type	difference_type;
		typedef typename ft::iterator_traits<RanIt>::reference			reference;
		typedef typename ft::iterator_traits<RanIt>::pointer			pointer;

		/*Default constructor, copy constructors*/

		reverse_iterator() : current() {}
		explicit reverse_iterator(RanIt _x) : current(_x) {}
		template <class U>
			reverse_iterator(const reverse_iterator<U>& _u) :
				current(_u.base()) {}
		template <class U>
			reverse_iterator& operator=(const reverse_iterator<U>& _u)
				{
					current = _u.base();
					return *this;
				}
		RanIt base() const
		{
			return current;
		}

		/*Operators*/

		reference		  operator*() const { RanIt tmp = current; return *--tmp; }
		pointer			  operator->() const { return &**this; }
		reverse_iterator& operator++() { --current; return *this; }
		reverse_iterator  operator++(int) { reverse_iterator tmp(*this); --current; return tmp; }
		reverse_iterator& operator--() { ++current; return *this; }
		reverse_iterator  operator--(int) { reverse_iterator tmp(*this); ++current; return tmp; }
		reverse_iterator  operator+ (difference_type n) const { return reverse_iterator(current - n); }
		reverse_iterator& operator+=(difference_type n) { current -= n; return *this; }
		reverse_iterator  operator- (difference_type n) const { return reverse_iterator(current + n); }
		reverse_iterator& operator-=(difference_type n) { current += n; return *this; }
		reference         operator[](difference_type n) const { return *(*this + n); }
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
		inline typename reverse_iterator<It1>::difference_type
		operator-(const reverse_iterator<It1> &x, const reverse_iterator<It2>& y) { return x.base() >= y.base(); }
}

#endif
