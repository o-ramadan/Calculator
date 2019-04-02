// -*- C++ -*-
// $Id: Calculator.h 

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS363_CALCULATOR_H_
#define _CS363_CALCULATOR_H_

/**
 * @class Calculator
 *
 * 
 */

#include "Stack_Expr_Command_Factory.h"
#include "Array.h"
#include "Stack.h"
#include "Num_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulus_Command.h"
#include <sstream>     			 // std::istringstream
#include <string>       		// std::string
#include <cstring> 				// size_t definition

 
class Calculator
{
	public:
		///Copy constructor
		Calculator (void);
		
		///Destructor
		~Calculator (void);
		
		bool infix_to_postfix (const std::string & infix,Expr_Command_Factory & factory, Array <Expr_Command *> & postfix);
};
#endif