#include "ReservationList.h"

ReservationList::ReservationList(): size(0), head(NULL){
}

ReservationList::ReservationList(
        const ReservationList& aList): size(aList.size){
   if (aList.head == NULL)
      head = NULL;  // original list is empty
   else {
      // copy first node
      head = new ReservationNode;
      head->Code = aList.head->Code;
      head->movieID= aList.head->movieID;
      head->row = aList.head->row;
      head->col = aList.head->col;
      // copy rest of list
      ReservationNode *newPtr = head;  // new list ptr

      for (ReservationNode *origPtr = aList.head->next;
                     origPtr != NULL;
                     origPtr = origPtr->next){
         newPtr->next = new ReservationNode;
         newPtr = newPtr->next;
         newPtr->Code = origPtr->Code;
         newPtr->movieID = origPtr->movieID;
         newPtr->row = origPtr->row;
         newPtr->col = origPtr->col;
      }
      newPtr->next = NULL;
   }
}  // end copy constructor

ReservationList::~ReservationList(){
    while( !isEmpty())
        remove(1);
}

bool ReservationList:: isEmpty() const {
    return size == 0;
}

int ReservationList:: getLength() const{
    return size;
}

ReservationList::ReservationNode* ReservationList::find(int index) const{
    if(index < 1 || index > getLength())
        return NULL;
    else {
        ReservationNode* temp = head;
        for( int skip = 1; skip < index; skip++){
            temp = temp->next;
        }
        return temp;
    }
}
bool ReservationList::getALL( int index, int &resCode, int& movieID, int &row, char &col) const{
   if( (index < 1) || (index > getLength()))
      return false;
   ReservationNode* node = find(index);
   resCode = node->Code;
   movieID = node->movieID;
   row = node->row;
   col = node->col;

   return true;
}
// in
bool ReservationList::retrieve( int index, int &resCode) const{
   if( (index < 1) || (index > getLength()))
      return false;
   ReservationNode* node = find(index);
   resCode = node->Code;
   
   return true;
}

bool ReservationList::add( int index, int resCode, int movieID, int row, char col){
    int newLength = getLength() + 1;
    if((index < 1) || (index > newLength))
        return false;

    ReservationNode* ptr = new ReservationNode;
    size = newLength;
    ptr->Code = resCode;
    ptr->movieID = movieID;
    ptr->row = row;
    ptr->col = col;
    if( index == 1){
        ptr->next = head;
        head = ptr;
    }else{
        ReservationNode* temp = find(index-1);
        ptr->next = temp->next;
        temp->next = ptr;
    }
    return true;
}

bool ReservationList::insert( int index, int resCode){
    int newLength = getLength() + 1;
    if((index < 1) || (index > newLength))
        return false;

    ReservationNode* ptr = new ReservationNode;
    size = newLength;
    ptr->Code = resCode;

    if( index == 1){
        ptr->next = head;
        head = ptr;
    }else{
        ReservationNode* temp = find(index-1);
        ptr->next = temp->next;
        temp->next = ptr;
    }
    return true;
}

bool ReservationList::remove(int index){
    ReservationNode* node;
    if((index < 1) || (index>size))
        return false;

    --size;
    if(index == 1){
        node = head;
        head = head->next;
    }else{
        ReservationNode* prev = find(index-1);
        node = prev->next;
        prev->next = node->next;
    }
    node->next = NULL;
    delete node;
    node = NULL;
    return true;
} //end remove

int ReservationList::does_contain(int resCode) const{
    ReservationNode* node = head;
    for( int i = 1; i <= size; i++){
        if(node->Code == resCode)
            return i;
        node = node->next;
    }
    return -1;
}
