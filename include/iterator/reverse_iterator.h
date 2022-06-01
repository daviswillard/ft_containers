/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:44:44 by dwillard          #+#    #+#             */
/*   Updated: 2022/06/01 19:58:01 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_H
# define REVERSE_ITERATOR_H

# include "iterator.h"

namespace ft
{
	template <class RanIt>
		class reverse_iterator : public iterator<
				typename ft::iterator_traits<RanIt>::iterator_category,
				typename ft::iterator_traits<RanIt>::value_type,
				typename ft::iterator_traits<RanIt>::difference_type,
				typename ft::iterator_traits<RanIt>::pointer,
				typename ft::iterator_traits<RanIt>::reference>
	{
	};
}
#endif
