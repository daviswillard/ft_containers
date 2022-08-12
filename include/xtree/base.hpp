/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:48:56 by dwillard          #+#    #+#             */
/*   Updated: 2022/07/01 16:21:32 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_BASE_HPP
# define TREE_BASE_HPP

#include "TreeVal.hpp"
#include "TreePtr.hpp"
#include "Node.hpp"
#include <stdexcept>
#include "../iterator/iterator.hpp"
#include "../utility/utility.hpp"
#include "../algorithm/equal.hpp"
#include "../algorithm/lexicographical_compare.hpp"

namespace ft
{
	template <class TreeTraits>
	class Tree : public TreeVal<TreeTraits>
	{
	public:
		typedef Tree<TreeTraits>							Myt;
		typedef TreeVal<TreeTraits>							Mybase;
		typedef typename TreeTraits::key_type				key_type;
		typedef typename TreeTraits::key_compare			key_compare;
		typedef typename TreeTraits::value_compare			value_compare;
		typedef typename TreeTraits::value_type				value_type;
		typedef typename TreeTraits::allocator_type			allocator_type;
	protected:
		typedef typename TreeNode<TreeTraits>::Genptr		Genptr;
		typedef typename TreeNode<TreeTraits>::Node			Node;

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

		// all these functions return lvalue, so we can assign new value to function call expression
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


//		Iterator


		class	        iterator;
		friend class	Tree<TreeTraits>::iterator;
		class iterator : public ft::iterator<bidirectional_iterator_tag,
							value_type, Dift, Tptr, Reft>
		{
			private:
			void Dec() {
				if (Isnil(current_))
					current_ = Right(current_);
				else if (!Isnil(Left(current_)))
					current_ = Max(Left(current_));
				else {
					Nodeptr P;
					while (!Isnil(P = Parent(current_)) && current_ == Left(P))
						current_ = P;
					if (!Isnil(P))
						current_ = P;
				}
			}

			void Inc() {
				if (Isnil(current_));
				else if (!Isnil(Right(current_)))
					current_ = Min(Right(current_));
				else {
					Nodeptr P;
					while (!Isnil(P = Parent(current_)) && current_ == Right(P))
						current_ = P;
					current_ = P;
				}
			}

			protected:
			Nodeptr current_;
			public:
			typedef ft::iterator<ft::bidirectional_iterator_tag, value_type,
					Dift, Tptr, Reft> Mybase;
			typedef typename Mybase::iterator_category iterator_category;
//			typedef typename Mybase::value_type				value_type;
			typedef typename Mybase::difference_type difference_type;
			typedef typename Mybase::pointer pointer;
			typedef typename Mybase::reference reference;

			iterator() : current_(0) {}

			explicit iterator(Nodeptr P) : current_(P) {}

			reference operator*() const {
				return Value(current_);
			}

			Tptr operator->() const {
				return &**this;
			}

			iterator operator++() {
				Inc();
				return *this;
			}

			iterator operator++(int) {
				iterator tmp = *this;
				++*this;
				return tmp;
			}

			iterator operator--() {
				Dec();
				return *this;
			}

			iterator operator--(int) {
				iterator tmp = *this;
				--*this;
				return tmp;
			}

			bool operator==(const iterator &X) const {
				return current_ == X.current_;
			}

			bool operator!=(const iterator &X) const {
				return !(*this == X);
			}

			Nodeptr Mynode() const {
				return current_;
			}
		};

		class	        const_iterator;
		friend class	Tree<TreeTraits>::const_iterator;
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
//			typedef typename Mybase::value_type				value_type;
			typedef typename Mybase::difference_type			difference_type;
			typedef typename Mybase::pointer				pointer;
			typedef typename Mybase::reference				reference;

			const_iterator() : current_(0) {}
			const_iterator(Nodeptr P) : current_(P) {}
			const_iterator(const typename Tree<TreeTraits>::iterator& X): current_(X.Mynode()) {}
			template <class TreeTraits1>
			const_iterator(const typename Tree<TreeTraits1>::const_iterator& X) {
				current_ = reinterpret_cast<Nodeptr>(X.current_);
			}

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
				const_iterator tmp = *this;
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
				const_iterator	tmp = *this;
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


//		Orthodox canonical form


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
				TreeTraits::comp = X.comp;
				Copy(X);
			}
			return *this;
		}


//		iterator methods


		iterator	begin()
			{ return iterator(Lmost()); }
		const_iterator	begin() const
			{ return const_iterator(Lmost()); }
		iterator	end()
			{ return iterator(Head); }
		const_iterator	end() const
			{ return const_iterator(Head); }

		reverse_iterator	rbegin()
			{ return reverse_iterator(end()); }
		const_reverse_iterator	rbegin() const
			{ return const_reverse_iterator(end()); }
		reverse_iterator	rend()
			{ return reverse_iterator(begin()); }
		const_reverse_iterator	rend() const
			{ return const_reverse_iterator(begin()); }


//		util methods


		size_type	size() const
			{ return Size; }
		size_type	max_size() const
			{ return this->Alval.max_size(); }
		bool	empty() const
			{ return size() == 0; }
		allocator_type	get_allocator() const
			{ return this->Alval; }
		key_compare	key_comp() const
			{ return TreeTraits::comp; }
		value_compare	value_comp() const
			{ return value_compare(key_comp()); }


//		insert-delete methods


		Pairib		insert(const value_type& V);
		iterator	insert(Tree::iterator P, const value_type& V);
		template <class Iter>
			void 	insert(Iter F, Iter L);

		iterator	erase(Tree::iterator P);
		iterator	erase(iterator F, iterator L);
		size_type	erase(const key_type& X);
		void		erase(const key_type* F, const key_type* L);

		void	clear()
		{
			erase(begin(), end());
		}


//		more util methods


		iterator	find(const key_type& Kv)
		{
			iterator P = lower_bound(Kv);
			return (P == end() || TreeTraits::comp(Kv, Key(P.Mynode())) ? end() : P);
		}

		const_iterator	find(const key_type& Kv) const
		{

			const_iterator P = lower_bound(Kv);
			return (P == end() || TreeTraits::comp(Kv, Key(P.Mynode())) ? end() : P);
		}

		size_type	count(const key_type& Kv) const
		{
			Paircc Ans = equal_range(Kv);
			size_type N = 0;
			distance_tree(Ans.first, Ans.second, N);
			return N;
		}

		iterator	lower_bound(const key_type& Kv)
		{
			return iterator(Lbound(Kv));
		}

		const_iterator	lower_bound(const key_type& Kv) const
		{
			return const_iterator(Lbound(Kv));
		}

		iterator	upper_bound(const key_type& Kv)
		{
			return iterator(Ubound(Kv));
		}


		const_iterator	upper_bound(const key_type& Kv) const
		{
			return const_iterator(Ubound(Kv));
		}

		Pairii	equal_range(const key_type& Kv)
		{
			return Pairii(lower_bound(Kv), upper_bound(Kv));
		}

		Paircc	equal_range(const key_type& Kv) const
		{
			return Paircc(lower_bound(Kv), upper_bound(Kv));
		}

		void	swap(Myt& X)
		{
			if (get_allocator() == X.get_allocator())
			{
				std::swap(TreeTraits::comp, X.TreeTraits::comp);
				std::swap(Head, X.Head);
				std::swap(Size, X.Size);
			}
			else
			{
				Myt Ts = *this;
				*this = X, X = Ts;
			}
		}

	protected:
		size_type	Size;
		Nodeptr		Head;


//		all heavy lifting is there


		void		Copy(const Myt& X);
		Nodeptr		Copy(Nodeptr X, Nodeptr P);

		void		Erase(Nodeptr X);

		iterator	Insert(bool Addleft, Nodeptr Y,
						   const value_type& V);

		void	Init()
		{
			Head = Buynode(0, Black);
			Isnil(Head) = true;
			Root() = Head;
			Lmost() = Head, Rmost() = Head;
			Size = 0;
		}

		Nodeptr	Lbound(const key_type& Kv) const
		{
			Nodeptr X = Root();
			Nodeptr Y = Head;
			while (!(Isnil(X)))
			{
				if (TreeTraits::comp(Key(X), Kv))
					X = Right(X);
				else
					Y = X, X = Left(X);
			}
			return (Y);
		}

		Nodeptr&	Lmost()
		{
			return Left(Head);
		}

		Nodeptr&	Lmost() const
		{
			return (Left(Head));
		}

		void	Lrotate(Nodeptr X)
		{
			Nodeptr Y = Right(X);
			Right(X) = Left(Y);
			if (!Isnil(Left(Y)))
				Parent(Left(Y)) = X;
			Parent(Y) = Parent(X);
			if (X == Root())
				Root() = Y;
			else if (X == Left(Parent(X)))
				Left(Parent(X)) = Y;
			else
				Right(Parent(X)) = Y;
			Left(Y) = X;
			Parent(X) = Y;
		}

		static Nodeptr Max(Nodeptr P)
		{
			while (!Isnil(Right(P)))
				P = Right(P);
			return P;
		}

		static Nodeptr Min(Nodeptr P)
		{
			while (!Isnil(Left(P)))
				P = Left(P);
			return P;
		}

		Nodeptr& Rmost()
		{
			return Right(Head);
		}

		Nodeptr& Rmost() const
		{
			return Right(Head);
		}

		Nodeptr& Root()
		{
			return Parent(Head);
		}


		Nodeptr& Root() const
		{
			return Parent(Head);
		}

		void Rrotate(Nodeptr X)
		{
			Nodeptr Y = Left(X);
			Left(X) = Right(Y);
			if (!Isnil(Right(Y)))
				Parent(Right(Y)) = X;
			Parent(Y) = Parent(X);
			if (X == Root())
				Root() = Y;
			else if (X == Right(Parent(X)))
				Right(Parent(X)) = Y;
			else
				Left(Parent(X)) = Y;
			Right(Y) = X;
			Parent(X) = Y;
		}

		Nodeptr Ubound(const key_type& Kv) const
		{
			Nodeptr X = Root();
			Nodeptr Y = Head;
			while (!Isnil(X))
			{
				if (TreeTraits::comp(Kv, Key(X)))
					Y = X, X = Left(X);
				else
					X = Right(X);
			}
			return Y;
		}

		Nodeptr	Buynode(Nodeptr Parg, char Carg)
		{
			Nodeptr S = this->Alnod.allocate(1);
#if defined (__linux__)
			this->Alptr.construct(&Left(S), NULL);
			this->Alptr.construct(&Right(S), NULL);
#elif defined (__APPLE__) && defined (__clang__)
			this->Alptr.construct(&Left(S), nullptr);
			this->Alptr.construct(&Right(S), nullptr);
#endif
			this->Alptr.construct(&Parent(S), Parg);
			Color(S) = Carg;
			Isnil(S) = false;
			return S;
		}

		void	Consval(Tptr P, const value_type& V)
		{
			this->Alval.construct(P, V);
		}

		void	Destval(Tptr P)
		{
			this->Alval.destroy(P);
		}

		void	Freenode(Nodeptr S)
		{
			this->Alptr.destroy(&Parent(S));
			this->Alptr.destroy(&Right(S));
			this->Alptr.destroy(&Left(S));
			this->Alnod.deallocate(S, 1);
		}
	};

	template <class TreeTraits> inline
	void	swap(Tree<TreeTraits>& X, Tree<TreeTraits>& Y)
	{
		X.swap(Y);
	}

	template <class TreeTraits> inline
	bool	operator== (const Tree<TreeTraits>& X, const Tree<TreeTraits>& Y)
	{
		return (X.size() == Y.size() && equal(X.begin(), X.end(), Y.begin()));
	}

	template <class TreeTraits> inline
	bool	operator!= (const Tree<TreeTraits>& X, const Tree<TreeTraits>& Y)
	{
		return !(X == Y);
	}

	template <class TreeTraits> inline
	bool	operator< (const Tree<TreeTraits>& X, const Tree<TreeTraits>& Y)
	{
		return ft::lexicographical_compare(X.begin(), X.end(), Y.begin(), Y.end(), X.value_comp());
	}

	template <class TreeTraits> inline
	bool	operator> (const Tree<TreeTraits>& X, const Tree<TreeTraits>& Y)
	{
		return Y < X;
	}

	template <class TreeTraits> inline
	bool	operator<= (const Tree<TreeTraits>& X, const Tree<TreeTraits>& Y)
	{
		return !(Y < X);
	}

	template <class TreeTraits> inline
	bool	operator>= (const Tree<TreeTraits>& X, const Tree<TreeTraits>& Y)
	{
		return !(X < Y);
	}

}

#include "TreeIterator.hpp"
#include "TreeCIterator.hpp"
#include "TreeInsert.hpp"
#include "TreeErase.hpp"
#include "TreeCopy.hpp"


#endif

