// $Id: Divide_Command.cpp 

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Divide_Command
//

#include "Divide_Command.h"

//
// Divide_Command (Stack <int> &)
//
Divide_Command::Divide_Command (Stack <int> & s)
: Binary_Op_Command (s, MULTIPLYDIVIDEMODULUSPRECEDENCE )
{
}

//
// ~Divide_Command
//
Divide_Command::~Divide_Command (void)
{
}

//
// evaluate
//
int Divide_Command::evaluate (int n1, int n2) const
{
	if ( n2 == 0 )
		throw std::runtime_error("Division by zero");
	
	return n1 / n2;
} 

