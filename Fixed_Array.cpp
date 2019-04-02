// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Fixed_Array
//
//Create a Fixed_Array of fixed size N

#include "Array_Base.h"
#include "Fixed_Array.h"
#include <stdexcept>

template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void)
:	Array_Base <T>(N)
{
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & fixed_arr)
:	Array_Base <T>(fixed_arr)
{
}

//
// Fixed_Array
//
template <typename T, size_t N>
template <size_t M>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, M> & fixed_arr)
:	Array_Base <T>(N)
{
	//Program will not compile if both Fixed_Arrays are not of the same type (a runtime check is not needed)
	//If argument array is larger, then fill "this" until its full
	if (M >= N)
	{
		for (int i = 0; i < N ; i++ )
			this->data_[i] = fixed_arr.get(i);
	}
	//If argument array is smaller, then fill "this" until all values from argument array have been copied
	else 
	{
		for (int i = 0; i < M ; i++ )
			this->data_[i] = fixed_arr.get(i);
	}
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill)
:	Array_Base <T>(N,fill)
{
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{
}

//
// operator =
//
template <typename T, size_t N>
template <size_t M>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, M> & rhs)
{
	//if argument array is bigger, then fill "this" until "this" reaches its capacity
	if (M >= N)
	{
		for (int i = 0; i < N ; i++ )
			this->data_[i] = rhs.get(i);
	}
	//If argument array is smaller, then fill "this" until all values from argument array have been copied
	else 
	{
		for (int i = 0; i < M ; i++ )
			this->data_[i] = rhs.get(i);
	}
	
	return *this;
	
}

//
// operator ==
//
template <typename T, size_t N>
bool Fixed_Array <T, N>::operator == (const Fixed_Array & rhs) const
{
	if (this != &rhs)
	{	
		//Base class == operator checks if cur_size_ of both arrays are equal
		if (Array_Base<T>::operator != (rhs))
			return false;
	}
	return true;
}

//
// operator !=
//
template <typename T, size_t N>
bool Fixed_Array <T, N>::operator != (const Fixed_Array & rhs) const
{
	if (*(this) == rhs)
		return false;
	else
		return true;
}



//
// slice (size_t,size_t)
//
template <typename T, size_t N>
Fixed_Array<T, N> Fixed_Array<T, N>::slice (size_t begin, size_t end) const
{
	//Size variable of the returned Fixed Array
	size_t new_size = end-begin+1;
	
	Fixed_Array<T,N> * newArr = new Fixed_Array<T,N>(new_size);
	newArr->data_ = this->data_+begin;
	return *newArr; 
}


