/**
  * Title: Balanced Search Trees, Hashing and Graphs * Author: Name Surname
  * ID: 21901009
  * Section: 1
  * Assignment: 4
  * Description: WordNetwork Hash table
 */
#include <iostream>
#include <string>
using namespace std;
struct Node{
    string data;
    Node* next;
};

class Hashtable{
    public:
    Node** HTable;
    Hashtable(int size);
    ~Hashtable();
    int hash( const string &key, int tableSize);
    void insert( string key);
    string search( string key);
    private:
    int size;
};

Hashtable:: Hashtable( int size){
    this->size = size;
    HTable = new Node*[size];
    for( int i = 0; i < size; i++){
        HTable[i] = NULL;
    }
}

Hashtable:: ~Hashtable(){
    for( int i = 0; i < size; i++){
        delete [] HTable[i];
    }
    delete [] HTable;

}
