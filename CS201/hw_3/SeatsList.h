#ifndef SEATSLIST_H 
#define SEATSLIST_H
#include <iostream>
using namespace std;

class SeatsList{
    public:
        //constructor, copy constructor and destructor
        SeatsList();
        SeatsList(const SeatsList& aList);
        ~SeatsList();
        
        bool isEmpty() const;
        int getLength() const;
        bool retrieve( int index, int &row, char &col, char& availability) const;
        bool insert( int index, int row, char col);
        bool remove( int index);
        
        bool changeAvailability(int index);
        int does_contain_seat( int row, char col) ;
    private:
        
        struct SeatsNode{
            int row;
            char col;
            char availability;
            SeatsNode* next;
        };
        int size;
        SeatsNode *head;
        SeatsNode *find(int index) const;
};
#endif

