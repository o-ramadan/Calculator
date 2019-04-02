// $Id: Num_Command.cpp 

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Num_Command
//

#include "Num_Command.h"

//
// Num_Command
//

Num_Command::Num_Command (Stack <int> & s, int n)
:	s_ (s),
	n_ (n)
{
}

//
// ~Num_Command
//
Num_Command::~Num_Command (void)
{
}

//
//	execute
//
void Num_Command::execute (void)
{
	s_.push (this->n_); 
}

//
//	getPrecedence
//
int Num_Command::getPrecedence (void)
{
}








