// -*- C++ -*-
// $Id: Stack_Expr_Command_Factory.h 

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS363_STACKEXPRCOMMANDFACTORY_H_
#define _CS363_STACKEXPRCOMMANDFACTORY_H_

/**
 * @class Stack_Expr_Command_Factory
 *
 * 
 */

#include "Expr_Command_Factory.h" 
 
class Stack_Expr_Command_Factory : public Expr_Command_Factory
{
	
public:

	 Stack_Expr_Command_Factory (Stack <int> & stack);
	 
	 ~Stack_Expr_Command_Factory (void);
	 
	 virtual Num_Command * create_num_command (int num);
	 
	 virtual Add_Command * create_add_command (void);
	 
	 virtual Subtract_Command * create_subtract_command (void);
	 
	 virtual Multiply_Command * create_multiply_command (void);
	 
	 virtual Divide_Command * create_divide_command (void);

	 virtual Modulus_Command * create_modulus_command (void);
	 
private:

	Stack <int> & stack_;
}; 

#endif