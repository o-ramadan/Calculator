// -*- C++ -*-
// $Id: Binary_Op_Command.h 

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS363_BINARYOPCOMMAND_H_
#define _CS363_BINARYOPCOMMAND_H_

/**
 * @class Binary_Op_Command
 *
 * 
 */
 
#include "Stack.h"
#include "Expr_Command.h"

#define ADDSUBTRACTPRECEDENCE (1)
#define MULTIPLYDIVIDEMODULUSPRECEDENCE (2)

class Binary_Op_Command : public Expr_Command
{

protected:
	
  /**
   * Copy constructor
   *
   * @param[in]     s         The source stack containing elements in postfix order.
   * @param[in]		p  		  Precedence of operator (2 for *,/,% and 1 for +,-)
   */
	Binary_Op_Command(Stack <int> & s, int p);
	
	///Virtual destructor to enable polymorphic behavior
	virtual ~Binary_Op_Command(void);
	
public:
	
    ///Execute binary operation
	void execute (void);
	
	///Return result of operation
	virtual int evaluate (int n1, int n2) const = 0;
	
	///Precedence getter
	int getPrecedence(void); 
	
private:
	Stack <int> & s_; 
	
	int precedence;
};

#endif 