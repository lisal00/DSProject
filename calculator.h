#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <stack>
#include <string>
using namespace std;

class calculator
{
public:
  /**Evaluates a postfix expression
  @param expression The expression to be evaluated
  @return The value of the expression
  @throw error
  */
  int eval(std::string &expression);

private:
  /**Evalutes the current operator. Pops 2 operands off operand stack
  and applies the operator
  @param op A char representing the operator
  @throws error
  */
  int eval_op(char op);

  /**Determines whether a char is an operator
  @param ch The char to be tested
  @return true If the char is an operator
  */
  bool is_operator(char ch) const
  {
    return OPERATORS.find(ch) != string::npos;
  }
  static const string OPERATORS;
  stack<int> operand_stack;
};

#endif