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
#define RAN_ITER_H

#include "iterator.h"

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
		explicit random_access_iterator
			(const random_access_iterator <Type, Dist, Ptr, Ref,
											Ptr_const, Ref_const>& other):
			current(other.base)
		{

		}

		~random_access_iterator()
		{

		}

		inline Ptr base() const
		{
			return current;
		}

		inline random_access_iterator& operator=(const RanIt& ref)
		{
			if (this != ref)
				this->current = ref->current;
			return *this;
		}

		inline Ref	operator*()
		{
			return *current;
		}

		inline const Ref operator*() const
		{
			return *current;
		}

	};
}

#endif
