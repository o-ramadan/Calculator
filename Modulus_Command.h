// -*- C++ -*-
// $Id: Modulus_Command.h 

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS363_MODULUSCOMMAND_H_
#define _CS363_MODULUSCOMMAND_H_

/**
 * @class Modulus_Command
 *
 * 
 */

#include "Binary_Op_Command.h"
 
class Modulus_Command : public Binary_Op_Command
{
	public:
		///Copy constructor
		Modulus_Command (Stack <int> & s);
		
		///Destructor
		~Modulus_Command (void);
		
		///Return n1%n2
		virtual int evaluate (int n1, int n2) const;
};

#endif