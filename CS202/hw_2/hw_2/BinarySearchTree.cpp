#include "BinarySearchTree.h"

/*
 *  * Title: Binary Search Trees
 *   * Author: Suleyman Hanyyev
 *    * ID: 21901009
 *     * Section: 1
 *      * Assignment: 2
 *       * Description: Implementation file of BST.h
 *        */

//............................
//construcors

BinarySearchTree:: BinarySearchTree(){
    rootPtr = NULL;
}

BinarySearchTree:: BinarySearchTree(const int rootItem){
    rootPtr = new BinaryNode(rootItem);
	cout<< " new node created"<<endl;
}

BinarySearchTree:: BinarySearchTree(const int rootItem, BinarySearchTree* leftTreePtr, BinarySearchTree* rightTreePtr){
    rootPtr = new BinaryNode(rootItem, copyTree(leftTreePtr->rootPtr),copyTree(rightTreePtr->rootPtr));
}
//............................
//destructor
BinarySearchTree::~BinarySearchTree(){
    destroyTree(rootPtr);
}

BinaryNode* BinarySearchTree::copyTree(const BinaryNode* treePtr) const{ 
    BinaryNode* newTreePtr = NULL;
    // Copy tree nodes during a preorder traversal
    if (treePtr != NULL) {
    // Copy node
        newTreePtr = new BinaryNode(treePtr->getItem(), NULL, NULL);
        newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
        newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr())); 
    } 
    
        // Else tree is empty (newTreePtr is nullptr)
    return newTreePtr;
} // end copyTree

//copy constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree& treePtr){
    rootPtr = copyTree(treePtr.rootPtr);
} // end copy constructor

//..........................................................
//Helper methods
//......................................................    

void BinarySearchTree::destroyTree(BinaryNode* subTreePtr){
    if (subTreePtr != NULL) {
        destroyTree(subTreePtr->getLeftChildPtr()); destroyTree(subTreePtr->getRightChildPtr()); delete subTreePtr;
    } // end if
}// end destroyTree

int BinarySearchTree::getHeightHelper(BinaryNode* subTreePtr) const {
    if (subTreePtr == NULL) return 0;
    else
        return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()),
                       getHeightHelper(subTreePtr->getRightChildPtr())); 
}

int BinarySearchTree::getNumberOfNodesHelper(BinaryNode* subTreePtr) const {
    if (subTreePtr == NULL) return 0;
    else
        return 1 + getHeightHelper(subTreePtr->getLeftChildPtr())+
                       getHeightHelper(subTreePtr->getRightChildPtr()); 
}

BinaryNode* BinarySearchTree::insertInOrder(BinaryNode* subTreePtr,BinaryNode* newNodePtr){
    BinaryNode* tempPtr = NULL;
    if(subTreePtr == NULL)
        return newNodePtr;
    else if( subTreePtr->getItem() > newNodePtr->getItem()){
        tempPtr = insertInOrder(subTreePtr->getLeftChildPtr(), newNodePtr);
        subTreePtr->setLeftChildPtr(tempPtr);
    } else{
        tempPtr = insertInOrder(subTreePtr->getRightChildPtr(), newNodePtr);
        subTreePtr->setRightChildPtr(tempPtr);
    }
    return subTreePtr;
}
void BinarySearchTree::inorder(BinaryNode* treePtr) const{
    if (treePtr != NULL) {
        inorder(treePtr->getLeftChildPtr());
        int temp = treePtr->getItem();
        cout<< temp << "  "<<endl;
        inorder(treePtr->getRightChildPtr());
    } // end if
} // end inorder

void BinarySearchTree::preorder(BinaryNode* treePtr) const{
    if (treePtr != NULL) {
        int temp = treePtr->getItem();
        cout<< temp << "  ";
        preorder(treePtr->getLeftChildPtr());
        preorder(treePtr->getRightChildPtr());
    } // end if
} // end inorder

