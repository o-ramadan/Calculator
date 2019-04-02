// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//

//#include "Stack.h"

#define DEF_SIZE (5)
#define INIT_TOP (-1)

template <typename T>
Stack <T>::Stack (void)
:	stack_arr (DEF_SIZE),		//Default Array constructor creates array with current size = 5
	max_size (DEF_SIZE),
	stack_top(INIT_TOP)
{

}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
:	stack_arr(stack.max_size),
	max_size(stack.max_size),
	stack_top(stack.stack_top)
{
	this->stack_arr = stack.stack_arr;
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
  // COMMENT You do not delete data members declared on the stack.
  
  // ADDRESSED COMMENT Removed the line below from code. It is commented out (and not deleted) to show the changes made
		//delete stack_arr;
		
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
	//If max size is reached then array needs to be resized
	if(stack_top == (max_size -  1))
	{	
		//If statement because if maxsize = 0 then if multiplied by 2, it remains 0
		if (max_size == 0)
		{
			stack_arr.resize(5);
			max_size = 5;
		}
		
		else
		{
			stack_arr.resize(2 * max_size);
			max_size = 2 * max_size;
		}
	}	
	
	//Increment top of stack then push the data element onto the stack
	stack_arr[++stack_top] = element;
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
		if(is_empty()) 
			throw empty_exception("Stack already empty - cannot pop!");
		
		//store the value of the data element.	
		else
			stack_top--;
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	if (this != &rhs)
	{
    // COMMENT It would be easier if you just use the assignment operator
    // on the array to copy things from rhs.
	
	// ADDRESSED COMMENT used array assignment operator below

	this->max_size = rhs.max_size;		
	
	this->stack_top = rhs.stack_top;

	this->stack_arr = rhs.stack_arr;
	}
	
	return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
  // COMMENT Just reset the variables instead popping each element, which
  // is expensive.
  
  // ADDRESSED COMMENT reset the variables
  stack_top = -1;
  max_size = 0;
  stack_arr.resize(0);
  
}
