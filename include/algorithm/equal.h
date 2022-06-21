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

#pragma once

namespace ft
{
	template <class InIt1, class InIt2>
		inline bool equal(InIt1 first, InIt1 last, InIt2 ref)
	{
		for (int i = 0; first < last; i++)
			if (!(*(first + i) == *(ref + i)))
				return false;
		return true;
	}

	template <class InIt1, class InIt2, class BinaryPredicate>
		inline bool equal(InIt1 first, InIt1 last,
		InIt2 ref, BinaryPredicate p)
	{
		for (; first != last; ++first, ++ref)
			if (!p(*first, *ref))
				return false;
		return true;
	}
}
