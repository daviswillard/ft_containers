/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adv_dist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:40:08 by dwillard          #+#    #+#             */
/*   Updated: 2022/06/03 17:02:05 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADV_DIST_H
# define ADV_DIST_H

# include "iterator.h"

/*advance*/

namespace ft
{
	template <class RanIt>
		inline
		void advance(RanIt& iter,
				typename ft::iterator_traits<RanIt>::difference_type _N, random_access_iterator_tag)
		{
			iter += _N;
		}

	template <class RanIt>
		inline
		typename ft::iterator_traits<RanIt>::difference_type
		distance(RanIt _first, RanIt _last, random_access_iterator_tag)
		{
			return _last - _first;
		}

	template <class It, class D> inline
	void distance_tree(It F, It L, D & N)
	{
		for (; F != L; ++F)
		{
			++N;
		}
	}

}

#endif
