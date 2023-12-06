#include "calculator.h"
#include <cctype>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <algorithm>
#include <vector>

using namespace std;
using std::isdigit;
using std::istringstream;
using std::stack;

const std::string calculator::OPERATORS = "+-*/%";

/**Evaluates a postfix expression
@param expression The expression to be evaluated
@return The value of the expression
@throw error
*/
int calculator::eval(std::string &expression)
{
  // Be sure the stack is empty
  while (!operand_stack.empty())
  {
    operand_stack.pop();
  }
  // Process each token
  stringstream tokens(expression);
  char next_char;

  while (tokens >> next_char)
  {
    if (next_char == ' ')
      continue;

    if (isdigit(next_char)) // checks if next character is a digit and then put it back onto tokens
    {
      tokens.putback(next_char);
      int value;
      tokens >> value;
      operand_stack.push(value);
      // cout << "VALUE ADDED: " << value << endl;
    }
    else if (is_operator(next_char))
    {
      int result = eval_op(next_char);
      operand_stack.push(result);
    }
    else
    {
      throw invalid_argument("Invalid character encountered");
    }
  }
  if (!operand_stack.empty())
  {                                   // if operand stack has elements
    int answer = operand_stack.top(); // set to answer and pop
    operand_stack.pop();
    // cout << operand_stack.empty() << endl;
    // cout << "TEST: " << operand_stack.size() << endl;
    // cout << "TEST: " << operand_stack.top() << "." << endl;

    return answer;
  }
  else
  {
    throw invalid_argument("Stack is empty1");
  }
}

/**Evalutes the current operator. Pops 2 operands off operand stack
and applies the operator
@param op A char representing the operator
@throws error if top is attempted on empty stack
*/
int calculator::eval_op(char op)
{
  if (operand_stack.empty())
    throw invalid_argument("stack is empty2");
  int rhs = operand_stack.top();
  operand_stack.pop();
  if (operand_stack.empty())
    throw invalid_argument("stack is empty3");
  int lhs = operand_stack.top();
  int result = 0;

  switch (op)
  {
  case '+':
    result = lhs + rhs;
    break;
  case '-':
    result = lhs - rhs;
    break;
  case '*':
    result = lhs * rhs;
    break;
  case '/':
    result = lhs / rhs;
    break;
  case '%':
    result = lhs % rhs;
    break;
  }
  return result;
}
