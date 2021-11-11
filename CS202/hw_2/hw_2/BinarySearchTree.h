#ifndef  _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE
#include "BinaryNode.h"
#include <iostream>

/*
 *  * Title: Binary Search Trees
 *   * Author: Suleyman Hanyyev
 *    * ID: 21901009
 *     * Section: 1
 *      * Assignment: 2
 *       * Description: design of the BST
 *        */

using namespace std;

class BinarySearchTree{
    
private:
    BinaryNode* rootPtr;
protected:
//........................................
//Helper methods
//........................................
    void destroyTree(BinaryNode* subTreePtr);
    int getHeightHelper(BinaryNode* subTreePtr) const;
    int getNumberOfNodesHelper(BinaryNode* subTreePtr) const;
    BinaryNode* insertInOrder(BinaryNode* subTreePtr, BinaryNode* newNodePtr);  
    bool search( BinaryNode* treePtr, const int anEntrY);
    void preorder(BinaryNode* treePtr) const;
    void inorder(BinaryNode* treePtr) const;
    void postorder(BinaryNode* treePtr) const;
    BinaryNode* copyTree(const BinaryNode* treePtr)const;
    BinaryNode* removeLeftmostNode(BinaryNode* nodePtr, int &inorderSuccesssor);
    BinaryNode* removeNode(BinaryNode* nodePtr);
    BinaryNode* removeValue(BinaryNode* subTreePtr, int target, bool &success);
    void printlevelorder(BinaryNode* ptr);
    void printlevelorderHelper(BinaryNode* ptr, int level);

    void spanHelper( const int a, const int b, BinaryNode* ptr, int &count);
    void mirrorHelper(BinaryNode* ptr);
public:
    //Constructors
    BinarySearchTree(); //Default
    BinarySearchTree(const int rootItem);
    BinarySearchTree(const int rootItem, BinarySearchTree* leftPtr, BinarySearchTree* rightPtr);
    
    BinarySearchTree(const BinarySearchTree& tree);

    //Destructor
    ~BinarySearchTree();
    
//........................................
//Homework assigned methods
//........................................
    
    //test whether the bst is empty. Empty = true
    bool isEmpty();

    //return the height of the BST
    int getHeight();

    //returns the number of nodes of BST
    int getNumberOfNodes();

    //if addition succesfull - return true.
    //if the item exists, don't add
    bool add( const int newEntry);

    // if removal succesfull - return true;
    bool remove(const int anEntry);

    // contains - true;
    bool contains(const int anEntry);

    // node, left , right
    void preorderTraverse();

    //left, node, right
    void inorderTraverse();

    //left,right,node
    void postorderTraverse();

    // print each level of nodes
    void levelorderTraverse();

    // returns the number of elements in the BST
    // that are >= a and <= b
    int span(const int a, const int b);

    void mirror();

   BinarySearchTree& operator=(const BinarySearchTree& rightHandSide);
};
#endif
