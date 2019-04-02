// $Id: Stack_Expr_Command_Factory.cpp 

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack_Expr_Command_Factory
//

#include "Stack_Expr_Command_Factory.h"


//
// Stack_Expr_Command_Factory (Stack <int> &)
//
Stack_Expr_Command_Factory::Stack_Expr_Command_Factory (Stack <int> & s)
: stack_ (s)
{
}

//
// ~Stack_Expr_Command_Factory
//
Stack_Expr_Command_Factory::~Stack_Expr_Command_Factory (void)
{
	
}

Num_Command * Stack_Expr_Command_Factory::create_num_command (int num)
{
	Num_Command * e = new Num_Command (stack_, num);
	
	return e;
}
	 
Add_Command * Stack_Expr_Command_Factory::create_add_command (void)
{
	return new Add_Command (stack_);;
}

Subtract_Command * Stack_Expr_Command_Factory::create_subtract_command (void)
{
	Subtract_Command * e = new Subtract_Command (stack_);
	
	return e;	
}

Multiply_Command * Stack_Expr_Command_Factory::create_multiply_command (void)
{
	Multiply_Command * e = new Multiply_Command (stack_);
	
	return e;	
}

Divide_Command * Stack_Expr_Command_Factory::create_divide_command (void)
{
	Divide_Command * e = new Divide_Command (stack_);
	
	return e;	
}

Modulus_Command * Stack_Expr_Command_Factory::create_modulus_command (void)
{
	Modulus_Command * e = new Modulus_Command (stack_);
	
	return e;	
}