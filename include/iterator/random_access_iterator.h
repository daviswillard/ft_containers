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
	template	<class Type, class Dist, class Ptr, class Ref,
					class Ptr_const, class Ref_const>
	class random_access_iterator :
		public ft::iterator	<ft::random_access_iterator_tag,
								Type, Dist, Ptr, Ref>
	{
	protected:
		Ptr	current;
	public:
		typedef	random_access_iterator<	Type, Dist, Ptr, Ref,
										Ptr_const, Ref_const>	RanIt;
		random_access_iterator()
		{
		}
		explicit random_access_iterator(const Ptr& p): current(p)
		{
		}
		random_access_iterator
			(const random_access_iterator <Type, Dist, Ptr, Ref,
											Ptr_const, Ref_const>& other)
			: current(other.base())
		{
		}

		~random_access_iterator()
		{
		}
		typedef random_access_iterator<Type, Dist, Ptr, Ref,
			Ptr_const, Ref_const>								iterator;
		typedef typename iterator::distance_type				difference_type;
		typedef typename iterator::pointer 						pointer;
		typedef typename iterator::reference 					reference;

		inline Ptr base() const
		{
			return current;
		}

		inline random_access_iterator& operator=(const RanIt& ref)
		{
			if (this != &ref)
				current = ref.current;
			return *this;
		}

		inline Ref	operator*()
		{
			return *current;
		}

		inline Ref operator*() const
		{
			return *current;
		}

		inline random_access_iterator& operator+= (difference_type n) {
			current += n;
			return *this;
		}

		inline iterator& operator++ () {
			current++;
			return *this;
		}

		inline iterator operator++ (int) {
			iterator temp = *this;
			++current;
			return temp;
		}

		inline iterator operator+ (difference_type n) {
			iterator temp = *this;
			return (temp += n);
		}

		inline iterator& operator-= (difference_type n) {
			current -= n;
			return *this;
		}

		inline iterator& operator-- () {
			--current;
			return *this;
		}

		inline iterator operator-- (int) {
			iterator temp = *this;
			current--;
			return temp;
		}

		inline iterator operator- (difference_type n) const {
			iterator temp = *this;
			return (temp -= n);
		}

		inline difference_type operator- (const iterator& a) const {
			return (current - a.current);
		}

		inline reference operator[] (Dist n) const {
			return *(current + n);
		}

		inline bool operator< (const iterator& b) const {
			return (current < b.current);
		}

		inline bool operator> (const iterator& b) const {
			return (current > b.current);
		}

		inline bool operator<= (const iterator& b) const {
			return (current <= b.current);
		}

		inline bool operator>= (const iterator& b) const {
			return (current >= b.current);
		}

		inline bool operator== (const iterator& b) const {
			return (current == b.current);
		}

		inline bool operator!= (const iterator& b) const {
			return (current != b.current);
		}

	};

	template<class Type, class Dist, class Ptr, class Ref,
			class Ptr_const, class Ref_const> inline
	random_access_iterator<Type, Dist, Ptr, Ref, Ptr_const, Ref_const>
	        operator+ (Dist n,
					const random_access_iterator<Type, Dist, Ptr, Ref, Ptr_const, Ref_const>& y)
	{
		return (y + n);
	}

}

#endif
