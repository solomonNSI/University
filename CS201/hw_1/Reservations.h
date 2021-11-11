/*                                                                              
*@author Suleyman Hanyyev                                                      
*@date 12/03/2021                                                              
*@program Reservations.h class: additional class for MBS.h                           
*/ 
#ifndef RESERVATIONS_H
#define RESERVATIONS_H

#include <iostream>
#include <cstdlib>
class Reservations{
    private:
        int uRid; //unique reservation id
        int mID; //so that it knows which movie the id belongs to
        int Rrow;
        char Rcol;

    public:
        Reservations();
        Reservations( const int movieID, const int row, const char column);

        int getID();
        int getMID();
        int getRow();
        int getCol();


};
#endif
