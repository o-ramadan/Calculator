// -*- C++ -*-
// $Id: Subtract_Command.h 

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS363_SUBTRACTCOMMAND_H_
#define _CS363_SUBTRACTCOMMAND_H_

/**
 * @class Subtract_Command
 *
 * 
 */

#include "Binary_Op_Command.h"
 
class Subtract_Command : public Binary_Op_Command
{
	public:
		///Copy constructor
		Subtract_Command (Stack <int> & s);
		
		///Destructor
		~Subtract_Command (void);
		
		///Return n1-n2
		virtual int evaluate (int n1, int n2) const;
		
};

#endif