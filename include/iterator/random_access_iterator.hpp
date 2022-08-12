/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:39:09 by dwillard          #+#    #+#             */
/*   Updated: 2022/06/17 16:48:45 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAN_ITER_H
# define RAN_ITER_H

namespace ft
{
	template <class Type, class Dist, class Ptr, class Ref,
					class Ptr_const, class Ref_const>
	class random_access_iterator :
	public iterator	<random_access_iterator_tag,
							Type, Dist, Ptr, Ref>
	{
	protected:
		Ptr	current;
	public:
		typedef	random_access_iterator<Type, Dist, Ptr, Ref,
										Ptr_const, Ref_const>	Myt;

		random_access_iterator()
		{
		}
		explicit random_access_iterator(const Ptr& p): current(p)
		{
		}
		random_access_iterator(const random_access_iterator<Type, Dist, Ptr, Ref,
				Ptr_const, Ref_const>& other)
		: current(other.base())
		{
		}

		template <class _T, class _D, class _Pt, class _Rt, class _Pt2, class _Rt2>
		random_access_iterator(const random_access_iterator<_T, _D, _Pt, _Rt, _Pt2, _Rt2> &X): current (X.base())
		{

		}

		inline Ptr base() const
		{
			return current;
		}

		inline random_access_iterator& operator=(const Myt& ref)
		{
			if (this != &ref)
				this->current = ref.current;
			return *this;
		}

		inline Ref	operator*() const
		{
			return *current;
		}

		inline Ptr operator->() const
		{
			return &**this;
		}

		inline Myt& operator++ () {
			++current;
			return *this;
		}

		inline Myt operator++ (int) {
			Myt temp = *this;
			++current;
			return temp;
		}

		inline Myt& operator+= (Dist n) {
			current += n;
			return *this;
		}

		inline Myt operator+ (Dist n) const {
			return Myt(current + n);
		}

		inline Myt& operator-= (Dist n) {
			current -= n;
			return *this;
		}

		inline Myt& operator-- () {
			--current;
			return *this;
		}

		inline Myt operator-- (int) {
			Myt temp = *this;
			--current;
			return temp;
		}


		inline Myt operator- (Dist n) const {
			return Myt(current - n);
		}

		inline Ref operator[] (Dist n) const {
			return *(*this + n);
		}

		inline bool operator< (const Myt& b) const {
			return (current < b.current);
		}

		inline bool operator> (const Myt& b) const {
			return (b < *this);
		}

		inline bool operator<= (const Myt& b) const {
			return !(b < *this);
		}

		inline bool operator>= (const Myt& b) const {
			return !(*this < b);
		}

		inline bool operator== (int Y) const
		{
			return current == (Ptr)Y;
		}

		inline bool operator== (const Myt& b) const {
			return (current == b.current);
		}

		inline bool operator!= (const Myt& b) const {
			return !(*this == b);
		}

		Dist operator- (const Myt& b) const {
			return current - b.current;
		}

	};

	template<class T, class D, class P, class R, class P2, class R2, class D2> inline
	random_access_iterator<T, D, P, R, P2, R2> operator+
						(D2 n, const ft::random_access_iterator<T, D, P, R, P2, R2>& y)
	{
		return (y + static_cast<D>(n));
	}

}

#endif
