/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:39:36 by dwillard          #+#    #+#             */
/*   Updated: 2022/06/17 15:09:26 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_ITERATOR_H
#define BASE_ITERATOR_H

#include <cstddef>
#include "iterator_tag.hpp"

namespace ft
{
	template <class Category, class T, class Distance = ptrdiff_t,
			 class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T			value_type;
		typedef	Distance	difference_type;
		typedef	Pointer		pointer;
		typedef	Reference	reference;
		typedef	Category	iterator_category;
	};

	template <class T, class Dist, class Pt, class Rt>
	struct Bidit : public iterator<ft::bidirectional_iterator_tag, T, Dist, Pt, Rt>
	{};
	template <class T, class Dist, class Pt, class Rt>
	struct Ranit : public iterator<ft::random_access_iterator_tag, T, Dist, Pt, Rt>
	{};
	template <class T, class Dist, class Pt, class Rt>
	struct Outit : public iterator<ft::output_iterator_tag, void, void, void, void>
	{};
}

#endif