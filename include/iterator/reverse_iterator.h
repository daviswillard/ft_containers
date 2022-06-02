/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:44:44 by dwillard          #+#    #+#             */
/*   Updated: 2022/06/01 19:58:01 by dwillard         ###   ########.fr       */
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
		typedef RanIt				iterator_type;
		typedef typename ft::iterator_traits<RanIt>::difference_type	difference_type;
		typedef typename ft::iterator_traits<RanIt>::reference			reference;
		typedef typename ft::iterator_traits<RanIt>::pointer			pointer;

		reverse_iterator() : current() {}
		explicit reverse_iterator(RanIt __x) : current(__x) {}
		//adapt it
/*template <class _Up>
			_LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX14
			reverse_iterator(const reverse_iterator<_Up>& __u) : __t(__u.base()), current(__u.base()) {}
			template <class _Up>
			_LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX14
			reverse_iterator& operator=(const reverse_iterator<_Up>& __u)
			{ __t = current = __u.base(); return *this; }
			_LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX14
			_Iter base() const {return current;}
			_LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX14
			reference operator*() const {_Iter __tmp = current; return *--__tmp;}
			_LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX14
			pointer  operator->() const {return _VSTD::addressof(operator*());}
			_LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX14
			reverse_iterator& operator++() {--current; return *this;}
			_LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX14
			reverse_iterator  operator++(int) {reverse_iterator __tmp(*this); --current; return __tmp;}
			_LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX14
			reverse_iterator& operator--() {++current; return *this;}
			_LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX14
			reverse_iterator  operator--(int) {reverse_iterator __tmp(*this); ++current; return __tmp;}
			_LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX14
			reverse_iterator  operator+ (difference_type __n) const {return reverse_iterator(current - __n);}
			_LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX14
			reverse_iterator& operator+=(difference_type __n) {current -= __n; return *this;}
			_LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX14
			reverse_iterator  operator- (difference_type __n) const {return reverse_iterator(current + __n);}
			_LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX14
			reverse_iterator& operator-=(difference_type __n) {current += __n; return *this;}
			_LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX14
			reference         operator[](difference_type __n) const {return *(*this + __n);}
*/
		};
}
#endif
