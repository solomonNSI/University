#ifndef RESERVATIONLIST_H
#define RESERVATIONLIST_H

#include <iostream>
using namespace std;

class ReservationList{ 
public:
    ReservationList();
    ReservationList( const ReservationList& aList );
    ~ReservationList();
    bool isEmpty() const;
    int getLength() const ;
    bool retrieve(int index, int &resCode) const;

    bool getALL( int index, int &resCode, int& movieID, int &row, char &col) const;
    bool add(int index, int resCode, int movieID, int row, char col);
    bool insert(int index, int resCode);
    bool remove(int index);
    
    int does_contain( int resCode) const;
private:

    struct ReservationNode{
            int Code;
            char col;
            int row;
            int movieID;
            ReservationNode* next;
    };
    int size;
    ReservationNode *head;
    ReservationNode *find(int index) const;
};

#endif
