#include "SeatsList.h"

SeatsList::SeatsList(): size(0), head(NULL){
}

SeatsList::SeatsList(
        const SeatsList& aList): size(aList.size){
   if (aList.head == NULL)
      head = NULL;  // original list is empty
   else {
      // copy first node
      head = new SeatsNode;
      head->row = aList.head->row;
      head->col = aList.head->col;
      head->availability = aList.head->availability;
      // copy rest of list
      SeatsNode *newPtr = head;  // new list ptr

      for (SeatsNode *origPtr = aList.head->next;
                     origPtr != NULL;
                     origPtr = origPtr->next){
         newPtr->next = new SeatsNode;
         newPtr = newPtr->next;
         newPtr->row = origPtr->row;
         newPtr->col = origPtr->col;
         newPtr->availability = origPtr->availability;
      }
      newPtr->next = NULL;
   }
}  // end copy constructor

SeatsList::~SeatsList(){
    while( !isEmpty())
        remove(1);
}

bool SeatsList:: isEmpty() const {
    return size == 0;
}

int SeatsList:: getLength() const{
    return size;
}

SeatsList::SeatsNode* SeatsList::find(int index) const{
    if(index < 1 || index > getLength())
        return NULL;
    else {
        SeatsNode* temp = head;
        for( int skip = 1; skip < index; skip++){
            temp = temp->next;
        }
        return temp;
    }
}
// in
bool SeatsList::retrieve( int index, int &row, char &col, char &availability) const{
   if( (index < 1) || (index > getLength()))
      return false;
   SeatsNode* node = find(index);
   availability = node->availability;
   return true;
}

bool SeatsList::insert( int index, int row, char col){
    int newLength = getLength() + 1;
    if((index < 1) || (index > newLength))
        return false;

    SeatsNode* ptr = new SeatsNode;
    size = newLength;
    ptr->row = row;
    ptr->col = col;

    ptr->availability = 'o';

    if( index == 1){
        ptr->next = head;
        head = ptr;
    }else{
        SeatsNode* temp = find(index-1);
        ptr->next = temp->next;
        temp->next = ptr;
    }
    return true;
}

bool SeatsList::remove(int index){
    SeatsNode* node;
    if((index < 1) || (index>size))
        return false;

    --size;
    if(index == 1){
        node = head;
        head = head->next;
    }else{
        SeatsNode* prev = find(index-1);
        node = prev->next;
        prev->next = node->next;
    }
    node->next = NULL;
    delete node;
    node = NULL;
    return true;
} //end remove

int SeatsList::does_contain_seat(int row, char col){
    SeatsNode* temp = head;
    for( int i = 1; i <= size; i++){
        if((temp->row == row) && (temp->col == col))
            return i;
        temp = temp->next;
    }
    return -1;
}

bool SeatsList::changeAvailability(int index){
    SeatsNode* temp = find(index);
    if( temp->availability == 'x')
        temp->availability = 'o';
    else
        temp->availability = 'x';
    return true;
}
