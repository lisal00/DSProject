#include "infix.h"
#include <stack>
#include <string>
#include <sstream>
#include <cctype>
#include <stdexcept>

using std::istringstream;
using std::string; 
using namespace std;

const string infix::OPERATORS = "+-*/%"; 
const int infix::PRECEDENCE[] = {1, 1, 2, 2, 2};

const string infix::open_bracket = "({[";
const string infix::closed_bracket = ")}]";

/**Extract and processes each char in infix and return equivalent postfix str
 * @param expression The infix expression
 * @return The equivalent postfix expression
 * @throw invalid_argument
*/
string infix::convert(const string& expression){
    postfix = "";
    while (!operator_stack.empty()){ 
        operator_stack.pop();
    }
    istringstream infix_tokens(expression);
    string next_token;

    while (infix_tokens >> next_token){
        if (isalnum(next_token[0])){ //checks if token is a number and then adds to postfix
            postfix += next_token;
            postfix += " ";
        } else if (is_operator(next_token[0]) || is_openbr(next_token[0]) || is_closedbr(next_token[0])){ //else, checks if operator or bracket
            process_operator(next_token[0]);
        } else { //else, throws exception
            throw invalid_argument("Unexpected character encountered.");
        }
    }
    while(!operator_stack.empty()){ //pop any remaining operators and append them to post fix
        char op = operator_stack.top();
        operator_stack.pop();
        postfix += op;
        postfix += " ";
    }
    return postfix;
}

/**Process operators
 * @param op The operator
 * @throw invalid_argument
*/
void infix::process_operator(char op){
    if (operator_stack.empty() || is_openbr(op)){ //if stack is empty or operator is opening bracket
        if (is_closedbr(op)){
            throw invalid_argument("Unmatched closed parenthesis");
        }
        operator_stack.push(op); //pushes operator/bracket onto stack
    } else{ 
        if (precedence(op) > precedence(operator_stack.top())){
            operator_stack.push(op);
        }else{ //pop all stacked operators with equal or higher precedence than op
            while (!operator_stack.empty() && (!is_openbr(operator_stack.top())) 
            && (precedence(op) <= precedence(operator_stack.top()))){ //checks if !empty, top of stack != open bracket, and precedences 
                postfix += operator_stack.top();
                postfix += " ";
                operator_stack.pop();
            }
            if (is_closedbr(op)) { //if the operator is a closed bracket
                if (!operator_stack.empty() && is_openbr(operator_stack.top())){ //if stack not empty and top is open bracket
                    operator_stack.pop();
                } else{
                    throw invalid_argument("Unmatched closed parenthesis");
                }
            }
            /**assert: operator stack is empty or 
             * current operator precedence > top of stack operator precedence
             * also checks if op != closed bracket to prevent closed bracket from being added to postfix string
            */
            if (!is_closedbr(op))
                operator_stack.push(op); 
        }
    }
}
