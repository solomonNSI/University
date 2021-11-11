/* 
 *@author Suleyman Hanyyev
 *@date 12/03/2021
 *@program Movies.h class: additional class for MBS.h
 */


#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>
using namespace std;

class Movies{
    private:
        char** seats;
        int radius;
        int mRow;
        int mCol;
        long uID; 
    public:
        const static int numOfRow = 30;
        const static int numOfCol = 26;
        //default constructor
        Movies();

        //construcor2
        Movies( const long movieID, const int radius, int columns, int rows);

        //destructor
        ~Movies();       
        
        //copy constructor
        Movies(const Movies& other);

        //assingment operator overload
        Movies& operator=(const Movies& other);


        //helper programs
        void printSeats();
        long getID() const ;
        int getRadius() const;
        int getRow() const;
        int getCol() const;
        char getSeat(int row, int col) const;
        void changeSeatAvailability(int row, char col);
};
#endif