void BinarySearchTree::postorder(BinaryNode* treePtr) const{
    if (treePtr != NULL) {
        postorder(treePtr->getLeftChildPtr());
        postorder(treePtr->getRightChildPtr());
        int temp = treePtr->getItem();
        cout<< temp << "  ";
    } // end if
} // end inorder

bool BinarySearchTree::search( BinaryNode* treePtr, const int anEntry){
    if(treePtr == NULL)
        return false;
    else if ( treePtr->getItem() == anEntry){
        return true;
    } else if( anEntry < treePtr->getItem()){
        return search(treePtr->getLeftChildPtr(), anEntry);
    } else{
        return search(treePtr->getRightChildPtr(), anEntry);
    }
}
BinaryNode* BinarySearchTree::removeValue(BinaryNode* subTreePtr, int target, bool &success){
    if( subTreePtr ==NULL){
        success = false;
        return NULL;
    }else if(subTreePtr->getItem() == target){
        subTreePtr = removeNode(subTreePtr);
        success = true;
        return subTreePtr;
    } else if( subTreePtr ->getItem() > target){
        BinaryNode* tempPtr;
        tempPtr = removeValue(subTreePtr->getLeftChildPtr(),target,success);
        subTreePtr->setLeftChildPtr(tempPtr);
        return subTreePtr;
    } else {
        BinaryNode* tempPtr;
        tempPtr = removeValue(subTreePtr->getRightChildPtr(),target,success);
        subTreePtr->setRightChildPtr(tempPtr);
        return subTreePtr;
    }
}
BinaryNode* BinarySearchTree::removeNode(BinaryNode* nodePtr){
    if( nodePtr->getLeftChildPtr() == NULL && nodePtr -> getRightChildPtr() == NULL){
        delete nodePtr;
        nodePtr = NULL;
        return nodePtr;
    } else if ( nodePtr->getLeftChildPtr() != NULL && nodePtr -> getRightChildPtr() != NULL){
        BinaryNode* temp;
        int newNodeValue = 0;
        temp = removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue);
        nodePtr->setRightChildPtr(temp);
    } else {
        BinaryNode* nodeToConnectPtr;
        if( nodePtr-> getLeftChildPtr() != NULL){
            nodeToConnectPtr = nodePtr->getLeftChildPtr();
        } else{
            nodeToConnectPtr = nodePtr->getRightChildPtr();
            delete nodePtr;
            nodePtr = NULL;
            return nodeToConnectPtr;
        }
    }
    return NULL;
}

BinaryNode* BinarySearchTree::removeLeftmostNode(BinaryNode* nodePtr, int &inorderSuccesssor){
    if(nodePtr ->getLeftChildPtr() == NULL){
        inorderSuccesssor = nodePtr -> getItem();
        return removeNode(nodePtr);
    } else return removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccesssor);
}

// Print level order will be a recursive program that will have a helper function
// from level 1 to the end og BST, it will print the elements
void BinarySearchTree::printlevelorder(BinaryNode* ptr){
    int i = 1;
    while( i < getHeight()){
        printlevelorderHelper(ptr, i);
        i++;
    }
}

void BinarySearchTree::printlevelorderHelper(BinaryNode* ptr, int level){
    if( ptr == NULL) return;
    if( level == 1){
        cout<< ptr->getItem() << "\n";
    } else if( level > 1){
        printlevelorderHelper(ptr->getLeftChildPtr(), level - 1);
        printlevelorderHelper(ptr->getRightChildPtr(), level - 1);
    }
}

void BinarySearchTree::spanHelper( const int a, const int b, BinaryNode* ptr, int &count){
    if(ptr == NULL) return;
    
    if(ptr->getItem() < a){
        spanHelper(a, b, ptr->getRightChildPtr(), count);   
    
    }else if( ptr->getItem() > b){

        spanHelper(a, b, ptr->getLeftChildPtr(), count);
    
    } else
        if( a <= ptr->getItem() && b >= ptr->getItem()){
            count++;
            spanHelper(a, b, ptr->getLeftChildPtr(), count);
            spanHelper(a, b, ptr->getRightChildPtr(),count);
        }
}

