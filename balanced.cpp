#include <stack>
#include <string>
#include "balanced.h"
using namespace std;

/**Determines if a char is opening bracket
 * @param ch Character to be tested
 * @return true If the char is an opening bracket
*/
bool is_open(char ch){
    return OPEN.find(ch) != string::npos;
}

/**Determines if a char is a closing bracket
 * @param ch Character to be tested
 * @return true If the char is a closing bracket
*/
bool is_close(char ch){
    return CLOSE.find(ch) != string::npos;
}

/**Tests the input str to see that it is balanced.
 * ( is matched with ), [ is matched with ], { is matched with }.
 * @param expression A str that has the expression to be examined
 * @return true If all brackets match 
*/
bool is_balanced(const string& expression){
    stack<char> st1;
    bool balanced = true;

    string::const_iterator iter = expression.begin();
    while (balanced && (iter != expression.end())){
        char next_char = *iter;
        if (is_open(next_char)){ //if char is open bracket, push char onto stack
            st1.push(next_char);
        } else if (is_close(next_char)){ //else, checks if char is closed bracket
            if (st1.empty()){   //if stack is empty, balanced is false
                balanced = false;
            } else{ //else, pop stack
                char top_ch = st1.top();
                st1.pop();
                balanced = (OPEN.find(top_ch) == CLOSE.find(next_char));
            }
        }
        ++iter;
    }
    return balanced && st1.empty();
}