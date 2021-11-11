#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include "Requests.h"

using namespace std;

const int MAX_HEAP = 10000;


class Heap{
    private:
        int size;
        Requests requests[MAX_HEAP];
    protected:
        void heapRebuild(int root);
    public:
        Heap();
        bool heapIsEmpty();
        void heapInsert(const Requests& request);
        Requests heapDelete();
};
#endif
