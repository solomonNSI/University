//
// Created by Suleyman Hanyyev on 14.05.2021.
//
#include "Stack.h"
#include <string>

Stack::Stack() {
    topPtr = NULL;
}
Stack::Stack(const Stack &aStack) {
    if(aStack.topPtr == NULL)
        topPtr = NULL;
    else{
        //first node copied
        topPtr = new StackNode;
        topPtr->item = aStack.topPtr->item;

        //the rest of the stack
        StackNode *newPtr = topPtr;
        for(StackNode *origPtr = aStack.topPtr->next;
                        origPtr != NULL;
                        origPtr = origPtr->next){
            newPtr->next = new StackNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }
        newPtr->next = NULL;
    }
}

Stack::~Stack() {
    while( !isEmpty())
        pop();
}

bool Stack::isEmpty() const {
    return topPtr == NULL;
}

bool Stack:: push(string newItem){
    //create a new node
    StackNode *newPtr = new StackNode;

    //set data portion of new node
    newPtr->item = newItem;

    //insert new node
    newPtr->next = topPtr;
    topPtr = newPtr;

    return true;
}

bool Stack::pop() {
    if(isEmpty())
        return false;

    //stack not empty - delete top
    else {
        StackNode *temp = topPtr;
        topPtr = topPtr->next;
        //return deleted node to system
        temp->next = NULL; //safeguard
        delete temp;
        return true;
    }
}

bool Stack::pop(string &stackTop) {
    if(isEmpty())
        return false;
    else{
        stackTop = topPtr->item;
        StackNode *temp = topPtr;
        topPtr = topPtr->next;

        temp->next = NULL;
        delete temp;
        return true;
    }
}

bool Stack::getTop( string &stackTop) const{
    if(isEmpty())
        return false;

    else{
        stackTop = topPtr->item;
        return true;
    }
}