void BinarySearchTree::mirrorHelper(BinaryNode* ptr){
    //now we can mirror it to see if the funciton works
    if(ptr == NULL) return;
    BinaryNode* tempN;
    mirrorHelper( ptr->getLeftChildPtr());
    mirrorHelper(ptr->getRightChildPtr());
    
    // Could not decide if i should have written a helper swap function,
    //will do if i have time
    tempN = ptr->getRightChildPtr();
    ptr->setRightChildPtr(ptr->getLeftChildPtr());
    ptr->setLeftChildPtr(tempN);
}
//..........................................................
//Homework assigned methods
//......................................................    
bool BinarySearchTree::isEmpty(){
    if(rootPtr == NULL) return true;
    else return false;
}

bool BinarySearchTree::add( const int newEntry){
    cout<<"contains check"<<endl;
    if(contains(newEntry)){
        cout<< "This item already exists" <<endl;
        return false;
    }else{
        cout<< "item will be added"<<endl;
	BinaryNode* newptr = new BinaryNode(newEntry);
        rootPtr = insertInOrder(rootPtr, newptr);
        return true;
    }
}

bool BinarySearchTree::remove(const int anEntry){
    bool success = false;
    rootPtr = removeValue(rootPtr, anEntry, success);
    cout<< "Element "<< anEntry<< " removed succesfully"<<endl;
    return success;
}

bool BinarySearchTree::contains( const int anEntry){
  
    if(search(rootPtr, anEntry)){ 
        cout<<"element is in the bst"<<endl;
        return true;
    } else {
        cout<<"no such element in the bst"<<endl;
        return false;
    }
}

int BinarySearchTree::getHeight(){
    return getHeightHelper(rootPtr);
}

int BinarySearchTree::getNumberOfNodes(){
    return getNumberOfNodesHelper(rootPtr);
}

void BinarySearchTree::inorderTraverse(){
    cout<< ".............................."<<endl;
    cout<< "       InOrder Traverse       "<<endl;
    inorder(rootPtr);
    cout<< "      InOrder Traverse Done   "<<endl;
}

void BinarySearchTree::preorderTraverse(){
    cout<< ".............................."<<endl;
    cout<< "       PreOrder Traverse       "<<endl;
    preorder(rootPtr);
    cout<<endl;
    cout<< ".............................."<<endl;
    cout<< "       PreOrder Traverse Done       "<<endl;
}

void BinarySearchTree::postorderTraverse(){
    cout<< ".............................."<<endl;
    cout<< "       PostOrder Traverse       "<<endl;
    postorder(rootPtr);
    cout<<endl;
    cout<< ".............................."<<endl;
    cout<< "       PostOrder Traverse Done      "<<endl;
}

void BinarySearchTree::levelorderTraverse(){
    cout<< ".............................."<<endl;
    cout<< "       LevelOrder Traverse       "<<endl;
    printlevelorder(rootPtr);
    cout<< ".............................."<<endl;
    cout<< "       LevelOrder Traverse Done      "<<endl;
}

int BinarySearchTree::span(const int a, const int b){
    int Node_counter = 0;
    if( a > b){
        cout<<" Incorrect span, first number should be less than second";
        return -1;
    }
    spanHelper( a, b, rootPtr, Node_counter);
    return Node_counter;
}

void BinarySearchTree::mirror(){
    if(rootPtr == NULL) return;
    else {
        //Let us print first the root without the mirror
        inorder(rootPtr);
        mirrorHelper(rootPtr);
        //now let's print the mirror version of it
        inorder(rootPtr);
    }
}

//BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree& rightHandSide){
	//if(this!=&rightHandSide){
	//	destroyTree(this);
	//	this = copyTree(rightHandSide);
//	}
//	return *this;
//}		

//}
