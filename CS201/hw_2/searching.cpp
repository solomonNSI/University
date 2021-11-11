/* 
 * Suleyman Hanyyev
 * 02/04/2021
 * ID: 21901009
 * 4 sorting algorithms. Testing their efficiency and time complexity
 */

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>


using namespace std;

int firstAlgorithm( int *arr, int size, int key){
    for(int index = 0; index < size; index++){
        if(arr[index] == key)
            return index;
    }
    return -1;
}

int secondAlgorithm( int *arr, int size, int key){
    if(size < 1)
        return -1;

    if( arr[size-1] == key)
        return size - 1;
    
    return secondAlgorithm( arr, size -1, key);
}

int thirdAlgorithmHelper( int *arr, int first, int last, int key){
    if( last >= first) {
        int mid = (last + first)/ 2;
    
        if(arr[mid] == key)
            return mid;

        if( arr[mid] > key)
            return thirdAlgorithmHelper( arr, first, mid - 1, key);

        return thirdAlgorithmHelper( arr, mid+1, last , key);
    }
    return -1;
}

int thirdAlgorithm( int *arr, int size, int key){
    if( size < 1)
        return -1;
    
    int index;
    int first = 0;
    index = thirdAlgorithmHelper(arr, first, size - 1, key);
    return index;
} 

int fourthAlgorithm( int *arr, int size, int key){
    int a = 0;
    int x = floor(sqrt(size));

    while( arr[ min( x, size) - 1] < key){
        a = x;
        x += floor(sqrt(size));
        if( a >= size)
            return -1;
    }
    while( arr[a] < key){
        a = a+1;
        if( a == min(x, size))
            return -1;
    }
    if(arr[a] == key)
        return a;
    else
        return -1;
}

int main() {
    cout<< "Start of the program........"<<endl;
    double duration;
    clock_t startTime;

    vector<int> sizes = {10, 100, 500, 1000, 5000, 10000, 25000, 50000, 75000, 100000, 150000, 200000, 250000};
    cout<< " 10, 100, 500, 1000, 5000, 10000, 50000, 100000 are the sizes of the array"<<endl;
    int size;

    for( int j = 0; j < sizes.size(); j++){
        size = sizes[j];
        cout<< "....Size of the Array :  "<< size<<endl;
        int* arr = new int[size];

        //initialize the elements in the array
        // in random order and with random values
        for( int i = 0; i < size; i++){
            arr[i] = 1 + (rand() % (size*10));
        }
        // sort the array in ascending order
        sort(arr, arr + size);
            //k is for the number of algorithms
        for( int k = 0; k < 4; k++){
            
        // a-d parts of the program
            for(int type = 0; type <=3; type++){
                int key;
                int index;

                //a part
                if(type == 0){
                    key = arr[(size*5) / 100 ]; //i.e the number will be the 5th percentile 
                }//part b
                if(type == 1){
                    key = arr[(size * 50) /100]; // 50th percentile
                }//part c
                if(type == 2){
                    key = arr[(size * 90) / 100]; //90th percentile
                }//part d
                if(type == 3){
                    key = 0; // 0 is not in the array
                }
                // does these comparisons affect the performance?
                if(k == 0){
                    cout<< "First Algorithm"<<endl;
                    startTime = clock();
                    index = firstAlgorithm(arr, size, key); 
                    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
                    cout<< "Execution took "<<duration <<" milliseconds"<< endl;
                }else if (k == 1){
                    cout<< "Second Algorithm"<<endl;
                    startTime = clock();
                    index = secondAlgorithm(arr, size, key); 
                    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
                    cout<< "Execution took "<<duration <<" milliseconds"<< endl;
                }else if (k == 2){
                    cout<< "Third Algorithm"<<endl;
                    startTime = clock();
                    index = thirdAlgorithm(arr, size, key); 
                    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
                    cout<< "Execution took "<<duration <<" milliseconds"<< endl;
                }else if (k == 3){
                    cout<< "Fourth Algorithm"<<endl;
                    startTime = clock();
                    index = fourthAlgorithm(arr, size, key); 
                    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
                    cout<< "Execution took "<<duration <<" milliseconds"<< endl;
                }
            }
        cout<<endl;
        }
        cout<<endl;
        delete [] arr;
    }
}
