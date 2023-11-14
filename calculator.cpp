#include "calculator.h"
#include <cctype>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
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
int calculator::eval(const std::string &expression) {
  // Be sure the stack is empty
  while (!operand_stack.empty()) {
    operand_stack.pop();
  }
  // Process each token
  istringstream tokens(expression);
  char next_char;

  while (tokens >> next_char) {
    cout << "TEST next_char: " << next_char << endl;
    if (isdigit(next_char)) {    //
      tokens.putback(next_char); //
      int value;
      tokens >> value;
      operand_stack.push(value);
    } else if (is_operator(next_char)) {
      int result = eval_op(next_char);
      operand_stack.push(result);
    } else {
      throw invalid_argument("Invalid character encountered");
    }
  }
  if (!operand_stack.empty()) {       // if operand stack has elements
    int answer = operand_stack.top(); // set to answer and pop
    operand_stack.pop();
    cout << operand_stack.empty() << endl;
    cout << "TEST: " << operand_stack.size() << endl;
    cout << "TEST: " << operand_stack.top() << "." << endl;
    if (operand_stack.empty() || operand_stack.size() == 1) { // if operand stack is empty return answer
      return answer;
    } else {
      throw invalid_argument("Stack should be empty");
    }
  } else {
    throw invalid_argument("Stack is empty");
  }
} // user name quick quick quick quick quick quick quick quick
//from repository settings uh phucv2376

/**Evalutes the current operator. Pops 2 operands off operand stack
and applies the operator
@param op A char representing the operator
@throws error if top is attempted on empty stack
*/
int calculator::eval_op(char op) {
  if (operand_stack.empty())
    throw invalid_argument("stack is empty");
  int rhs = operand_stack.top();
  operand_stack.pop();
  if (operand_stack.empty())
    throw invalid_argument("stack is empty");
  int lhs = operand_stack.top();
  int result = 0;

  switch (op) {
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
