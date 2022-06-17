/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inserter.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:50:46 by dwillard          #+#    #+#             */
/*   Updated: 2022/06/17 14:51:56 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator.h"

namespace ft
{
	template <class Cont>
		ft::insert_iterator<Cont>	inserter(Cont& c, typename Cont::iterator i)
	{
		return ft::insert_iterator<Cont>(c, i);
	};

}
