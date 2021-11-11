#include "BinaryNode.h"
/*
 *  * Title: Binary Search Trees
 *   * Author: Suleyman Hanyyev
 *    * ID: 21901009
 *     * Section: 1
 *      * Assignment: 2
 *       * Description: implementation of the nodes
 *        */
//default constructor
BinaryNode::BinaryNode(){
    item = 0;
    leftChildPtr = NULL;
    rightChildPtr = NULL;
}
//constructor with item in the argument
BinaryNode:: BinaryNode(const int& Item){
    item = Item;
    leftChildPtr = NULL;
    rightChildPtr = NULL;
}
// constructore with an item and l/r pointers
BinaryNode:: BinaryNode(const int& Item, BinaryNode* leftPtr, BinaryNode* rightPtr){
    item = Item;
    leftChildPtr = leftPtr;
    rightChildPtr = rightPtr;
}

void BinaryNode::setItem(const int& Item){
    item = Item;
}

int BinaryNode::getItem() const {
    return item;
}

BinaryNode* BinaryNode::getLeftChildPtr() const {
    return leftChildPtr;
}
    
BinaryNode* BinaryNode::getRightChildPtr() const{
    return rightChildPtr;
}

void BinaryNode::setLeftChildPtr(BinaryNode* leftPtr){
    leftChildPtr = leftPtr;
}

void BinaryNode::setRightChildPtr(BinaryNode* rightPtr){
    rightChildPtr = rightPtr;
}


