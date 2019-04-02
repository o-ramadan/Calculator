// -*- C++ -*-
// $Id: Add_Command.h 

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS363_ADDCOMMAND_H_
#define _CS363_ADDCOMMAND_H_

/**
 * @class Add_Command
 *
 * 
 */

#include "Binary_Op_Command.h"

class Add_Command : public Binary_Op_Command
{
	public:
		///Copy constructor
		Add_Command (Stack <int> & s);
		
		///Destructor
		~Add_Command (void);
		
		///Return n1+n2
		virtual int evaluate (int n1, int n2) const;
};

#endif