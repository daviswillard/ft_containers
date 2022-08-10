/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeInsert.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:55:29 by dwillard          #+#    #+#             */
/*   Updated: 2022/07/08 15:56:57 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_TREEINSERT_H
#define FT_CONTAINERS_TREEINSERT_H

#include "base.hpp"

namespace ft
{
	template <class TreeTraits>
	typename Tree<TreeTraits>::Pairib
	Tree<TreeTraits>::insert(const value_type& V)
	{
		Nodeptr	X = Root();
		Nodeptr	Y = Head;
		bool	Addleft = true;
		while (!Isnil(X))
		{
			Y = X;
			Addleft = TreeTraits::comp(TreeTraits::GetKey(V), Key(X));
			X = Addleft ? Left(X) : Right(X);
		}
		iterator P = iterator(Y);
		if (!Addleft)
			;
		else if (P == begin())
			return (Pairib(Insert(true, Y, V), true));
		else
			--P;
		if (TreeTraits::comp(Key(P.Mynode()), TreeTraits::GetKey(V)))
			return (Pairib(Insert(Addleft, Y, V), true));
		else
			return (Pairib(P, false));
	}

	template <class TreeTraits>
	template <class Iter>
	void Tree<TreeTraits>::insert(Iter F, Iter L)
	{
		for (; F != L; ++F)
			insert(*F);
	}

	template <class TreeTraits>
	typename Tree<TreeTraits>::iterator
	Tree<TreeTraits>::insert(Tree::iterator P, const value_type& V)
	{
		if (size() == 0)
			return Insert(true, Head, V);
		else if (P == begin())
		{
			if (TreeTraits::comp(TreeTraits::GetKey(V), Key(P.Mynode())))
				return Insert(false, Rmost(), V);
		}
		else
		{
			iterator	Pb = P;
			if (TreeTraits::comp(Key((--Pb).Mynode()), TreeTraits::GetKey(V))
				&& TreeTraits::comp(TreeTraits::GetKey(V), Key(P.Mynode())))
			{
				if (Isnil(Right(Pb.Mynode())))
					return Insert(false, Pb.Mynode(), V);
				else
					return Insert(true, P.Mynode(), V);
			}
		}
		return insert(V).first;
	}

	template <class TreeTraits>
	typename Tree<TreeTraits>::iterator ft::Tree<TreeTraits>::Insert(bool Addleft, Nodeptr Y,
																	const value_type &V)
	{
		if (max_size() - 1 <= Size)
			throw std::length_error("map/set<T> too long");
		Nodeptr Z = Buynode(Y, Red);    //create new node that we insert. Y is considered its parent node
		Left(Z) = Head, Right(Z) = Head;
		try {
			Consval(&Value(Z), V); //initialize its value
		} catch (...) {
			Freenode(Z);
			throw;
		}
		++Size;
		if (Y == Head) {
			Root() = Z;
			Lmost() = Z, Rmost() = Z;
		}
		else if (Addleft) //check whether to add it to the left of node Y or not
		{
			Left(Y) = Z;
			if (Y == Lmost())
				Lmost() = Z;
		}
		else
		{
			Right(Y) = Z;
			if (Y == Rmost())
				Rmost() = Z;
		}
		for (Nodeptr X = Z; Color(Parent(X)) == Red;) //check that we didn't disbalance our tree (insert-fixup)
		{
			if (Parent(X) == Left(Parent(Parent(X))))
			{
				Y = Right(Parent(Parent(X)));
				if (Color(Y) == Red)
				{
					Color(Parent(X)) = Black;
					Color(Y) = Black;
					Color(Parent(Parent(X))) = Red;
					X = Parent(Parent(X));
				}
				else
				{
					if (X == Right(Parent(X)))
					{
						X = Parent(X);
						Lrotate(X);
					}
					Color(Parent(X)) = Black;
					Color(Parent(Parent(X))) = Red;
					Rrotate(Parent(Parent(X)));
				}
			}
			else
			{
				Y = Left(Parent(Parent(X))); // 1
				if (Color(Y) == Red)
				{
					Color(Parent(X)) = Black;
					Color(Y) = Black;
					Color(Parent(Parent(X))) = Red;
					X = Parent(Parent(X));
				}
				else
				{
					if (X == Left(Parent(X)))
					{
						X = Parent(X);
						Rrotate(X);
					}
					Color(Parent(X)) = Black; // 2
					Color(Parent(Parent(X))) = Red; // 3
					Lrotate(Parent(Parent(X))); // 4
				}
			}
		}
		Color(Root()) = Black;
		return iterator(Z);
	}
}
#endif
