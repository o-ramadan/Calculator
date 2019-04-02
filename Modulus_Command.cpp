// $Id: Modulus_Command.cpp 

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Modulus_Command
//

#include "Modulus_Command.h"


//
// Modulus_Command (Stack <int> &)
//
Modulus_Command::Modulus_Command (Stack <int> & s)
: Binary_Op_Command (s, MULTIPLYDIVIDEMODULUSPRECEDENCE )
{
}

//
// ~Modulus_Command
//
Modulus_Command::~Modulus_Command (void)
{
}

//
// evaluate
//
int Modulus_Command::evaluate (int n1, int n2) const
{
	if ( n2 == 0 )
		throw std::runtime_error("Division by zero");
	
	return n1 % n2;
} 

