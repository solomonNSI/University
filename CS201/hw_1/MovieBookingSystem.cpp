#include "MovieBookingSystem.h"

//............................................................
//            Constructor and Destructor
//............................................................

MovieBookingSystem::MovieBookingSystem(){
    movies = NULL;
    reservations = NULL;
    Msize = 0;
    Rsize = 0;
}
MovieBookingSystem::~MovieBookingSystem(){
    if( movies != NULL){
        delete [] movies;
        delete [] reservations;
        movies = NULL;
        reservations = NULL;
    }
}

//............................................................
//            Helper Methods
//............................................................
void MovieBookingSystem::add( Movies* movie){
    //create a temp array that is bigger than the prev array

    Movies* temp = new Movies[Msize+1];
    
    //insert the last movie to the end of the array
    temp[Msize] = *movie;
    //copy previous elements from the array
    for( int i = 0; i < Msize; i++){
        temp[i] = movies[i];
    }
    //delete the old array and point to the new one
    delete [] movies;
    movies = temp;
    Msize++;
}

bool MovieBookingSystem::does_contain(const long movieID){
    for( int i = 0; i < Msize; i++){
        if(movies[i].getID() == movieID) return true;
    }
    return false;
}

bool MovieBookingSystem::does_contain_res(const int resCode){
    for( int i = 0; i < Rsize; i++){
        if(reservations[i].getID() == resCode) return true;
    }
    return false;
}


int MovieBookingSystem::findIndex( const int movieID) {
    for( int i = 0; i < Msize; i++){
        if( movies[i].getID() == movieID) return i;
    }
    return -1;
}

void MovieBookingSystem::remove(const long movieID){
    if(Msize == 1) {
        delete [] movies;
        delete [] reservations;

        movies = NULL;
        reservations = NULL;
        Msize--;
        Rsize = 0;
    } else {
        int resSize = 0;
        for( int i = 0; i < Rsize; i++){
            if(reservations[i].getMID() == movieID){
                resSize++;
            }
        }
        if( resSize > 0){
            int* res = new int[resSize];
            int cntr = 0;
            for( int i = 0; i < Rsize; i++){
                if(reservations[i].getMID() == movieID){
                    res[cntr] = reservations[i].getID();
                    cntr++;
                }
            }
            cancelReservations(resSize, res);
            delete [] res;
            res = NULL;
        }

        Movies* temp = new Movies[Msize - 1];
       
        int counter = 0;
        
        // counter is used because the temp array is smaller than the movies
        // and without it it won't copy properly
        //find the index of the movie in the movies array
        int indexM = findIndex(movieID);
        for( int i = 0; i < Msize; i++){
            if(i == indexM) {
                continue;
            } else {
                temp[counter] = movies[i];
                counter++;
            }
        }
        delete [] movies;
        movies = temp;
        Msize--;
    }   
}

// a function to determine how many seats are available
int MovieBookingSystem::availableS( Movies* movie){
    int column = movie->getCol();
    int row = movie->getRow();
    int counter = 0;
    for( int i = 0; i < row; i++){
        for( int j = 0; j < column; j++){
            if( movie->getSeat(i,j) == 'o')
                counter++;
        }
    }
    return counter;
}
//finds the movie object and returns it
Movies* MovieBookingSystem::findM(const long movieID){
    for( int i = 0; i < Msize; i++){
        if( movies[i].getID() == movieID){
            Movies* temp1 = &movies[i];
            return temp1;
        }
    }
    return NULL;
}

void MovieBookingSystem::reservationAdd( Reservations reservation){
    Reservations* temp = new Reservations[Rsize+1];
    temp[Rsize] = reservation;
    for(int i = 0; i < Rsize; i++){
        temp[i]  = reservations[i];
    }
    delete [] reservations;
    reservations = temp;
    Rsize++;
}

Reservations* MovieBookingSystem::findR(const int resCode){
    for( int i = 0; i< Rsize; i++){
        if(reservations[i].getID()==resCode)
        {
            Reservations* temp = &reservations[i];
            return temp;
        }
    }
    return NULL;
}
//............................................................
//            Main, hw assigned Methods
//............................................................

void MovieBookingSystem::addMovie(const long movieID, const int audienceRadius){
    if(does_contain(movieID)){
        cout<<"This movie is already registered"<< endl;   
    }else if( audienceRadius < 0 || audienceRadius > 7) {
        cout<< "The radius is invalid, should be between [0, 7]"<<endl;
    } else{
        int covid_row;
        int covid_col;         
            
        if( audienceRadius == 0){
            covid_row = numOfRow;
            covid_col = numOfColumn;
        } else if(audienceRadius == 1) {
            covid_row = numOfRow/2;
            covid_col = numOfColumn/2;
        }else{
            // to avoid creating space for the elements we are not going to use
            covid_row = (numOfRow / audienceRadius) - 1;
            covid_col = (numOfColumn / audienceRadius) - 1;
        }
        Movies tempM = Movies( movieID, audienceRadius, covid_col, covid_row );
        add(&tempM);
        time_t t;
        t = movieID;
        string stamp = ctime(&t);
        stamp.erase(stamp.end() - 1);
        cout<< "Movie at " <<stamp << " was successfully added" <<endl;
    }
}
void MovieBookingSystem::cancelMovie(const long movieID){
    if( !does_contain(movieID)) cout << "Movie was not yet registered, can't delete"<<endl;
    else {
        cout<< " I think I am here, goin to remove "<<endl;
        remove(movieID);
        cout<< " Movie succesfully deleted"<<endl;
    }
}

