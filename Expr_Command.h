// -*- C++ -*-
// $Id: Expr_Command.h 

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS363_EXPRCOMMAND_H_
#define _CS363_EXPRCOMMAND_H_

/**
 * @class Expr_Command
 *
 * 
 */
 
class Expr_Command
{  
	public:
	
		///Default constructor
		Expr_Command(void);
		
		///Virtual destructor to enable polymorphic behavior
		virtual ~Expr_Command(void);
	
		///Polymorphic execute method depends on type of object
		virtual void execute (void) = 0;
		
		virtual int getPrecedence(void);
}; 

#endif