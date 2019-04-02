// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include <stdexcept>         // for std::out_of_bounds exception
#include "Array_Base.h"


//
// Array_Base
//
template <typename T>
Array_Base <T>::Array_Base (void)
:	cur_size_ (DEF_CUR_SIZE),
	data_ (new T[cur_size_])
{
}

//
// Array_Base (size_t)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length)
:	cur_size_ (length),
	data_ (new T[cur_size_])
{	
}

//
// Array_Base (const Array_Base &)
//
template <typename T>
Array_Base <T>::Array_Base (const Array_Base & arr_base)
:	cur_size_ (arr_base.cur_size_),
	data_ (new T[cur_size_])
{
	for (int i = 0;i < this->cur_size_; i++ )
		this->data_[i] = arr_base.data_[i];
}

//
// Array (size_t, T)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length, T fill)
:	cur_size_(length),
	data_ (new T[cur_size_])
{
	this->fill(fill);
}

//
// ~Array_Base
//
template <typename T>
Array_Base <T>::~Array_Base (void)
{	
	if (data_ != nullptr)
		delete [] data_;
}

//
// operator =
//
template <typename T>
const Array_Base <T> & Array_Base <T>::operator = (const Array_Base & rhs)
{
	//Set cur_size_ and data_ of lhs equal to rhs'
	if (this != &rhs)
	{
		if (cur_size_ != rhs.cur_size_)
			cur_size_ = rhs.cur_size_; 
		
		for (int i = 0; i < this->cur_size_; i++)
			data_[i] = rhs.data_[i];	
	}
	return *this;	
}

//
// operator ==
//
template <typename T>
bool Array_Base <T>::operator == (const Array_Base & rhs) const
{
	if (this != &rhs)
	{	
		if	(cur_size_ != rhs.cur_size_)
			return false;
		
		//If at least one difference exists between both array's data then return false
		for (int i = 0; i < this->cur_size_; i++)
		{
			if (data_[i] != rhs.data_[i])
				return false;
		}
	}
	return true;
}

//
// operator !=
//
template <typename T>
bool Array_Base <T>::operator != (const Array_Base & rhs) const
{
	if (*(this) == rhs)
		return false;
	else
		return true;
}


//
// operator []
//
template <typename T>
T & Array_Base <T>::operator [] (size_t index)
{
	if (index >= this->cur_size_)
		throw std::out_of_range ("Out of Range");
	
	return	data_[index];	
}

//
// operator [] 
//
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
	if (index >= this->cur_size_)
		throw std::out_of_range ("Out of Range");
  
	return	data_[index];	
}

//
// get
//
template <typename T>
T Array_Base <T>::get (size_t index) const
{

	if (index >= this->cur_size_)
		throw std::out_of_range ("Out of Range");
	
	return	data_[index];	
}

//
// set
//
template <typename T>
void Array_Base <T>::set (size_t index, T value)
{
	if (index >= this->cur_size_)
		throw std::out_of_range ("Out of Range");

	data_[index] = value;
}

//
// find (T)
//
template  <typename T>
int Array_Base <T>::find (T value) const
{
	//linear search through array
	for (int i = 0; i < this->cur_size_; i++)
	{
		if (data_[i] == value)
			return i;
	}
	return -1;
}

//
// find (T, size_t) 
//
template <typename T>
int Array_Base <T>::find (T val, size_t start) const
{
	if (start >= this->cur_size_)
		throw std::out_of_range ("Out of Range");
	
	//linear search through array
	for (int i = start; i < this->cur_size_; i++)
	{
		if (data_[i] == val)
			return i;
	}
	return -1;
}


//
// fill
//
template <typename T>
void Array_Base <T>::fill (T value)
{
	for (int i = 0; i < this->cur_size_; i++)
		data_[i] = value;
}

//
// reverse
//
template <typename T>
void Array_Base<T>::reverse (void)
{
  T temp;
  int i,j;
  
  //Switch corresponding elements (eg: first and last, second and second last) until middle of array is reached
  for (i = 0,j = (this->cur_size_) - 1; i < (this->cur_size_)/2; i++,j--)
  {
	temp = data_[j];
    
	data_[j] = data_[i];
    
	data_[i] = temp;  
  }
}


