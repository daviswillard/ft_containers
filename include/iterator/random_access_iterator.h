/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:39:09 by dwillard          #+#    #+#             */
/*   Updated: 2022/06/17 15:36:01 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator.h"

namespace ft
{
	template	<class Type, class Dist, class Ptr, class Ref,
				class Ptr_const, class Ref_const>
	class random_access_iterator :
		public ft::iterator	<random_access_iterator_tag,
							Type, Dist, Ptr, Ref>
	{
	protected:
		Ptr	current;
	public:
		typedef	random_access_iterator<Type, Dist, Ptr, Ref,
										Ptr_const, Ref_const>	RanIt;
		random_access_iterator()
		{

		}
		explicit random_access_iterator(const Ptr& p): current(p)
		{

		}
		explicit random_access_iterator
			(const random_access_iterator<Type, Dist, Ptr, Ref,
										Ptr_const, Ref_const>& other):
			current(other.base)
		{

		}

		~random_access_iterator()
		{

		}

	};
}
