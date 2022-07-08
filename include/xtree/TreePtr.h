/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreePtr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:55:49 by dwillard          #+#    #+#             */
/*   Updated: 2022/07/08 15:56:14 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_PTR_H
#define TREE_PTR_H

#include "Node.h"

namespace ft
{
	template <class TreeTraits>
	class TreePtr : public TreeNode<TreeTraits>
	{
	protected:
		typedef typename TreeNode<TreeTraits>::Node	Node;
		typedef typename TreeTraits::allocator_type	allocator_type;
		typedef typename TreeTraits::key_compare	key_compare;
		typedef typename allocator_type::template
				rebind<Node>::other::pointer		Nodeptr;
		TreePtr(const key_compare& Parg, allocator_type Al):
				TreeNode<TreeTraits>(Parg, Al), Alptr(Al)
		{
		}
		typename allocator_type::template
				rebind<Nodeptr>::other	Alptr;
	};
}

#endif
