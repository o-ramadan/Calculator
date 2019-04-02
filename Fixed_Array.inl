// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// operator =
//
template <typename T, size_t N>
inline
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{	
	// = operator for fixed array's with same size on both sides is identical to derived class = operator
	return Array_Base <T>::operator=(rhs);	
}

//
// slice (size_t)
//
template <typename T, size_t N>
inline
Fixed_Array<T, N> Fixed_Array<T, N>::slice (size_t begin) const
{
	//Return new array that is a portion of argument array with beginning index until end of array
	return slice(begin, this->cur_size_ - 1);
}
