#ifndef MOVIESLIST_H
#define MOVIESLIST_H
#include "SeatsList.h"
using namespace std;

class MoviesList{
    public:
        const static int numOfRow = 30;
        const static int numOfColumn = 26;
        //constructor, copy constructor and destructor
        MoviesList();
        MoviesList(const MoviesList& aList);
        ~MoviesList();
        
        bool isEmpty() const;
        int getLength() const;
        bool retrieve( int index) const;
        bool insert( int index, long movieID, int audienceRadius);
        bool remove( int index);
        
        bool does_contain(long movieID) const;
        int findNode(long movieID);
       //To do 
        void printSeats(int index);
    
        void changeSeatsAvailability(int index, int row, char col);
    private:
        struct MoviesNode{
            long movieID;
            int audienceRadius;
            SeatsList seats;
            MoviesNode* next;
        };
        int size;
        MoviesNode* head;
        MoviesNode* find(int index) const;
        int SeatsSize;
};
#endif