void MovieBookingSystem::showAllMovies(){
    if(movies == NULL) {
        cout<< "No movies on show"<<endl;
    }else {
        for(int i = 0; i < Msize; i++){
            int id = movies[i].getID();
            time_t t = id;
            string stamp = ctime(&t);
            stamp.erase(stamp.end() - 1);
            cout<< "Movie at " << stamp << 
                " ( " << availableS((findM(id))) << " available seats "<<endl;
            movies[i].printSeats();
        }
    }
}

void MovieBookingSystem::showMovie(const long movieID){
    if(!does_contain(movieID)) {
        cout<< " Movie does not exist " <<endl;
    } else {
        cout<< " Movie at "<< ctime(&movieID)<< "has " << availableS((findM(movieID))) 
            << " seats available " << endl;
        findM(movieID)->printSeats();
    }
}

int MovieBookingSystem::makeReservation(const long movieID, const int row, const char column){
    int radius = findM(movieID)->getRadius();
    if(!does_contain(movieID)){
        cout<< " Movie does not exist "<<endl;
        return -1;
    } else if ( row % radius == 0 || column % radius == 0) {
        cout<< " You are not allowed to sit on this place (covid policies) " <<endl;
        return -1;
    }else{
        findM(movieID)->changeSeatAvailability(row, column);
        cout<< " Occupied successfully" <<endl;
        Reservations r1 = Reservations(movieID, row, column);
        reservationAdd(r1);
        time_t t;
        t = movieID;
        string stamp = ctime(&t);
        stamp.erase(stamp.end() - 1);
        cout<< "Reservation done for "<< column << row << " in the movie at  "
         << stamp << " reservation id: "<< r1.getID() << endl;
        return r1.getID();
    }
}

void MovieBookingSystem::cancelReservations(const int numRes, const int* resCode){
    int cnt = 0;
    for( int i = 0; i<numRes; i++){
        if(!does_contain_res( resCode[i])){
            cout<< "Reservation " << resCode[i] << " does not exist " <<endl;
            cnt++;
        }
    }
    if( cnt > 0) return;
    else if( Rsize == 1){
        int mID = findR(resCode[0])->getMID();
        int occ_row = findR(resCode[0])->getRow();
        int occ_col = findR(resCode[0])->getCol();
        time_t t = mID;
        string stamp = ctime(&t);
        stamp.erase( stamp.end() - 1);
        findM(mID)->changeSeatAvailability(occ_row, occ_col);
        cout<< " Reservation " << resCode[0] << " for the movie at " <<
            stamp << " has been deleted " <<endl;
        delete [] reservations;
        reservations = NULL;
        Rsize = 0;
    } else{
        // a bit messed up part, I should better create a helper method
        for( int j = 0; j < numRes; j++){
            //get the values from reservation 
            int mID = findR(resCode[j])->getMID();
            int occ_row = findR(resCode[j])->getRow();
            int occ_col = findR(resCode[j])->getCol();
                
            findM(mID)->changeSeatAvailability(occ_row, occ_col);
            Reservations* temp = new Reservations[Rsize - 1];
            int counter = 0;
            for( int i = 0; i < Rsize; i++){
                if( reservations[i].getID() == resCode[j])
                   continue;
                temp[counter] = reservations[i];
                cout<< counter<<endl;
                counter++;
            }
            delete [] reservations;
            reservations = temp; 
            Rsize--; 
            time_t t = mID;
            string stamp = ctime( &t);
            stamp.erase(stamp.end() - 1);
            cout<< " Reservation " << resCode[j] << " for the movie at " <<
                stamp<< " has been deleted " <<endl;
        }
    }
}

void MovieBookingSystem::showReservation(const int resCode){
        if(!does_contain_res(resCode)){
            cout<< " There is no such reservation (" << resCode << ")"<<endl;
        } else{
            int mID = findR(resCode)->getMID();
            int occ_row = findR(resCode)->getRow();
            char occ_col = ( findR(resCode)->getCol() + 64) ;
            time_t t = mID;
            string stamp = ctime(&t);
            stamp.erase( stamp.end() - 1);

            //char temp = findM(mID).getSeat(occ_row, occ_col);
            cout<< "Reservation in code " << resCode << ": your seat " << occ_col
                <<occ_row<< " for the movie at " << stamp<<endl;
        }
}
