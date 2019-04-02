// -*- C++ -*-
// $Id: Divide_Command.h 

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS363_DIVIDECOMMAND_H_
#define _CS363_DIVIDECOMMAND_H_

/**
 * @class Divide_Command
 *
 * 
 */

#include "Binary_Op_Command.h"
 
class Divide_Command : public Binary_Op_Command
{
	public:
		///Copy constructor
		Divide_Command (Stack <int> & s);
		
		///Destructor
		~Divide_Command (void);
		
		///Return n1/n2
		virtual int evaluate (int n1, int n2) const;
};

#endif