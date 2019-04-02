// -*- C++ -*-
// $Id: driver.cpp

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================


#include <iostream>
#include "Stack.h"
#include <stdexcept>
#include <typeinfo>
#include <sstream>      // std::istringstream
#include <string>       // std::string
#include "Stack_Expr_Command_Factory.h"
#include "Expr_Command.h"
#include "Calculator.h"

int main()
{
	//Infix expression to be entered by user
	std::string infix;
	
	std::cout << "Enter expression:" << "\n";
	std::getline (std::cin,infix);
	
	//Stack that will store result at the end
	Stack <int> result;
	int res;
	
	//Calculator object that will convert infix to postfix
	Calculator calc;

	
	while (infix.compare("QUIT") != 0)
	{
		Stack_Expr_Command_Factory factory(result);
		Array <Expr_Command *> postfix;
			
    // COMMENT: Instead of using C functions to implement parts of the
    // calculator. It would be better suited to use a Wrapper Facade.
    
	//ADRESSED COMMENT: Made a wrapper called calculator that contains the infix_to_postfix method (hopefully that addresses the concern above)
	
		//Ensure expression entered is in the correct form
		if (calc.infix_to_postfix (infix, factory, postfix) == true)
		{
			// evaluate postfix
			res = result.top ();
			result.pop();
			
			std::cout << "Answer: " << res << "\n";
		}
		
		else
			std::cout << "Something went wrong. Try again!\n";
	
		std::cout << "\nEnter expression:\n";
		std::getline (std::cin,infix);
	}
	
	return 0;
}
