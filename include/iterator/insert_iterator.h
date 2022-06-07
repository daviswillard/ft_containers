/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_iterator.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:49:37 by dwillard          #+#    #+#             */
/*   Updated: 2022/06/07 19:17:52 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator.h"
#include "iterator_tag.h"

namespace ft
{
	template <class Cont>
	class insert_iterator
		: public ft::iterator<ft::output_iterator_tag, void, void, void, void>
	{
	protected:
		Cont*					container;
		typename Cont::iterator	iter;
	public:
		typedef Cont 						container_type;
		typedef typename Cont::reference	reference;
		typedef typename Cont::value_type	value_type;
		insert_iterator(Cont& x, typename Cont::iterator it);
		insert_iterator& operator=(typename Cont::const_reference val);
		insert_iterator& operator*();
		insert_iterator& operator++();
		insert_iterator& operator++(int);

		insert_iterator<Cont>	inserter(Conta& c, typename Cont::iterator i) { return insert_iterator<Cont>(c, i) };
	};
}
