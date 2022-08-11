/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_type.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:59:18 by dwillard          #+#    #+#             */
/*   Updated: 2022/06/01 19:10:22 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAL_TYPE_HPP
# define VAL_TYPE_HPP

# include "iterator_traits.hpp"

namespace ft
{
	/*These functions return a pointer to type T, instead of and object of type T*/

	template <class It> inline
	typename ft::iterator_traits<It>::value_type* Val_type(It)
	{
		return 0;
	}

	/*
	 * If compiler doesn't support partial template specialization, then:
	 *
	 * template <class C, class T, class D, class Pt, class Rt> inline
	 *		T* Val_type(ft::iterator, T, D, Pt, Rt)
	 *	{
	 *		return 0;
	 *	}
	 *
	 * template <class T> inline
	 *		T* Val_type(const T*)
	 *	{
	 *		return 0;
	 *	}
	 */
}

#endif
