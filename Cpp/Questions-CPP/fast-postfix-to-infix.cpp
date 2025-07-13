#include <iostream>
#include <stack>
#include <string>
#include <sstream>

// Helper function to check if a string is an operator
bool isOperator(const std::string &token)
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

// Helper function to check if a string is a valid operand (positive integer)
bool isValidOperand(const std::string &token)
{
    if (token.empty())
        return false;
    for (char c : token)
    {
        if (!std::isdigit(c))
            return false;
    }
    return true;
}

int main()
{
    // Step 1: Read the postfix expression
    std::string postfix_expression;
    std::getline(std::cin, postfix_expression);

    // Step 2: Initialize a stack to store intermediate infix expressions
    std::stack<std::string> expression_stack;

    // Step 3: Parse the postfix expression using stringstream
    std::stringstream ss(postfix_expression);
    std::string token;

    // Step 4: Process each token in the postfix expression
    while (ss >> token)
    {
        if (isOperator(token))
        {
            // Step 4a: It's an operator - we need exactly two operands
            if (expression_stack.size() < 2)
            {
                std::cout << "Error: Not enough operands for operator " << token << std::endl;
                return 1;
            }

            // Pop two operands from the stack
            // Note: In postfix, the second operand is on top of stack
            std::string operand2 = expression_stack.top();
            expression_stack.pop();
            std::string operand1 = expression_stack.top();
            expression_stack.pop();

            // Create the infix expression with parentheses for clarity
            std::string infix_expr = "(" + operand1 + " " + token + " " + operand2 + ")";

            // Push the new infix expression back onto the stack
            expression_stack.push(infix_expr);
        }
        else if (isValidOperand(token))
        {
            // Step 4b: It's a valid operand (number) - push it onto the stack
            expression_stack.push(token);
        }
        else
        {
            // Step 4c: Invalid token
            std::cout << "Error: Invalid token '" << token << "'" << std::endl;
            return 1;
        }
    }

    // Step 5: Check if we have exactly one expression left (valid postfix)
    if (expression_stack.size() == 0)
    {
        std::cout << "Error: Empty postfix expression" << std::endl;
        return 1;
    }
    else if (expression_stack.size() > 1)
    {
        std::cout << "Error: Too many operands (incomplete expression)" << std::endl;
        return 1;
    }

    // Step 6: Output the final infix expression
    std::cout << expression_stack.top() << std::endl;

    return 0;
}
