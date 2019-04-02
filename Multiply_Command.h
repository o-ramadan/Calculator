// -*- C++ -*-
// $Id: Multiply_Command.h 

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS363_MULTIPLYCOMMAND_H_
#define _CS363_MULTIPLYCOMMAND_H_

/**
 * @class Multiply_Command
 *
 * 
 */

#include "Binary_Op_Command.h"
 

class Multiply_Command : public Binary_Op_Command
{
	public:
		///Copy constructor
		Multiply_Command (Stack <int> & s);
		
		///Destructor
		~Multiply_Command (void);
		
		///Return n1*n2
		virtual int evaluate (int n1, int n2) const;
};

#endif