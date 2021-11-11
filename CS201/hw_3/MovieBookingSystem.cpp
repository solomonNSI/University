#include "MovieBookingSystem.h"
#include <stdlib.h>

MovieBookingSystem::MovieBookingSystem(){
    Msize = 0;
    Rsize = 0;
}

MovieBookingSystem::~MovieBookingSystem(){}

void MovieBookingSystem::addMovie( const long movieID, const int audienceRadius){
    if(!movies.does_contain(movieID)){
        if( (audienceRadius > 0) || (audienceRadius < 8)){
            ++Msize;
            movies.insert(Msize, movieID, audienceRadius);
            time_t t = movieID;
            string stamp = ctime(&t);
            stamp.erase(stamp.end() - 1);
            cout<<"Movie at "<<stamp<< " was succesfully added "<<endl;
        }else{
            cout<< "The radius is out of range"<<endl;
        }
    }else{
            time_t t = movieID;
            string stamp = ctime(&t);
            stamp.erase(stamp.end() - 1);
            cout<<"Movie at "<<stamp<< " was already added "<<endl;
    }
}

void MovieBookingSystem::cancelMovie( const long movieID){
    if(!movies.does_contain(movieID)){
        if( Msize == 1){
            movies.remove(1);
            while( reservationCodes.isEmpty()== false)
                reservationCodes.remove(1);
            Msize == 0;
            Rsize == 0;
        }else{
            //first remove the movie from LL
            int index;
            index = movies.findNode(movieID);
            if(index > 0){
                movies.remove(index);
                --Msize;
            
            //now find the RL that have the same movieID
                for( int i = 0; i < Rsize; i++){
                    int res = 0;
                    int mID = 0;
                    int temp;
                    char temp1;
                    reservationCodes.getALL(i,res,mID, temp, temp1);
                    if(mID == movieID){
                        reservationCodes.remove(i);
                        --Rsize;
                    }
                }
            //delete them as well
            }
        }
    }else{
        cout<<"Movie with ID: " << movieID << " does not exist " <<endl;
    }
}

void MovieBookingSystem::showAllMovies() const{
    if(Msize > 0){
        cout<<"Movies on show : "<<endl;
        for(int i = 1; i <= Msize; i++){
            movies.retrieve(i);
        }
    }else{
        cout<<" No movies on show"<<endl;
    }
}

void MovieBookingSystem::showMovie( const long movieID){
    int index;
    index = movies.findNode(movieID);
    if( index > 0){
        movies.retrieve(index);
        movies.printSeats(index);
    }else
        cout<< " There is no movie like that"<<endl;
}
int MovieBookingSystem::makeReservation( const long movieID, const int row, const char col){
    if(movies.does_contain(movieID)){
        // check if the seat is available
        int index;
        index = movies.findNode(movieID);

        char available;
        movies.changeSeatsAvailability(index, row, col);

        // change the availability
    
        // generate the code for reservation
        Rsize++;
        int uRid = rand() %1000 + 1;
        reservationCodes.add(Rsize, uRid, movieID, row, col);
        // add to the linked list
        cout<< "Reservation done succesfully"<<endl;
        return uRid; 
        
    }else{
        cout<< "Movie does not exist"<<endl;
        return -1;
    }
}

void MovieBookingSystem::cancelReservations( ReservationList resCode){
    int length = resCode.getLength();

    for( int i = 1; i <= length; i++){
        int index;
        int mID;
        int reservation;
        int row;
        char col;
        resCode.getALL(i,reservation, mID, row, col);
        if( reservationCodes.does_contain(reservation) < 0){
            cout<< "Some codes have a problem " <<endl;
            return;
        }
    }

    for( int i = 1; i <= length; i++){
        int index, mID, reservation, row;
        char col;
        resCode.getALL(i, reservation,mID, row,col);
        index = movies.findNode(mID);

        movies.changeSeatsAvailability(index, row, col);
        int index1;
        index1 = reservationCodes.does_contain(reservation);
        reservationCodes.remove(index1);
        Rsize--;
    }
    cout<< "The reservations removed succesfully "<<endl;
        // find the reservations
    // false if one of them does not exist
    // remove the reservations
    //
}

void MovieBookingSystem::showReservation(const int resCode) const{
    int index;
    index = reservationCodes.does_contain(resCode);

    if( index > 0){
        int mID;
        int res;
        int row;
        char col;
        reservationCodes.getALL(index, res, mID, row, col);
            
        time_t t = mID;
        string stamp = ctime(&t);
        stamp.erase(stamp.end() - 1);
        cout<<"Reservation with code: " << res <<": Seat" << col << row<< "Movie at "<<stamp<<endl;

    } else{
        cout<< " Reservation with code: " <<resCode << " does not exist"<<endl;
    //find the reservation and retrieve
    }
}
