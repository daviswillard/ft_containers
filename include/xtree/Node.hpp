/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:01:07 by dwillard          #+#    #+#             */
/*   Updated: 2022/07/08 15:55:16 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

#include <memory>

namespace ft
{
	template <class TreeTraits>
		class TreeNode : public TreeTraits
	{
	protected:
		typedef typename TreeTraits::allocator_type	allocator_type;
		typedef typename TreeTraits::key_compare	key_compare;
		typedef typename TreeTraits::value_type		value_type;
		typedef typename allocator_type::template
					rebind<void>::other::pointer	Genptr;
		struct			Node;
		friend struct	Node;
		struct	Node {
			Genptr		Left;
			Genptr		Right;
			Genptr		Parent;
			value_type	Value;
			char		Color;
			char		Isnil;
		};
		TreeNode(const key_compare& Parg, allocator_type Al):
				TreeTraits(Parg), Alnod(Al)
		{
		}
		typename allocator_type::template rebind<Node>::other	Alnod;
	};

}

#endif
