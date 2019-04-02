// -*- C++ -*-
// $Id: Expr_Command_Factory.h 

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS363_EXPRCOMMANDFACTORY_H_
#define _CS363_EXPRCOMMANDFACTORY_H_

/**
 * @class Expr_Command_Factory
 *
 * 
 */


#include "Num_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulus_Command.h"
#include  <exception>		//For division by zero

class Expr_Command_Factory
{
public:
	 virtual ~Expr_Command_Factory (void) = 0;
	 
	 virtual Num_Command * create_num_command (int num) = 0;
	 
	 virtual Add_Command * create_add_command (void) = 0;
	 
	 virtual Subtract_Command * create_subtract_command (void) = 0;
	 
	 virtual Multiply_Command * create_multiply_command (void) = 0;
	 
	 virtual Divide_Command * create_divide_command (void) = 0;

	 virtual Modulus_Command * create_modulus_command (void) = 0;
	   
protected:
	Expr_Command_Factory(void);
	
private:
 // prevent the following operations
	Expr_Command_Factory (const Expr_Command_Factory &);
 
	const Expr_Command_Factory & operator = (const Expr_Command_Factory &);
}; 

#endif