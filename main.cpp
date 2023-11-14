#include <iostream>
#include "balanced.h"
#include "infix.h"
#include "calculator.h"

using namespace std;

int main(){
    infix infix;
    calculator calculate;
  
    cout << "Enter an expression. \n";
    string expression; 
    string postfix;

    while (getline(cin, expression) && (expression != "")){
        cout << expression;
        if (is_balanced(expression)){
            cout << " is balanced.\n";
            postfix = infix.convert(expression);
            cout << "\nInfix to postfix: " << postfix << endl;
            //perform calculator function 
            int res = calculate.eval(postfix);
            cout << res << endl;
        } else{
            cout << " is not balanced. Invalid. \n";
        }
        cout << "\nEnter another expression: ";
    }
    return 0;
}

// #include <iostream> 
//thats so not slay queen