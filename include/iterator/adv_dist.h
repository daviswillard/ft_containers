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

# include "iterator_traits.h"
# include "iterator_tag.h"

/*advance*/

namespace ft
{
	template<class InIt, class Distance> inline
	void	advance(InIt& I, Distance N) {
		Advance(I, N, Iter_cat(I));
	}

	template<class InIt, class Distance> inline
	void	Advance(InIt& iterator, Distance n, input_iterator_tag) {
		while (n-- > 0) {
			++iterator;
		}
	}

	template<class FwdIt, class Distance> inline
	void	Advance(FwdIt& iterator, Distance n, forward_iterator_tag) {
		while (n-- > 0) {
			++iterator;
		}
	}

	template<class BidIt, class Distance> inline
	void	Advance(BidIt& iterator, Distance n, bidirectional_iterator_tag) {
		while (n-- > 0) {
			++iterator;
		}
		while (n++ < 0) {
			--iterator;
		}
	}

	template<class RanIt, class Distance> inline
	void	Advance(RanIt& iterator, Distance n, random_access_iterator_tag) {
		iterator += n;
	}

}

#endif
