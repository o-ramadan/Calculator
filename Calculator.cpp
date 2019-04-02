// $Id: Calculator.cpp 

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Calculator.h"

//
// Calculator
//
Calculator::Calculator (void)
{
}

//
//~Calculator
//
Calculator::~Calculator (void)
{
}

//
// infix_to_postfix
//
bool Calculator::infix_to_postfix (const std::string & infix,Expr_Command_Factory & factory, Array <Expr_Command *> & postfix)
 {
	 //Delete trailing spaces
	 std::string infixNoTrailSpace = infix;
	 for (int i = infixNoTrailSpace.size() - 1; i >= 0; i--)
	 {
		if (infixNoTrailSpace.at(i) == ' ')
			infixNoTrailSpace.erase(i);
		else
			break;
	 }

	 //When true, the method will skip to the end and manage memory before returning
	 bool exitCondition = false;
	 
	 // create a input stream parser
	 std::istringstream input(infixNoTrailSpace); 
	 
	 // current token in string/stream
	 std::string token; 
	 
	 // created command object
	 Expr_Command * cmd = 0; 
	 
	 Stack <Expr_Command *> temp;
	 
	 size_t count = 0;
	 
	 while (!input.eof ())
	{
		//ensure array has enough space to accommodate more elements
		if (count ==  postfix.size() - 1)
			postfix.resize( 2 * postfix.size() );

		input >> token;
		
		//Create command according to user input
		if (token.compare("+") == 0)
			cmd = factory.create_add_command ();

		else if (token.compare("-") == 0)
			cmd = factory.create_subtract_command ();
		
		else if (token.compare("*") == 0)
			cmd = factory.create_multiply_command ();
		
		else if (token.compare("/") == 0)
			cmd = factory.create_divide_command ();
		
		else if (token.compare("%") == 0)
			cmd = factory.create_modulus_command ();
		
    // COMMENT: Create a design that does not require having parenthesis as
    // as command object since parenthesis are not executed.
	
	//ADDRESSED COMMENT: else-block below uses recursion to address this issue. It sends expressions within parenthesis
	// as an argument to the recursive method, evaluates it, then uses the result.
		else if (token.compare("(") == 0)
		{
			std::string RecursiveString;
			Stack <int> RecursiveStack;
			Stack_Expr_Command_Factory RecursiveFactory (RecursiveStack);
			Array <Expr_Command *> RecursivePostfix;
			
			//Ensure there are more characters after the left paranthesis
			if (!input.eof ())
				input >> token;
			else 
			{
				exitCondition = true;
				break;
			}	
			
			
			//Keep count of left parenthesis in expression that is going to be sent to sent to recursive method
			//This is done to ensure the right number of right parenthesis
			int LPcount = 0;
			
			while (!input.eof ())
			{
				if ( token.compare("(") == 0 )
					LPcount++;
				
				//For every '(', there must be a ')'
				if ( token.compare(")") == 0 )
				{
					if (LPcount == 0 )
						break;
					LPcount--;	
				}
				
				RecursiveString.append(token);
				RecursiveString.append(" ");
				input >> token;
			}
		
			if (RecursiveString.empty() || (infix_to_postfix (RecursiveString,RecursiveFactory,RecursivePostfix) == false))
			{
				exitCondition = true;
				break;
			}	
			
			//Take the result of the expression within the parenthesis and add it to the array 
			postfix[count++] = factory.create_num_command(RecursiveStack.top());
			
			//ensure array has enough space to accommodate more elements
			if (count ==  postfix.size() - 1)
				postfix.resize( 2 * postfix.size() );
			
			continue;
		}
		
    // COMMENT: Create a design that does not require having parenthesis as
    // as command object since parenthesis are not executed.
	
	//ADDRESSED COMMENT: (Comment was addressed in else-block above) else-block below uses recursion to address this issue.
	//It sends expressions within parenthesis as an argument to the recursive method, evaluates it, then uses the result.	
	
	// Check if it is a number
	else	
		{
			std::string::iterator it = token.begin();
			
			//Allow for negative numbers by skipping the initial char check in the subsequent for-loop if a negative num is entered
			if (*it == '-')
				++it;
			
			for (	; it != token.end(); ++it)
			{
				if (*it < '0' || *it > '9' )
				{
					exitCondition = true;
					break;
				}	
			}
			
			if (exitCondition == true)
				break;
			
			int num = stoi(token,nullptr);
			cmd = factory.create_num_command(num);	
			
			postfix[count++] = cmd;
			continue;
		}
				
		//Infix to postfix algorithm

		//If an operator is encountered (+,-,*,/,%)
		
		//If stack is empty or operator has higher precedence than top of stack, push operator
		if (temp.is_empty() ||  ( cmd->getPrecedence() > temp.top()->getPrecedence() ) )
			temp.push(cmd);

		//If operator has same precedence as top of stack, then pop top off stack and add to array, and push new operator onto stack
		else if (cmd->getPrecedence() == temp.top()->getPrecedence())
		{
			postfix[count++] = temp.top();
			temp.pop();
			temp.push(cmd);
		}
		
		else
		{	
			//Precedence lower than top of stack
			while ( !temp.is_empty() && (cmd->getPrecedence() <= temp.top()->getPrecedence() ) )
			{
				postfix[count++] = temp.top();
				temp.pop();
				
				if (count ==  postfix.size() - 1)
					postfix.resize( 2 * postfix.size() );
			}
			
			temp.push(cmd);
		}	
		
		if (count ==  postfix.size() - 1)
				postfix.resize( 2 * postfix.size() );
		
	}
	 
	//Pop remaining operators off stack and add to array after parsing is done
	while (!temp.is_empty())
	{
		postfix[count++] = temp.top();
		temp.pop();
		
		if (count ==  postfix.size() - 1)
			postfix.resize( 2 * postfix.size() ); 
	}
 
	//Execute the operations while ensuring that exceptions are caught
	size_t index = 0;
	try
	{
		while ( index < count )
		{
			postfix[index]->execute();
			delete postfix[index++];
		}
	}
	
	catch (std::exception& e)
	{
		//delete the rest of commands that were not deleted because of exception
		while ( index < count )
			delete postfix[index++];
		
		return false;
	}

	if ( exitCondition == true )
		return false;

	 return true;
}
