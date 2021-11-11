#include <iostream>
#include "Requests.h"
#include "Heap.h"
#include <sstream>
using namespace std;

int simulator( int numOfReq, Requests* req, const int numOfPrinters) {
    int *end_time = new int[numOfPrinters];
    for( int i = 0 ; i < numOfPrinters; i++){
        end_time[i] = -1;
    }

    int cur_time = 0;
    int r = 0;
    int *waiting_time = new int[numOfReq];
    for( int i = 0; i < numOfReq; i++){
        waiting_time[i] = 0;
    }
    Heap heap;
        
    while( r < numOfReq | !heap.heapIsEmpty()){
        
        while( r < numOfReq & req[r].getTimeReq() <= cur_time){
            heap.heapInsert(req[r]);
            r += 1;
        }
        
        cout<< "here" << r << endl;
        
        while( !heap.heapIsEmpty()){
            cout<< "here"<<endl;
            int free_id = -1;
            for( int i = 0; i < numOfPrinters; i++){
                if( end_time[i] <= cur_time){
                    free_id = i;
                    break;
                }
            }

            if( free_id == -1)
                break;

            Requests temp;
            temp = heap.heapDelete();
            
            int r_id = temp.getID();
            waiting_time[r_id - 1 ] = cur_time - req[r_id - 1].getTimeReq();
            end_time[free_id] = cur_time + req[r_id - 1].getTimePro();
        
        }
        cur_time += 1;
    }
    int avgTime = 0;
    for( int i =0 ; i < numOfReq; i++){
        avgTime+= waiting_time[i];
    }
    cout<< avgTime << endl;
    return avgTime;
}
