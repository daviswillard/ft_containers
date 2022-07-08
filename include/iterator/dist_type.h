/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_type.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:19:41 by dwillard          #+#    #+#             */
/*   Updated: 2022/06/17 15:10:13 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIST_TYPE_H
#define DIST_TYPE_H

#include "iterator.h"

namespace ft
{
	/*These functions return a pointer to type T, instead of and object of type T*/

	template <class It> inline
		typename ft::iterator_traits<It>::distance_type* Dist_type(It)
		{
			return 0;
		}

/*
 * If compiler doesn't support partial template specialization, then:
 *
 * template <class C, class T, class D, class Pt, class Rf> inline
 *		T* Dist_type(ft::iterator, T, D, Pt, Rt)
 *	{
 *		return 0;
 *	}
 *
 * template <class T> inline
 *		T* Dist_type(const T*)
 *	{
 *		return 0;
 *	}
 */
}

#endif
