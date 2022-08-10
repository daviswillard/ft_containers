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

#include "mismatch.hpp"

namespace ft
{
	template <class InIt1, class InIt2>
		inline bool equal(InIt1 first, InIt1 last, InIt2 ref)
	{
		return ft::mismatch(first, last, ref).first == last;
	}

	template <class InIt1, class InIt2, class BinaryPredicate>
		inline bool equal(InIt1 first, InIt1 last,
		InIt2 ref, BinaryPredicate p)
	{
		return ft::mismatch(first, last, ref, p).first == last;
	}
}
