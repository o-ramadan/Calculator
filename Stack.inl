// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
	return (this->stack_top) + 1;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
	if(is_empty() == 1)
		throw empty_exception("Stack is empty");

	return stack_arr[stack_top];
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
	return (stack_top == -1);
}
