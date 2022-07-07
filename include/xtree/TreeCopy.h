#ifndef FT_CONTAINERS_TREECOPY_H
#define FT_CONTAINERS_TREECOPY_H

#include "base.h"

namespace ft
{
	template <class TreeTraits>
	void	Tree<TreeTraits>::Copy(const Myt& X)
	{
		Root() = Copy(X.Root(), Head);
		Size = X.size();
		if (!Isnil(Root()))
		{
			Lmost() = Min(Root());
			Rmost() = Max(Root());
		}
		else
		{
			Lmost() = Head;
			Rmost() = Head;
		}
	}

	template <class TreeTraits>
	typename Tree<TreeTraits>::Nodeptr	Tree<TreeTraits>::Copy(Nodeptr X, Nodeptr P)
	{
		Nodeptr	R = Head;
		if (!Isnil(X))
		{
			Nodeptr Y = Buynode(P, Color(X));
			try {
				Consval(&Value(Y), Value(X));
			} catch (...) {
				Freenode(Y);
				Erase(R);
				throw;
			}
			Left(Y) = Head, Right(Y) = Head;
			if (Isnil(R))
				R = Y;
			try {
				Left(Y) = Copy(Left(X), Y);
				Right(Y) = Copy(Right(X), Y);
			} catch (...) {
				Erase(R);
				throw;
			}
		}
		return R;
	}
}

#endif
