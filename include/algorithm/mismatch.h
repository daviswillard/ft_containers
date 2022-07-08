/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mismatch.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:52:37 by dwillard          #+#    #+#             */
/*   Updated: 2022/07/08 15:52:56 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISMATCH_H
#define MISMATCH_H

#include "../utils/pair.h"

namespace ft
{
	template<class InIt1, class InIt2>
	inline
	ft::pair<InIt1, InIt2> mismatch(InIt1 F, InIt1 L, InIt2 X) {
		for (; F != L && *F == *X; ++F, ++X);
		return (ft::pair<InIt1, InIt2>(F, X));
	}

	template<class InIt1, class InIt2, class Pr>
	inline
	ft::pair<InIt1, InIt2> mismatch(InIt1 F, InIt1 L, InIt2 X, Pr P) {
		for (; F != L && P(*F, *X); ++F, ++X);
		return (ft::pair<InIt1, InIt2>(F, X));
	}
}

#endif
