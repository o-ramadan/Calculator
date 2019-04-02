// -*- C++ -*-
// $Id: Num_Command.h 

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS363_NUMCOMMAND_H_
#define _CS363_NUMCOMMAND_H_

/**
 * @class Num_Command
 *
 * 
 */
 
#include "Stack.h"
#include "Expr_Command.h"

class Num_Command : public Expr_Command
{
	
public:

	///Copy constructor
	Num_Command (Stack <int> & s, int n);
	
	///Destructor
	~Num_Command (void);
 
	///Pushes number onto stack
	virtual void execute (void);
	
	///Precedence getter
	int getPrecedence(); 
	
private:
	///Stack containing mathematical expression in postfix form
	Stack <int> & s_;
	
	///Number to be pushed onto stack
	int n_;
};

#endif