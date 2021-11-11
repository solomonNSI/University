#include "MoviesList.h"

MoviesList::MoviesList(): size(0), head(NULL){
    SeatsSize = 0;
}

MoviesList::MoviesList(
        const MoviesList& aList): size(aList.size){
   if (aList.head == NULL)
      head = NULL;  // original list is empty
   else {
      // copy first node
      head = new MoviesNode;
      head->movieID = aList.head->movieID;
      head->audienceRadius = aList.head->audienceRadius;
      head->seats = aList.head->seats;

      // copy rest of list
      MoviesNode *newPtr = head;  // new list ptr

      for (MoviesNode *origPtr = aList.head->next;
                     origPtr != NULL;
                     origPtr = origPtr->next){
         newPtr->next = new MoviesNode;
         newPtr = newPtr->next;
         newPtr->movieID = origPtr->movieID;
         newPtr->audienceRadius = origPtr->audienceRadius;
         newPtr->seats = origPtr->seats;
      }
      newPtr->next = NULL;
   }
}  // end copy constructor

MoviesList::~MoviesList(){
    while( !isEmpty())
        remove(1);
}

bool MoviesList:: isEmpty() const {
    return size == 0;
}

int MoviesList:: getLength() const{
    return size;
}

MoviesList::MoviesNode* MoviesList::find(int index) const{
    if(index < 1 || index > getLength())
        return NULL;
    else {
        MoviesNode* temp = head;
        for( int skip = 1; skip < index; skip++){
            temp = temp->next;
        }
        return temp;
    }
}
// in
bool MoviesList::retrieve( int index) const{
    if( (index < 1) || (index > getLength()))
        return false;
   
    MoviesNode* node = find(index);
    int movieID = node->movieID;
    int audienceRadius = node->audienceRadius;
    
    int count = 0;
    time_t t = movieID;
    string stamp = ctime(&t);
    stamp.erase(stamp.end() - 1);
    
    int count1 = 0; 
    //print seats
    if( audienceRadius > 1){
        for( int i = 0; i < 30; i += audienceRadius){
            for( char j = 'A'; j <= 'Z'; j +=audienceRadius){
                char available;
                node->seats.retrieve(count1, i, j, available);
                if( available == 'o')
                    count++;
                count1++;
            }
            count1++;
        }
    }else{
        for( int i = 0; i < 30; i += audienceRadius + 1){
            for( char j = 'A'; j <= 'Z'; j += audienceRadius + 1){
                char available = 'o';
                node->seats.retrieve(count1, i, j, available);
                if( available == 'o')
                    count++;
                count1++;
            }
            count1++;
        }
    }
    cout<<" Movie at " << stamp << "(" << count<<" available seats) " <<endl;
    return true;
}

bool MoviesList::insert( int index, long movieID, int audienceRadius){
    int newLength = getLength() + 1;
    SeatsSize = 1;

    if((index < 1) || (index > newLength))
        return false;

    MoviesNode* ptr = new MoviesNode;
    size = newLength;
    ptr -> movieID = movieID;
    ptr -> audienceRadius = audienceRadius;
    
    for( int i = 1; i < 30; i += audienceRadius+ 1){
        for( char j = 'A' ; j < 'A' + 26; j += audienceRadius+1){
            ptr->seats.insert(SeatsSize, i, j);
            SeatsSize++;
        }
    }

    if( index == 1){
        ptr->next = head;
        head = ptr;
    }else{
        MoviesNode* temp = find(index-1);
        ptr->next = temp->next;
        temp->next = ptr;
    }
    return true;
}

bool MoviesList::remove(int index){
    MoviesNode* node;
    if((index < 1) || (index>size))
        return false;

    --size;
    if(index == 1){
        node = head;
        head = head->next;
    }else{
        MoviesNode* prev = find(index-1);
        node = prev->next;
        prev->next = node->next;
    }
    node->next = NULL;
    delete node;
    node = NULL;
    return true;
} //end remove

bool MoviesList::does_contain(long movieID) const{
   MoviesNode* node = head;
   for( int i = 1; i <= size; i++){
       if(node->movieID == movieID){
           return true;
       }
       node = node->next;
   }
   return false;
}

int MoviesList::findNode(long movieID){
    MoviesNode* node = head;
    for( int i = 1; i <= size; i++){
        if(node->movieID == movieID){
            return i;
        }
        node = node->next;
    }
    return -1;
}

void MoviesList::printSeats( int index){
    MoviesNode* temp = find(index);
    
    char letter = 'A';
    int r = 1;
    int covid_col;
    int covid_row;

    if(temp->audienceRadius == 0){
        covid_col = numOfColumn;
        covid_row = numOfRow;
    } else if (temp->audienceRadius == 1){
        covid_col = numOfColumn/2;
        covid_row = numOfColumn/2;
    } else{
        covid_col =( numOfColumn/(temp->audienceRadius) - 1);
        covid_row = (numOfRow/(temp->audienceRadius) - 1);
    }

    for( int i = 0; i < covid_col; i++){
        cout<< "   "  << letter << " ";
        letter += temp->audienceRadius + 1;
    }
    cout<<endl;
    //temp chars
    int temp1;
    char temp2;
    int seat = 1;
    for(int i = 1; i < covid_row; i++ ){
        cout<< r << " ";
        for(int j = 0; j < covid_col; j++){
            char avaiab;
            temp->seats.retrieve(seat, temp1, temp2, avaiab);
            cout<< "  "<<avaiab<< "  ";
            seat++;
        }
        r+= temp->audienceRadius + 1;
        cout<<endl;
    }
}

void MoviesList::changeSeatsAvailability(int index, int row, char col){
    MoviesNode* temp = find(index);
    int index1;
    index1 = temp->seats.does_contain_seat( row, col);
    if( index1 > 0){
        temp->seats.changeAvailability( index1);
    }else
        cout<< "Seat is not available"<<endl;
}
