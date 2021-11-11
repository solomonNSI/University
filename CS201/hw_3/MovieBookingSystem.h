#ifndef MOVIEBOOKINGSYSTEM_H
#define MOVIEBOOKINGSYSTEM_H

#include <iostream>
#include "ReservationList.h"
#include "MoviesList.h"

using namespace std;

class MovieBookingSystem{
public:
    const static int numOfRow = 30;
    const static int numOfColumn = 26;
    MovieBookingSystem();
    ~MovieBookingSystem();

    void addMovie( const long movieID, const int audienceRadius);
    void cancelMovie( const long movieID);
    void showAllMovies() const;

    void showMovie( const long movieID);
    int makeReservation( const long movieID, const int row, const char col);

    void cancelReservations( ReservationList resCode);
    void showReservation( const int resCode) const;

private:
    ReservationList reservationCodes;
    MoviesList movies;
    int Msize;
    int Rsize;
};
#endif
