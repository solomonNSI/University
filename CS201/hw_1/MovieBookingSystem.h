#ifndef __MOVIEBOOKINGSYSTEM_H
#define __MOVIEBOOKINGSYSTEM_H

#include <ctime>
#include <iostream>
#include "Reservations.h"
#include "Movies.h"
#include <string>
using namespace std;

class MovieBookingSystem{
    private:
        Movies* movies;
        Reservations* reservations;
        int Msize;
        int Rsize;

        
        bool does_contain( const long movieID);
        void add( Movies* movie);
        Movies* findM(const long movieID);
        int availableS( Movies* movie);
        void remove( const long movieID);
        void reservationAdd( Reservations reservation);
        int findIndex( const int movieID);
        Reservations* findR( const int resCode);
        bool does_contain_res(const int resCode);
    public:
        const static int numOfRow = 30;
        const static int numOfColumn = 26;

        MovieBookingSystem();
        ~MovieBookingSystem();

        void addMovie( const long movieID, const int audienceRadius);
        void cancelMovie( const long movieID);
        void showAllMovies();
        void showMovie( const long movieID);
        int makeReservation( const long movieID, const int row, const char col);
        void cancelReservations( const int numRes, const int* resCode);
        void showReservation(const int resCode);

};
#endif

