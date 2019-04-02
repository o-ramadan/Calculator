// $Id: Subtract_Command.cpp 

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Subtract_Command
//

#include "Subtract_Command.h"


//
// Subtract_Command (Stack <int> &)
//
Subtract_Command::Subtract_Command (Stack <int> & s)
: Binary_Op_Command ( s, ADDSUBTRACTPRECEDENCE )
{
}

//
// ~Subtract_Command
//
Subtract_Command::~Subtract_Command (void)
{
}

//
// evaluate
//
int Subtract_Command::evaluate (int n1, int n2) const
{
	return n1 - n2;
} 

