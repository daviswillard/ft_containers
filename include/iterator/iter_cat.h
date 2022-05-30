/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_cat.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:52:06 by dwillard          #+#    #+#             */
/*   Updated: 2022/05/30 20:03:09 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_CAT_H
# define ITER_CAT_H

# include "iterator.h"

namespace ft
{
	template <class C, class T, class Dist, class Ptr, class Ref >
		inline
		C Iter_cat(const iterator<C, T, Dist, Ptr, Ref>& iter)
		{
			C x;
			return x;
		}
}

#endif
