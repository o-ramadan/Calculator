// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array <T>::Array (void)
:	Array_Base <T>(),				//Creates Array of default size 10
	max_size_ (2 * DEF_CUR_SIZE) 
{	
	allocate_max_size();
}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
:	Array_Base <T>(length),
	max_size_ (2*length) 	
{
	allocate_max_size();
}

//
// Array (size_t, T)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
:	Array_Base <T>(length,fill),
	max_size_ (2*length)
{
	allocate_max_size();
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & arr)
:	Array_Base <T>(arr),
	max_size_ (arr.max_size_)
{
	allocate_max_size();
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{	
}

//
// allocate_max_size
//
template <typename T>
void Array <T>::allocate_max_size()
{
	T temp[this->cur_size_];
				
	//copy old array into temporary location
	for (int i = 0; i < this->cur_size_; i++)
		temp[i] = this->data_[i];

	delete [] this->data_;
	
	//Create new array with size = max_size to accommodate expansion
	this->data_ = new T[this->max_size_];
	
	//Copy data back into data_
	for (int i = 0; i < this->cur_size_; i++)
		 this->data_[i] = temp[i];
	
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
	if (this != &rhs)
	{
		bool flag = false;
		
		if ( this->max_size_ < rhs.cur_size_)
		{
			//Set current and max size variables equal to rhs'
			this->cur_size_ = rhs.cur_size_;
			this->max_size_ = rhs.max_size_;
			flag = true;
		}
		
		//If the "if-block" above is not executed, then this Array's current size
		//is altered to prevent future operations from throwing exceptions when accessing
		//data beyond the old "cur_size_"
		if (flag == false)
			this->cur_size_ = rhs.cur_size_; 
		
		//Free old data, allocate new memory, then fill it with rhs' data
		delete [] this->data_;
		this->data_ = new T[max_size_];
		
		for (int i = 0; i < this->cur_size_; i++)
				this->data_[i] = rhs.data_[i];
	}
	return *this;	
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
	
	//if new size = current size, then do nothing
	if (new_size != this->cur_size_)
	{
		if (new_size > this->cur_size_)
		{
			int i,tempVar;
			
			//If new size is greater than max size, then more space needs to be allocated (maxsize needs to increase)
			if (new_size > this->max_size_)
			{
				tempVar = this->cur_size_;
				
				this->max_size_ = 2*new_size;
				this->cur_size_ = new_size;
				
				//temp will be used to keep the data constant throughout the resizing process
				//by copying data from old array to newly resized one
				T temp[this->cur_size_];
				
				//copy old array into new location that has expanded memory
				for (i = 0; i < this->cur_size_; i++)
					temp[i] = this->data_[i];
				
				
				//old data is deleted after it was copied. temp points to the location that contains the new data. 
				//The data is copied from temp to data_ using the for loop below.
				//Temp is deleted on its own after the "resize" method goes out of scope
				
				delete [] this->data_;
				this->data_ = new T[this->max_size_];
				
				for (i = 0; i < this->cur_size_; i++)
					 this->data_[i] = temp[i];
			}
			else
				this->cur_size_ = new_size;
		}	
		//If "else" block executes then cur_size_ > new_size
		else
			this->cur_size_ = new_size;
	}
}

//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{
	if (this != &rhs)
	{	
		if	(this->cur_size_ == rhs.cur_size_)
		{
				//If at least one difference exists between both array's data then return false
				for (int i = 0; i < this->cur_size_; i++)
				{
					if (this->data_[i] != rhs.data_[i])
						return false;
				}
				return true;
		}
		else 
			return false;
	}
	//If else block below executes, then the array is being compared to itself
	else
		return true;
}

//
// operator !=
//
template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{
	if (*(this) == rhs)
		return false;
	else
		return true;
}

//
// shrink
//
template <typename T>
void Array<T>::shrink (void)
{
  
  /*
	The data is copied into a temporary location, then its original version is deleted.
	New space is allocated for the data, then it is copied from its temporary location to that new location.
	The new space that was allocated is exactly equal to cur_size_ in order to reclaim unused space.
	Max size is changed to current size because the rest of the space was given up
  */
  
	T temp[this->cur_size_];
	
	for (int i = 0; i < this->cur_size_; i ++)
		temp[i] = this->data_[i];

	delete [] this->data_;
	
	//The memory allocated for "data_" will be exactly what the cur_size_ is
	this->data_ = new T[this->cur_size_];
	
	//The data is copied back to "data_" 
	for (int i = 0; i < this->cur_size_; i ++)
		this->data_[i] = temp[i];
	
	//Max size becomes the current size because unused space was reclaimed
	this->max_size_ = this->cur_size_;
}

//
// slice (size_t,size_t)
//
template <typename T>
Array<T> Array<T>::slice (size_t begin, size_t end) const
{
	
	//Size variable of the returned Fixed Array
	size_t new_size = end-begin+1;
	
	Array <T> * newArr = new Array <T>(new_size);
	
	//Shallow copy of array's data is created
	newArr->data_ = this->data_+begin;
	return *newArr; 
}




