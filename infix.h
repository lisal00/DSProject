#ifndef INFIX_H_
#define INFIX_H_

#include <stack>
#include <string>
#include <sstream>
#include <cctype>
#include <stdexcept>

using std::istringstream;
using std::string;
using namespace std;

class infix{
    public:
        /**Extract and processes each char in infix and return equivalent postfix str
         * @param expression The infix expression
         * @return The equivalent postfix expression
        */
        string convert(const string& expression);

    private:
        /**Process operators
         * @param op The operator
        */
        void process_operator(char op);

        /**Determines if char is an operator
        * @param ch The char to be tested
        * @return true if the char is operator
        */
        bool is_operator(char ch) const{
            return OPERATORS.find(ch) != string::npos;
        }

        /**Determines the precendence of an operator
         * @param op the operator
         * @return The precedence
         */
        int precedence(char op) const{
            return PRECEDENCE[OPERATORS.find(op)];
        }

        /**Determines if char is closed bracket
         * @param ch The char to be tested
         * @return true If the char is closed bracket
        */
        bool is_closedbr(char ch){
            return closed_bracket.find(ch) != string::npos;
        }

        /**Determines if char is open bracket
         * @param ch The char to be tested
         * @return true If the char is open bracket
        */
        bool is_openbr(char ch){
            return open_bracket.find(ch) != string::npos;
        }

        /**variables*/
        static const string open_bracket;
        static const string closed_bracket;   
        static const string OPERATORS;
        static const int PRECEDENCE[];
        stack<char> operator_stack;
        string postfix;
};

#endif