//
// Created by Suleyman Hanyyev on 14.05.2021.
//

#ifndef CS201_HW4_STACK_H
#define CS201_HW4_STACK_H
#include <string>
using namespace std;


class Stack {
public:
    Stack();
    Stack(const Stack &aStack);
    ~Stack();

    bool isEmpty() const;
    bool push(string newItem);
    bool pop();
    bool pop(string &stackTop);
    bool getTop( string &stackTop) const;

private:
    struct StackNode{
        string item;
        StackNode* next;
    };
    StackNode* topPtr;
};


#endif //CS201_HW4_STACK_H
