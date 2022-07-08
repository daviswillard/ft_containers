/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeVal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:56:18 by dwillard          #+#    #+#             */
/*   Updated: 2022/07/08 15:56:33 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_VAL_H
#define TREE_VAL_H

#include "TreePtr.h"

namespace ft
{
	template<class TreeTraits>
	class	TreeVal : public TreePtr<TreeTraits>
	{
	protected:
		typedef typename TreeTraits::allocator_type	allocator_type;
		typedef typename TreeTraits::key_compare	key_compare;
		TreeVal(const key_compare& Parg, allocator_type Al):
				TreePtr<TreeTraits>(Parg, Al), Alval(Al)
		{
		}
		allocator_type Alval;
	};
}

#endif
