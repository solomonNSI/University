//
// Created by Suleyman Hanyyev on 14.05.2021.
//

#include "StrangeCalculator.h"
#include <sstream>  // for string streams
using namespace std;

string infix2prefix(const string exp){
    //create a stack
    Stack aStack;

    //temp variable for reversing the exp
    string temp = exp;
    string infix = reverse(temp);
    //the prefix form
    string prefix;
    string top;

    //infix2prefix
    for( int i = 0; i < infix.length(); i++){
        string s(1, infix[i]);
        if(s == "("){
            aStack.push(s);
        }else if( s == ")"){
            aStack.getTop( top);
            //while top of a stack is not )
            while( top != "("){
                prefix += top;
                aStack.pop();
                aStack.getTop(top);
            }
            aStack.pop();
            //stack.pop = remove the open paranthesis
        } else if(isOperand(s)){
            prefix += infix[i];
        } else if(!isOperand(s)){
            if(aStack.isEmpty())
                aStack.push(s);
            else{
                aStack.getTop(top);
                if(levelOrder(s) > levelOrder(top))
                    aStack.push(s);
                else if(levelOrder(s) <= levelOrder(top)){
                    while( !aStack.isEmpty() && levelOrder(s) <= levelOrder(top)){
                        prefix += top;
                        aStack.pop();
                        aStack.getTop(top);
                    }
                    aStack.push(s);
                }
            }
        }
    }
    while( !aStack.isEmpty()){
        aStack.getTop(top);
        prefix += top;
        aStack.pop();
    }
    return reverse(prefix);
}

double evaluatePrefix( const string exp){
    //reverse the prefix
    //then check if it is operand or operator
    //if operand, push to the stack
    //else, perform operation
    string prefix = exp;
    Stack aStack;
    for( int i = prefix.length() -1 ; i >= 0; i--){
        string s(1, prefix[i]);
        if(isOperand(s)){
            aStack.push(s);
        }else{
            string var1, var2;
            aStack.pop(var1);
            aStack.pop(var2);
            double t = atof(var1.c_str());
            double t2 = atof(var2.c_str());
            double sum;
            if( s == "+")
                sum = t + t2;
            else if( s == "-")
                sum = t - t2;
            else if( s == "*")
                sum = t * t2;
            else if( s == "/")
                sum =  t / t2;
            
            ostringstream str1;
            str1<<sum;
            string last = str1.str();
            aStack.push(last);
        }
    }
    string result;
    aStack.pop(result);
    return atof(result.c_str());
}

void evaluateInputPrefixExpression(){
    //    This function (i) asks the user for an infix input,
    string exp;
    cout<< "Enter the infix expression: "<<endl;
    getline(cin,exp);
    int size = exp.length();

    //(ii) removes the possible spaces in the input,
    exp.erase(remove_if(exp.begin(), exp.end(),::isspace), exp.end());
    cout<<"here the exp is" <<exp<<endl;
    //    (iii) checks if the expression has a balanced number of parentheses
    //    using isBalancedInfix function (if not give a warning)
    if(isBalancedInfix(exp)){
    //    (iv) if the input is of correct format,
    //    converts the input infix expression to prefix using infix2prefix
    string prefix = infix2prefix(exp);
    cout<< "The Prefix Expression:" << prefix<<endl;

    //    (v) and computes the final result using evaluatePrefix.
    cout<< "The result is: "<< evaluatePrefix(prefix);
    }else
        cout<< "The expression is not balanced";

}

bool isBalancedInfix(const string exp) {
    Stack stack;
    bool sofar = true;
    int i = 0;

    while(sofar && i < exp.length()){
        char ch = exp[i];
        i++;

        if(ch == '(')
            stack.push("(");
        else if(ch == ')') {
            if (!stack.isEmpty())
                stack.pop();
            else
                sofar = false;
        }
    }
    if(sofar && stack.isEmpty())
        return true;
    else
        return false;
}

int isOperand(string x){
    if( x == "+" || x == "-" || x == "*" || x == "/")
        return 0;
    else return 1;
}

int levelOrder( string x){
    int level = 0;
    if( x == "+" || x == "-")
        level = 1;
    else if( x == "*" || x == "/")
        level = 2;
    else if( x == "(" || x == ")")
        level = -1;
    else
        level = 0;

    return level;
}

string reverse( string exp) {
    int size = exp.length();
    string reverse = "";
    for (int i = size - 1; i >= 0; i--) {
        if (exp[i] == '(')
            reverse += ")";
        else if (exp[i] == ')')
            reverse += "(";
        else
            reverse += exp[i];
    }
    return reverse;
}

