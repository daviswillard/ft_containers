/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:26:56 by dwillard          #+#    #+#             */
/*   Updated: 2022/06/03 20:48:40 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_H
# define EQUAL_H

namespace ft
{
	template <class InpIter1, class InpIter2>
		inline bool equal(InpIter1 first, InpIter1 last, InpIter2 ref)
	{
		for (int i = 0; first < last; i++)
			if (!(*(first + i) == *(ref + i)))
				return false;
		return true;
	}

	template <class InpIter1, class InpIter2, class BinaryPredicate>
		inline bool equal(InpIter1 first, InpIter1 last,
		InpIter2 ref, BinaryPredicate p)
	{
		for (; first != last; ++first, ++ref)
			if (!p(*first, *ref))
				return false;
		return true;
	}

	template <class InpIter1, class InpIter2>
		inline bool lexicographical_compare(InpIter1 first, InpIter1 last,
											InpIter2 _first, InpIter2 _last)
	{
		for (; _first != _last; ++first, ++_first)
		{
			if (*first < *_first)
				return true;
			else if (*_first < *first)
				return false;
		}
		return first == last && _first != _last;
	}
}

#endif
