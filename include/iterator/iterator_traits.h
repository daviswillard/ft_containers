/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:21:55 by dwillard          #+#    #+#             */
/*   Updated: 2022/06/04 17:56:08 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_H
# define ITERATOR_TRAITS_H

# include "iterator_tag.h"
# include <cstddef>

namespace ft
{
	template <class It>
		struct iterator_traits
		{
			typedef typename It::iterator_category iterator_category;
			typedef typename It::value_type value_type;
			typedef typename It::distance_type distance_type;
			typedef typename It::pointer pointer;
			typedef typename It::reference reference;
		};

	template <class T>
		struct iterator_traits<T *>
		{
			typedef T							value_type;
			typedef T*							pointer;
			typedef T&							reference;
			typedef ptrdiff_t					difference_type;
			typedef random_access_iterator_tag	iterator_category;
		};
}

#endif
