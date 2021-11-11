#include "Heap.h"
Heap:: Heap(): size(0){}

bool Heap::heapIsEmpty(){
    return (size==0);
}

Requests Heap::heapDelete() {
        Requests temp;
        temp = requests[0];
        requests[0] = requests[--size];
        heapRebuild(0);
        return temp;    
}

void Heap:: heapRebuild(int root){
    int child = 2 * root + 1;
    if( child < size) {
        int rightChild = child + 1;

        if ( (rightChild < size) &&
		     (requests[rightChild].getPriority() > requests[child].getPriority()) )
			child = rightChild; 	// index of larger child

		// If root’s item is smaller than larger child, swap values
		if ( requests[root].getPriority() < requests[child].getPriority() ) {
			Requests temp = requests[root];
			requests[root] = requests[child];
			requests[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
		}
    }
}

void Heap:: heapInsert(const Requests& request) {
    if (size >= MAX_HEAP)
		throw "HeapException: Heap full";

	// Place the new item at the end of the heap
	requests[size] = request;

	// Trickle new item up to its proper position
	int place = size;
	int parent = (place - 1)/2;
    while ( (place > 0) && (requests[place].getPriority() > requests[parent].getPriority()) ) {
		if( requests[place].getTimeReq() > requests[parent].getTimeReq()){
            Requests temp = requests[parent];
	    	requests[parent] = requests[place];
	    	requests[place] = temp;

		    place = parent;
		    parent = (place - 1)/2;
        }
    }
 	++size;
}
