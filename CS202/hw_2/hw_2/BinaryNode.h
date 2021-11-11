#ifndef BINARYNODE_H
#define BINARYNODE_H
#include <iostream>

/*
 *  * Title: Binary Search Trees
 *   * Author: Suleyman Hannyev
 *    * ID: 21901009
 *     * Section: 1
 *      * Assignment: 2
 *       * Description: The nodes of the BST are designed here
 *        */
using namespace std;

class BinaryNode{
private:
    int item;
    BinaryNode* leftChildPtr;
    BinaryNode* rightChildPtr;
public:
    BinaryNode();
    BinaryNode(const int& Item);
    BinaryNode(const int& Item,BinaryNode* leftPtr, BinaryNode* rightPtr);

    void setItem(const int& Item);
    int getItem() const;

    BinaryNode* getLeftChildPtr() const;
    BinaryNode* getRightChildPtr() const;

    void setLeftChildPtr( BinaryNode* leftPtr);
    void setRightChildPtr( BinaryNode* rightPtr);

};

#endif
