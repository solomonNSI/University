#include "Requests.h"


Requests:: Requests(){
    id = 0;
    priority = 0;
    timeReq = 0;
    timePro = 0;
}

Requests:: Requests( const int id, const int priority, const int timeReq, const int timePro){
    this->id = id;
    this->priority = priority;
    this->timeReq = timeReq;
    this->timePro = timePro;
}

int Requests:: getID(){
    return id;
}

int Requests:: getPriority(){
    return priority;
}

int Requests:: getTimeReq(){
    return timeReq;
}

int Requests:: getTimePro(){
    return timePro;
}

