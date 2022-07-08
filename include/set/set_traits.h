/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_traits.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:40:36 by dwillard          #+#    #+#             */
/*   Updated: 2022/07/01 15:52:01 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_TRAITS_H
#define SET_TRAITS_H

namespace ft
{
	template <class Key, class Pred, class Ax>
	class	Tset_traits
	{
	public:
		Pred	comp;

		typedef Key						key_type;
		typedef Key						value_type;
		typedef Pred					key_compare;
		typedef typename Ax::template
			rebind<value_type>::other	allocator_type;

		Tset_traits() : comp()
		{
		}

		explicit Tset_traits(Pred Parg) : comp(Parg)
		{
		}

		typedef key_compare value_compare;

		const static Key &GetKey(const value_type &V)
		{
			Kfn	ret;
			return ret(V);
		}

		struct Kfn
		{
			const Key& operator()(const value_type& X) const
			{
				return X;
			}
		};
	};
}

#endif
