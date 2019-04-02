// $Id: Binary_Op_Command.cpp 

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Binary_Op_Command
//

#include "Binary_Op_Command.h"
//
// Binary_Op_Command
//
Binary_Op_Command::Binary_Op_Command (Stack <int> & s, int p)
:	s_ (s), 
	precedence (p)
{ 
}

//
// ~Binary_Op_Command
//
Binary_Op_Command::~Binary_Op_Command (void)
{
}
 
//
// execute
// 
void Binary_Op_Command::execute (void)
 {
	 //Pop 2 elements off stack, execute binary operation on them, then push result to stack
	int n2 = s_.top ();
	s_.pop();
	 
	int n1 = s_.top();
	s_.pop();
	
	int result = this->evaluate(n1, n2);
	
	s_.push (result);
 }
 
 int Binary_Op_Command::getPrecedence(void)
 {
	 return precedence;
 }