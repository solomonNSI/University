#ifndef REQUESTS_H
#define REQUESTS_H

#include <iostream>
using namespace std;

class Requests{
private:
    int id;
    int priority;
    int timeReq;
    int timePro;

public:
    Requests();
    Requests(const int id, const int priority, const int timeReq, const int timePro);
//get Methods
    int getID();
    int getPriority();
    int getTimeReq();
    int getTimePro();
};

#endif
