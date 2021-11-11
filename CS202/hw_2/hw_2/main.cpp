#include "BinarySearchTree.h"

int main(){ 
	cout<<"compiled"<<endl;

int temp1 = 14;
    BinarySearchTree* bst = new BinarySearchTree(temp1);
	cout<<"r1"<<endl;
	int temp2 = 1;
	int temp3 = 3;
    bst->add(temp2);
	cout<<"r2"<<endl;
    bst->add(temp3);
	cout<<"r3"<<endl;
	int temp4 = 4;
	int temp5 = 5;
	int temp6 = 6;
	int temp7 = 127;
	int temp8 = 83;
    bst->add(temp4);
	cout<<"r4"<<endl;
    bst->add(temp5);
	cout<<"r5"<<endl;
    bst->add(temp6);
	cout<<"r6"<<endl;
    bst->add(temp7);
	cout<<"r7"<<endl;
    bst->add(temp8);

    bst->inorderTraverse();
    bst->levelorderTraverse();
    bst->preorderTraverse();
    bst->postorderTraverse();
     int span;
    span = bst->span(13,100);
    
    
    cout<<"span is: " <<span <<endl;
    
     bst->contains(5);
     bst->contains(34);
    
    bst->remove(5);
    bst->contains(5);
    
    cout<< bst->isEmpty()<<endl;
    cout<< bst->getNumberOfNodes()<<endl;
    cout<< bst->getHeight()<<endl;
    return 0;
}
