#pragma once

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