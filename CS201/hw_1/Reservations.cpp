#include "Reservations.h"

Reservations::Reservations(){
    uRid = 0;
    mID = 0;
    Rrow = 0;
    Rcol = 0;
}

Reservations::Reservations(const int movieID, const int row, const char column){
    mID = movieID;
    Rrow = row;
    Rcol = (int)column - 64;
    uRid = rand() % 1000 + 1; //unId range :from 1 to 1k 
}

int Reservations::getID(){
    return uRid;
}

int Reservations::getMID(){
    return mID;
}

int Reservations::getRow(){
    return Rrow;
}

int Reservations::getCol(){
    return Rcol;
}
