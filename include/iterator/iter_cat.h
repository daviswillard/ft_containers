/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_cat.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:52:06 by dwillard          #+#    #+#             */
/*   Updated: 2022/06/01 18:58:48 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_CAT_H
# define ITER_CAT_H

/*These two functions are needed to determine iterator type*/

#include "base.h"
#include "iterator_tag.h"

namespace ft
{
	template <class C, class T, class Dist>
		inline
		C Iter_cat(const ft::iterator<C, T, Dist>& iter)
		{
			C x;
			return x;
		}
	template <class T> inline
		random_access_iterator_tag Iter_cat (const T *) {
			random_access_iterator_tag x;
			return x;
		}
}

#endif
