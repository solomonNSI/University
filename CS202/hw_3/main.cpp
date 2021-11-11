/*
 * Title: Heaps
 * Author: Suleyman Hanyyev
 * ID:21901009
 * Section:1
 * Assignment: 3
 * Description: The minimum amount of 
 * printers required to sustain the avg waiting time
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <cstdlib>
#include "simulator.h"
#include "Requests.h"
using namespace std;

int main(int argc, char *argv[]){
    //initiation of variables
    //to take the input from the console
    string time = "";
    double MaxWaitingTime;
    string filename = "";
    
    //taking the parameters from the console
    if( argc == 3){
        //assigning the parameters to the variables
        filename = argv[1];
        MaxWaitingTime = atof(argv[2]);
    } 
    fstream Logs(filename.c_str());
    string num;
    getline(Logs, num);
    int numOfRequests = atoi(num.c_str());
    //allocate the requests
    istringstream iss;
    string line;
    Requests* req = new Requests[numOfRequests];
    for( int i = 0; i < numOfRequests; i++){
        int id, priority, timeReq, timePro;
        getline(Logs, line);
        iss.clear();
        iss.str(line);
        iss >> id >> priority >> timeReq >> timePro;
        Requests temp(id , priority , timeReq, timePro);
        req[i] = temp;
    }
    //start from 1 printer
    int printers = 1;
    int avgWait = simulator( numOfRequests, req, printers);
    while( avgWait > MaxWaitingTime){
       printers++;
       avgWait = simulator( numOfRequests, req, printers);
    } 

    Logs.close();
    cout<<endl;
    cout<<"Minimum number of printers required: "<< printers<<endl;
    cout<<"Simulation with " << printers << " printers "<<endl;
    return 0;
}
