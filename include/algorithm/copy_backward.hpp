#ifndef COPY_BACKWARD_HPP
#define COPY_BACKWARD_HPP

namespace ft
{
	template <class BidIt1, class BidIt2> inline
	BidIt2 copy_backward(BidIt1 F, BidIt1 L, BidIt2 X)
	{
		while (F != L)
			*--X = *--L;
		return X;
	}
}

#endif //COPY_BACKWARD_HPP
