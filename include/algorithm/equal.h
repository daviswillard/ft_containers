/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:26:56 by dwillard          #+#    #+#             */
/*   Updated: 2022/05/29 19:53:38 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_H
# define EQUAL_H

template <class InpIter1, class InpIter2>
bool equal(InpIter1 first, InpIter1 last, InpIter2 ref)
{
	for (int i = 0; first < last; i++) {
		if (!(*(first + i) == *(ref + i)))
			return false;
	}
	return true;
}

#endif
