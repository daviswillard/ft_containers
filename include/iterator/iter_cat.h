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
	template <class C, class T, class Dist> inline
	C Iter_cat(const ft::iterator<C, T, Dist>& iter)
	{
		C x;
		return x;
	}

	template <class T> inline
	random_access_iterator_tag Iter_cat (const T)
	{
		random_access_iterator_tag x;
		return x;
	}


/*Overloaded Iter_cat functions helpful in vector implementation*/
	inline Int_iterator_tag Iter_cat(bool)
	{
		Int_iterator_tag X;
		return X;
	}

	inline Int_iterator_tag Iter_cat(char)
	{
		Int_iterator_tag X;
		return X;
	}

	inline Int_iterator_tag Iter_cat(signed char)
	{
		Int_iterator_tag X;
		return X;
	}

	inline Int_iterator_tag Iter_cat(unsigned char)
	{
		Int_iterator_tag X;
		return X;
	}

	inline Int_iterator_tag Iter_cat(wchar_t)
	{
		Int_iterator_tag X;
		return X;
	}

	inline Int_iterator_tag Iter_cat(short)
	{
		Int_iterator_tag X;
		return X;
	}

	inline Int_iterator_tag Iter_cat(unsigned short)
	{
		Int_iterator_tag X;
		return X;
	}

	inline Int_iterator_tag Iter_cat(int)
	{
		Int_iterator_tag X;
		return X;
	}

	inline Int_iterator_tag Iter_cat(unsigned int)
	{
		Int_iterator_tag X;
		return X;
	}

	inline Int_iterator_tag Iter_cat(long)
	{
		Int_iterator_tag X;
		return X;
	}

	inline Int_iterator_tag Iter_cat(unsigned long)
	{
		Int_iterator_tag X;
		return X;
	}
}

#endif
