// $Id: Add_Command.cpp 

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Add_Command
//

#include "Add_Command.h"

//
// Add_Command (Stack <int> &)
//
Add_Command::Add_Command (Stack <int> & s)
: Binary_Op_Command ( s , ADDSUBTRACTPRECEDENCE )
{
}

//
// ~Add_Command
//
Add_Command::~Add_Command (void)
{
}

//
// evaluate
//
int Add_Command::evaluate (int n1, int n2) const
{
	return n1 + n2;
} 

