#include "Movies.h"

Movies::Movies(){
    this->seats = NULL;
    this->radius = 0;
    this->uID = 0;
    this->mRow = 0;                                                           
    this->mCol = 0;
}

Movies::~Movies(){
    if( seats != NULL){
        for(int i = 0; i < mRow; i++){
            delete [] seats[i];
        }
            delete [] seats;
    }
    seats = NULL;
}

Movies::Movies(const long movieID, int radius, int columns, int rows){
   //take the value of the passing elements and store
    this->uID = movieID;
    this->radius = radius;
    this->mRow = rows;
    this->mCol = columns;

    // create the memory for the spaces
    seats = new char*[mRow];
    for( int i = 0; i < mRow; i++){
        seats[i] = new char[mCol];
    }

    //make all the seats available
    for(int count = 0; count < mRow; count++){
        for(int count1 = 0; count1 < mCol; count1++){
            seats[count][count1] = 'o' ;
        }
    }
}
//copy constructor
Movies::Movies( const Movies& other) {
    if(this != &other){
        //delete the seats in the first movie
        
        this->~Movies();
        this->uID = other.getID();
        this->radius = other.getRadius();
        this->mRow = other.getRow();
        this->mCol = other.getCol();
        this->seats = new char*[mRow];
        for(int count = 0; count < mRow; count++){
            this->seats[count] = new char[mCol];
            for(int count1 = 0; count1 < mCol; count1++){
                this->seats[count][count1] = other.getSeat(count, count1);
            }
        }
    }
}

void Movies:: printSeats(){
    char letter = 'A';
    int r = 1;
    cout<<" Radius: " << radius << endl;
    for( int i = 0; i < mCol; i++){
        cout<<" "  << letter << " ";
        letter += radius + 1;
    }
    cout<<endl;

    for(int i = 0; i < mRow; i++ ){
        cout<< r << " ";
        for(int j = 0; j < mCol; j++){
            cout<< seats[i][j]<<" ";
        }
        r++;
        cout<<endl;
    }
}

//assignment operator overload                                                                              
Movies& Movies::operator=(const Movies& other){
    if( this != &other){
        this->uID = other.getID();
        this->radius = other.getRadius();
        this->mRow = other.getRow();
        this->mCol = other.getCol();
        cout<<endl;
        if( seats){
            for( int i = 0; i < mRow; i++){
                delete [] seats[i];
            }
            delete [] seats;
        }
        this->seats = new char*[mRow];
        for(int count = 0; count < mRow; count++){
            this->seats[count] = new char[mCol];
            for(int count1 = 0; count1 < mCol; count1++){
                this->seats[count][count1] = other.getSeat(count, count1);
            }
        }
    }
    return *this;
}        

long Movies:: getID() const{
    return uID;
}

int Movies:: getRadius() const{
    return radius;
}

int Movies::getRow() const{
    return mRow;
}

int Movies:: getCol() const{
    return mCol;
}

char Movies::getSeat(int row, int column) const {
    return seats[row][column];
}

void Movies::changeSeatAvailability(int row, char column){
    int c = (int)column - 64;
    if(seats[row][column] == 'x'){
        seats[row][column] = 'o';
    } else 
        seats[row][column] = 'x';
}
