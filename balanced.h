#ifndef BALANCED_H_
#define BALANCED_H_
#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*String with all open brackets*/
const string OPEN = "([{";

/*String with all closed brackets*/
const string CLOSE = ")]}";

/**Determines if a char is opening bracket
 * @param ch Character to be tested
 * @return true If the char is an opening bracket
*/
bool is_open(char ch);

/**Determines if a char is a closing bracket
 * @param ch Character to be tested
 * @return true If the char is a closing bracket
*/
bool is_close(char ch);

/**Tests the input str to see that it is balanced.
 * ( is matched with ), [ is matched with ], { is matched with }.
 * @param expression A str that has the expression to be examined
 * @return true If all brackets match 
*/
bool is_balanced(const string& expression);

#endif