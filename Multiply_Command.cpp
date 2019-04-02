// $Id: Multiply_Command.cpp 

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Multiply_Command
//

#include "Multiply_Command.h"

//
// Multiply_Command (Stack <int> &)
//
Multiply_Command::Multiply_Command (Stack <int> & s)
: Binary_Op_Command ( s , MULTIPLYDIVIDEMODULUSPRECEDENCE )
{
}

//
// ~Multiply_Command
//
Multiply_Command::~Multiply_Command (void)
{
}

//
// evaluate
//
int Multiply_Command::evaluate (int n1, int n2) const
{
	return (n1 * n2);
} 

