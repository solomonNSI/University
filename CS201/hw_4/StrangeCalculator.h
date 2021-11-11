//
// Created by Suleyman Hanyyev on 14.05.2021.
//
//
#ifndef CS201_HW4_STRANGECALCULATOR_H
#define CS201_HW4_STRANGECALCULATOR_H



#include <iostream>
#include <string>
#include "Stack.h"
#include <cstdlib>
#include <cctype>
#include <algorithm>
using namespace std;

    string infix2prefix(const string exp);
    double evaluatePrefix( const string exp);

    bool isBalancedInfix(const string exp);
    void evaluateInputPrefixExpression();

    int isOperand(string x);
    int levelOrder(string x);
    string reverse(string exp);

#endif //CS201_HW4_STRANGECALCULATOR_H
