#ifndef FT_CONTAINERS_TREEERASE_H
#define FT_CONTAINERS_TREEERASE_H

#include "base.h"

namespace ft
{
	template <class TreeTraits>
	typename Tree<TreeTraits>::iterator	Tree<TreeTraits>::erase(iterator P)
	{
		if (Isnil(P.Mynode()))
			throw std::out_of_range("map/set<T> iterator");
		Nodeptr X;
		Nodeptr Xpar;
		Nodeptr Y = (P++).Mynode();
		Nodeptr	Z = Y;
		if (Isnil(Left(Y)))
			X = Right(Y);
		else if (Isnil(Right(Y)))
			X = Left(Y);
		else
			Y = Min(Right(Y)), X = Right(Y);
		if (Y == Z)
		{
			Xpar = Parent(Z);
			if (!Isnil(X))
				Parent(X) = Xpar;
			if (Root() == Z)
				Root() = X;
			else if (Left(Xpar) == Z)
				Left(Xpar) = X;
			else
				Right(Xpar) = X;
			if (Lmost() != Z)
				;
			else if (Isnil(Right(Z)))
				Lmost() = Xpar;
			else
				Lmost() = Min(X);
			if (Rmost() != Z)
				;
			else if (Isnil(Left(Z)))
				Rmost() = Xpar;
			else
				Rmost() = Max(X);
		}
		else
		{
			Parent((Left(Z))) = Y;
			Left(Y) = Left(Z);
			if (Y == Right(Z))
				Xpar = Y;
			else
			{
				Xpar = Parent(Y);
				if (!Isnil(X))
					Parent(X) = Xpar;
				Left(Xpar) = X;
				Right(Y) = Right(Z);
				Parent(Right(Z)) = Y;
			}
			if (Root() == Z)
				Root() = Y;
			else if (Left(Parent(Z)) == Z)
				Left(Parent(Z)) = Y;
			else
				Right(Parent(Z)) = Y;
			Parent(Y) = Parent(Z);
			std::swap(Color(Y), Color(Z));
		}
		if (Color(Z) == Black)
		{
			for (; X != Root() && Color(X) == Black; Xpar = Parent(X))
			{
				if (X == Left(Xpar))
				{
					Nodeptr W = Right(Xpar);
					if (Color(W) == Red)
					{
						Color(W) = Black;
						Color(Xpar) = Red;
						Lrotate(Xpar);
						W = Right(Xpar);
					}
					if (Isnil(W))
						X = Xpar; // shouldn't happen
					else if (Color(Left(W)) == Black && Color(Right(W)) == Black)
					{
						Color(W) = Red;
						X = Xpar;
					}
					else
					{
						if (Color(Right(W)) == Black)
						{
							Color(Left(W)) = Black;
							Color(W) = Red;
							Rrotate(W);
							W = Right(Xpar);
						}
						Color(W) = Color(Xpar);
						Color(Xpar) = Black;
						Color(Right(W)) = Black;
						Lrotate(Xpar);
						break;
					}
				}
				else
				{
					Nodeptr W = Left(Xpar);
					if (Color(W) == Red)
					{
						Color(W) = Black;
						Color(Xpar) = Red;
						Rrotate(Xpar);
						W = Left(Xpar);
					}
					if (Isnil(W))
						X = Xpar; //shouldn't happen
					else if (Color(Right(W)) == Black && Color(Left(W)) == Black)
					{
						Color(W) = Red;
						X = Xpar;
					}
					else
					{
						if (Color(Left(W)) == Black)
						{
							Color(Right(W)) = Black;
							Color(W) = Red;
							Lrotate(W);
							W = Left(Xpar);
						}
						Color(W) = Color(Xpar);
						Color(Xpar) = Black;
						Color(Left(W)) = Black;
						Rrotate(Xpar);
						break;
					}
				}
			}
			Color(X) = Black;
		}
		Destval(&Value(Z));
		Freenode(Z);
		if (0 < Size)
			--Size;
		return P;
	}

	template <class TreeTraits>
	typename Tree<TreeTraits>::iterator Tree<TreeTraits>::erase(iterator F, iterator L)
	{
		if (size() == 0 || F != begin() || L != end())
		{
			while (F != L)
				erase(F++);
			return (F);
		}
		else
		{
			Erase(Root());
			Root() = Head, Size = 0;
			Lmost() = Head, Rmost() = Head;
			return begin();
		}
	}

	template <class TreeTraits>
	typename Tree<TreeTraits>::size_type Tree<TreeTraits>::erase(const key_type& X)
	{
		Pairii P = equal_range(X);
		size_type N = 0;
		ft::distance_tree(P.first, P.second, N);
		erase(P.first, P.second);
		return N;
	}

	template <class TreeTraits>
	void	Tree<TreeTraits>::erase(const key_type* F, const key_type* L)
	{
		while (F != L)
			erase(*F++);
	}

	template <class TreeTraits>
	void	Tree<TreeTraits>::Erase(Nodeptr X)
	{
		for (Nodeptr Y = X; !Isnil(Y); X = Y)
		{
			Erase(Right(Y));
			Y = Left(Y);
			Destval(&Value(X));
			Freenode(X);
		}
	}

}

#endif
