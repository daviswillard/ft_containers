/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:48:56 by dwillard          #+#    #+#             */
/*   Updated: 2022/06/28 17:54:24 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "TreeVal.h"
//#include "titerator.h"
#include "../iterator/iterator.h"
#include "../utils/utils.h"

namespace ft
{
	template <class TreeTraits>
	class Tree : public TreeVal<TreeTraits>
	{
	protected:
		typedef typename TreeNode<TreeTraits>::Genptr Genptr;
		typedef typename TreeNode<TreeTraits>::Node		Node;
		enum	Redbl {Red, Black};
		typedef typename allocator_type::template
				rebind<Node>::other::pointer				Nodeptr;
		typedef typename allocator_type::template
				rebind<Nodeptr>::other::reference			Noderef;
		typedef typename allocator_type::template
				rebind<key_type>::other::const_reference	Keyref;
		typedef typename allocator_type::template
				rebind<char>::other::reference				Charref;
		typedef typename allocator_type::template
				rebind<value_type>::other::reference		Vref;

		static Charref	Color(Nodeptr P)
		{
			return ((Charref)(*P).Color);
		}
		static Charref	Isnil(Nodeptr P)
		{
			return ((Charref)(*P).Isnil);
		}
		static Keyref Key(Nodeptr P)
		{
			return (TreeTraits::GetKey(Value(P)));
		}
		static Noderef	Left(Nodeptr P)
		{
			return ((Noderef)(*P).Left);
		}
		static Noderef	Right(Nodeptr P)
		{
			return ((Noderef)(*P).Right);
		}
		static Noderef	Parent(Nodeptr P)
		{
			return ((Noderef)(*P).Parent);
		}
		static Vref	Value(Nodeptr P)
		{
			return ((Vref)(*P).Value);
		}

	public:
		typedef Tree<TreeTraits>	Myt;
		typedef TreeVal<TreeTraits>	Mybase;
		typedef typename TreeTraits::key_type		key_type;
		typedef typename TreeTraits::key_compare	key_compare;
		typedef typename TreeTraits::value_compare	value_compare;
		typedef typename TreeTraits::value_type		value_type;
		typedef typename TreeTraits::allocator_type	allocator_type;
		typedef typename TreeTraits::comp			comp;


		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	Dift;
		typedef typename allocator_type::template
				rebind<value_type>::other::pointer			Tptr;
		typedef typename allocator_type::template
				rebind<value_type>::other::const_pointer	Ctptr;
		typedef typename allocator_type::template
				rebind<value_type>::other::reference		Reft;

		typedef typename allocator_type::template
			rebind<value_type>::other::const_reference		const_reference;

		typedef	Dift										difference_type;
		typedef Tptr										pointer;
		typedef Ctptr										const_pointer;
		typedef Reft										reference;


//		typedef	ft::titerator<TreeTraits>					iterator;
//		friend class	titerator<TreeTraits>

		class	        iterator;
		friend class	iterator;
        class iterator : public ft::iterator<bidirectional_iterator_tag, value_type,
				Dift, Tptr, Reft>
		{
        private:
            void Dec()
            {
                if (Isnil(current_))
                    current_ = Right(current_);
                else if (!Isnil(Left(current_)))
                    current_ = Max(Left(current_));
                else
                {
                    Nodeptr P;
                    while (!Isnil(P = Parent(current_)) && current_ == Left(P))
                        current_ = P;
                    if (!Isnil(P))
                        current_ = P;
                }
            }
            void Inc()
            {
                if (Isnil(current_))
                    ;
                else if (!Isnil(Right(current_)))
                    current_ = Min(Right(current_));
                else
                {
                    Nodeptr P;
                    while (!Isnil(P = Parent(current_)) && current_ == Right(P))
                        current_ = P;
                    current_ = P;
                }
            }
		protected:
			Nodeptr	current_;
		public:
			typedef	ft::iterator<ft::bidirectional_iterator_tag, value_type,
					Dift, Tptr, Reft>						Mybase;
			typedef typename Mybase::iterator_category		iterator_category;
			typedef typename Mybase::value_type				value_type;
			typedef typename Mybase::difference_type		difference_type;
			typedef typename Mybase::pointer				pointer;
			typedef typename Mybase::reference				reference;

            iterator() : current_(0) {}
            explicit iterator(Nodeptr P) : current_(P) {}
            reference   operator*() const
            {
                return Value(current_);
            }
            Tptr    operator->() const
            {
                return &**this;
            }
            iterator	operator++()
            {
                Inc();
                return *this;
            }
            iterator	operator++(int)
            {
                iterator    tmp = *this;
                ++*this;
				return tmp;
            }
			iterator	operator--()
			{
				Dec();
				return *this;
			}
			iterator	operator--(int)
			{
				iterator	tmp = *this;
				--*this;
				return tmp;
			}
			bool	operator==(const iterator& X) const
			{
				return current_ == X.current_;
			}
			bool	operator!=(const iterator& X) const
			{
				return !(*this == X);
			}
			Nodeptr	Mynode() const
			{
				return current_;
			}
		};

		class	        const_iterator;
		friend class	const_iterator;
		class const_iterator : public ft::iterator<bidirectional_iterator_tag, value_type,
				Dift, Ctptr, const_reference>
		{
		private:
			void Dec()
			{
				if (Isnil(current_))
					current_ = Right(current_);
				else if (!Isnil(Left(current_)))
					current_ = Max(Left(current_));
				else
				{
					Nodeptr P;
					while (!Isnil(P = Parent(current_)) && current_ == Left(P))
						current_ = P;
					if (!Isnil(P))
						current_ = P;
				}
			}
			void Inc()
			{
				if (Isnil(current_))
					;
				else if (!Isnil(Right(current_)))
					current_ = Min(Right(current_));
				else
				{
					Nodeptr P;
					while (!Isnil(P = Parent(current_)) && current_ == Right(P))
						current_ = P;
					current_ = P;
				}
			}
		protected:
			Nodeptr	current_;
		public:
			typedef	ft::iterator<ft::bidirectional_iterator_tag, value_type,
					Dift, Ctptr, const_reference>			Mybase;
			typedef typename Mybase::iterator_category		iterator_category;
			typedef typename Mybase::value_type				value_type;
			typedef typename Mybase::difference_type		difference_type;
			typedef typename Mybase::pointer				pointer;
			typedef typename Mybase::reference				reference;

			const_iterator() : current_(0) {}
			explicit const_iterator(Nodeptr P) : current_(P) {}
			explicit const_iterator(const typename Tree<TreeTraits>::iterator& X): current_(X.Mynode()) {}

			const_reference   operator*() const
			{
				return Value(current_);
			}
			Ctptr    operator->() const
			{
				return &**this;
			}
			const_iterator&	operator++()
			{
				Inc();
				return *this;
			}
			const_iterator	operator++(int)
			{
				iterator    tmp = *this;
				++*this;
				return tmp;
			}
			const_iterator&	operator--()
			{
				Dec();
				return *this;
			}
			const_iterator	operator--(int)
			{
				iterator	tmp = *this;
				--*this;
				return tmp;
			}
			bool	operator==(const const_iterator& X) const
			{
				return current_ == X.current_;
			}
			bool	operator!=(const const_iterator& X) const
			{
				return !(*this == X);
			}
			Nodeptr	Mynode() const
			{
				return current_;
			}
		};

		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		typedef	pair<iterator, bool>					Pairib;
		typedef	pair<iterator, iterator>				Pairii;
		typedef	pair<const_iterator, const_iterator>	Paircc;

		explicit Tree(const key_compare& Parg, const allocator_type& Al): Mybase(Parg, Al)
		{
			Init();
		}

		Tree(const value_type* F, const value_type* L,
			 const key_compare& Parg, const allocator_type& Al)
			 : Mybase(Parg, Al)
		{
			Init();
			insert(F, L);
		}

		Tree(const Myt& X)
			: Mybase(X.key_comp(), X.get_allocator())
		{
			Init();
			Copy(X);
		}

		~Tree()
		{
			erase(begin(), end());
			Freenode(Head);
			Head = 0;
			Size = 0;
		}

		Myt& operator= (const Myt& X)
		{
			if (this != &X)
			{
				erase(begin(), end());
				comp = X.comp;
				Copy(X);
			}
			return *this;
		}

		iterator	begin()
			{ return iterator(Lmost()); }
		const_iterator	begin()
			{ return const_iterator(Lmost()); }
		iterator	end()
			{ return iterator(Head()); }
		const_iterator	end()
			{ return const_iterator(Head()); }

		reverse_iterator	rbegin()
			{ return reverse_iterator(end()); }
		const_reverse_iterator	rbegin() const
			{ return const_reverse_iterator(end()); }
		reverse_iterator	rend()
			{ return reverse_iterator(begin()); }
		const_reverse_iterator	rend() const
			{ return const_reverse_iterator(begin()); }


		size_type	size() const
			{ return Size; }
		size_type	max_size() const
			{ return Alval.max_size(); }
		bool	empty() const
			{ return size() == 0; }
		allocator_type	get_allocator() const
			{ return Alval; }
		key_compare	key_comp() const
			{ return comp; }
		value_compare	value_comp() const
			{ return value_compare(key_comp()); }


		Pairib	insert(const value_type& V)
		{
			Nodeptr	X = Root();
			Nodeptr	Y = Head;
			bool	Addleft = true;
			while (!Isnil(X))
			{
				Y = X;
				Addleft = comp(Kfn()(V), Key(X));
				X = Addleft ? Left(X) : Right(X);
			}
			iterator P = iterator(Y);
			if (!Addleft)
				;
			else if (P == begin())
				return (Pairib(Insert(true, Y, V), true));
			else
				--P;
			if (comp(Key(P.Mynode()), Kfn()(V)))
				return (Pairib(Insert(Addleft, Y, V), true));
			else
				return (Pairib(P, false));
		}
		iterator	insert(iterator P, const value_type& V)
		{
			if (size() == 0)
				return Insert(true, Head, V);
			else if (P == begin())
			{
				if (comp(kfn()(V), Key(P.Mynode())))
					return Insert(false, Rmost(), V);
			}
			else
			{
				iterator	Pb = P;
				if (comp(Key((--Pb).Mynode()), Kfn()(V))
				&& comp(Kfn()(V), Key(P.Mynode()))) {
					if (Isnil(Right(Pb.Mynode())))
						return Insert(false, Pb.Mynode(), V);
					else
						return Insert(true, P.Mynode(), V);
				}
			}
			return insert(V).first;
		}
		template <class Iter>
			void insert(Iter F, Iter L)
		{
			for (; F != L; ++F)
				insert(*F);
		}


		iterator	erase(iterator P)
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
				Y = Min(Right(Y)), X = Right(Y); /* comma operator basically does first statement, discards it
				then calculates second statement and returns it's value
https://www.quora.com/Why-was-the-comma-operator-introduced-in-C-and-C-I-am-yet-to-see-a-good-use-of-a-comma-operator */
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
								Color(Right(W)) == Black;
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
		iterator erase(iterator F, iterator L)
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
		size_type	erase(const key_type& X)
		{
			Pairii P = equal_range(X);
			size_type N = 0;
			Distance(P.first, P.second, N);
			erase(P.first, P.second);
			return N;
		}
		void	erase(const key_type* F, const key_type* L)
		{
			while (F != L)
				erase(*F++);
		}

		void	clear()
		{
			erase(begin, end());
		}

	protected:
		size_type	Size;
	};
}
