/*
 * Title: Sorting and Algorithm Efficiency
 * Author: Suleyman Hanyyev
 * ID: 21901009
 * Section: 1
 * Assignment: 1
 * Description: here is the part where all the implementation of sorting.h file is
 */

#include "sorting.h"

int findIndexOfLargest( const int *arr, int size, int &compCount) {
    int indexSoFar = 0;
    for( int currentIndex = 1; currentIndex < size; currentIndex++)
    {
        if( arr[currentIndex]  > arr[indexSoFar])
        {
	    indexSoFar = currentIndex;
            compCount++;
	}
	}
    return indexSoFar;
}
//selection sort implementation using for loop and swap functions
void selectionSort( int *arr, const int size, int &compCount, int &moveCount){
    for( int last = size-1; last >= 1; last--){
        int largest = findIndexOfLargest(arr, last+1, compCount);
	swap(arr[largest],arr[last]);
	moveCount += 3; //swap is 3 data moves    
	}
}

// countingSort that will be used for radixSort
void countingSort(int *arr, int size, int div){
    int tempArray[size];
    int range = 10; //from 0 to 10
    int *counter= new int[range];
    for (int i = 0; i <range; i++) {
       counter[i] = 0;
    }

    for( int i = 0; i < size; i++){
            counter[ (arr[i]/div) % 10]++;
    }

    for( int i = 1; i < range; i++){
        counter[i] += counter[i-1];
    }

    for( int i = size - 1; i >=0; i--){	
        tempArray[ counter[ (arr[i]/div)%10] - 1] = arr[i];
        counter[ (arr[i]/div) % 10]--;
    }

    for( int i = 0; i < size; i++){
        arr[i] = tempArray[i];	
    }
}
        
void merge(int *arr, int first, int mid, int last, int size, int &compCount, int &moveCount) {
    int tempArray[size]; // Temporary array
    
    int first1 = first; 
    int last1 = mid;
    int first2 = mid + 1; 
    int last2 = last;
    
    int index = first1; // Next available location in tempArray
     while ((first1 <= last1) && (first2 <= last2)) {
    // At this point, tempArray[first..index-1] is in order
        if (arr[first1] <= arr[first2]) {
	    compCount++;	//one comparison
            tempArray[index] = arr[first1];	//one DM
            first1++;
	    moveCount++;
        } else {
            tempArray[index] = arr[first2]; first2++; //second dm
            moveCount++;
	} // end if
        index++;
    } // end while
    // Finish off the first subarray, if necessary
   
     while (first1 <= last1) {
        tempArray[index] = arr[first1]; 
	moveCount++;
	first1++;
        index++;
    } // end while
    
    // Finish off the second subarray, if necessary
    while (first2 <= last2) { 
    // At this point, tempArray[first..index-1] is in order
        tempArray[index] = arr[first2]; 
        moveCount++;
	first2++; 
        index++;
    } // end for
    
    // Copy the result back into the original array
    for (index = first; index <= last; index++)
        arr[index] = tempArray[index];
	moveCount++;	//size - 1
} // end merge

void mergeSort2( int *arr, int first, int last,int size, int &compCount, int &moveCount){                                                                                 
     if (first < last) {                                                         
         int mid = first + (last - first) / 2;
         mergeSort2(arr, first, mid, size,compCount, moveCount);                      
         mergeSort2(arr, mid + 1, last,size, compCount, moveCount);                   
         
         // Merge the two halves                                                 
         merge(arr, first, mid, last, size, compCount, moveCount);
	 } // end if                         
} // end mergeSort 

void mergeSort(int *arr,const int size, int &compCount, int &moveCount) {
    int first = 0;
    int last = size-1;

    mergeSort2( arr, first, last, size, compCount, moveCount);
}

int partition( int *arr, int low, int high, int &compCount, int &moveCount){    
    int pivot = arr[low];
    moveCount++;
    int pnt = low+1;

    for( int i = low+1; i <=high; i++){
        if(arr[i] <= pivot){
	    compCount++; 
            swap(arr[i], arr[pnt]);
	    pnt++;
        }
    }
    swap( arr[pnt-1], arr[low]);
    return pnt-1;
}                      
                                                                                
void swap( int *arr, int &first, int &second, int &moveCount){                  
   int temp = arr[first];                                                       
   arr[first] = arr[second];                                                    
   arr[second] = temp;                                                           
   moveCount+=3;
}   

void quickSort2( int *arr, const int low, const int high, int &compCount, int &moveCount){
    if( low < high ){
        int pivot_loc = partition( arr, low, high, compCount, moveCount);
        quickSort2( arr, low, pivot_loc-1, compCount, moveCount);
        quickSort2( arr, pivot_loc+1, high, compCount, moveCount);
    } // end quickSort
}

void quickSort(int *arr, const int size, int &compCount, int &moveCount) {
    int low  = 0;
    int high = size-1;
    quickSort2(arr, low, high, compCount, moveCount);
}

int findMax(int *arr, const int size){
	int max = arr[0];
	for( int i = 1; i < size; i++){
		if(arr[i] > max)
			max = arr[i];
	}
	return max;
}
		  
void radixSort( int *arr, const int size){
   	int max = findMax( arr, size); //finding the max of the array
	for( int div = 1; max/div > 1; div *= 10){
        countingSort(arr, size, div);
    }
}

void displayArray( const int *arr, const int size) {
    cout<< " Elements of the Array are: ";
    for( int i = 0; i < size; i++){
        cout<< arr[i] << "  ";
    }
    cout<< "\n";
}

void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size){
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];
    for( int i = 0 ; i < size; i++){
        arr1[i] = rand() % 100 + 1;
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
    }
}
 
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size){
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];
    int number = 1;
    for( int i = 0; i < size; i++){
        arr1[i] = number;
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
        number += 2;
    }
}

void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size){
     arr1 = new int[size];
     arr2 = new int[size];
     arr3 = new int[size];
     arr4 = new int[size];
     int number = 455000;
     for( int i = 0; i < size; i++){
         arr1[i] = number;
         arr2[i] = arr1[i];
         arr3[i] = arr1[i];
         arr4[i] = arr1[i];
         number -= 2;
     }
} 
void performanceAnalysis(int &compCount, int &moveCount){
    // Initialization
    int *arr1;
    int *arr2;
    int *arr3;
    int *arr4;

    clock_t time;
    double s_duration;
    double m_duration; 
    double q_duration;
    double r_duration;

// Starting to print
    cout<<" Using Random Inputs " <<endl;
    cout<<"--------------------------------------------"<<endl;
    cout<<" Analysis of Selection Sort " <<endl;
    cout<< "Array Size  Elapsed Time  compCount  moveCount  "<<endl;
    for( int size = 6000; size <= 30000; size +=4000){
        createRandomArrays( arr1, arr2, arr3, arr4, size);

        time = clock();
        selectionSort(arr1,size,compCount, moveCount);
        time = clock() - time;
        s_duration =1000 * (double)time /CLOCKS_PER_SEC;
        cout<< size << "    " << s_duration << "ms     " << compCount<< "   " << moveCount <<endl;
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
        delete [] arr4;
	moveCount = 0;
	compCount = 0;

    }

    cout<<"--------------------------------------------"<<endl;
    cout<<" Analysis of Merge Sort " <<endl;
    cout<<" Array Size  Elapsed Time  compCount moveCount  "<<endl;
    for( int size = 6000; size <= 30000; size +=4000){
        createRandomArrays( arr1, arr2, arr3, arr4, size);

        time = clock();
        mergeSort(arr2,size,compCount, moveCount);
        time = clock() - time;
        m_duration = 1000 * (double)time /CLOCKS_PER_SEC;
        cout<< size << "      " << m_duration << "ms       " << compCount<< "   " << moveCount <<endl;
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
        delete [] arr4;
        compCount = 0;
	moveCount = 0;
    }

    cout<<"--------------------------------------------"<<endl;
    cout<<" Analysis of Quick Sort " <<endl;
    cout<<" Array Size    Elapsed Time   compCount  moveCount  "<<endl;
    for( int size = 6000; size <= 30000; size +=4000){
        createRandomArrays( arr1, arr2, arr3, arr4, size);

        time = clock();
        quickSort(arr3,size,compCount, moveCount);
        time = clock() - time;
        q_duration = 1000 * (double)time /CLOCKS_PER_SEC;
        cout<< size << "     " << q_duration << "ms      " << compCount<< "   " << moveCount <<endl;
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
        delete [] arr4;
        moveCount = 0;
	compCount = 0;
	}


    cout<<"--------------------------------------------"<<endl;
    cout<<" Analysis of Radix Sort " <<endl;
    cout<<" Array Size   Elapsed Time "<<endl;
    for( int size = 6000; size <= 30000; size +=4000){
        createRandomArrays( arr1, arr2, arr3, arr4, size);

        time = clock();
        radixSort(arr4,size);
        time = clock() - time;
        r_duration = 1000 * (double)time /CLOCKS_PER_SEC;
        cout<< size << "      " << r_duration <<"ms"<<endl;
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
        delete [] arr4;
    }

    cout<<" Using Ascending Inputs " <<endl;
    cout<<"--------------------------------------------"<<endl;
    cout<<" Analysis of Selection Sort " <<endl;
    cout<<" Array Size  Elapsed Time  compCount moveCount  "<<endl;
    for( int size = 6000; size <= 30000; size +=4000){
        createAscendingArrays( arr1, arr2, arr3, arr4, size);
        time = clock();
        selectionSort(arr1,size,compCount, moveCount);
        time = clock() - time;
        s_duration = 1000 * (double)time /CLOCKS_PER_SEC;
        cout<< size << "     " << s_duration << "ms     " << compCount<<"    " << moveCount <<endl;
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
        delete [] arr4;
        moveCount = 0;
	compCount = 0;
    }

    cout<<"--------------------------------------------"<<endl;
    cout<<" Analysis of Merge Sort " <<endl;
    cout<<" Array Size Elapsed Time compCount moveCount  "<<endl;
    for( int size = 6000; size <= 30000; size +=4000){
        createAscendingArrays( arr1, arr2, arr3, arr4, size);

        time = clock();
        mergeSort(arr2,size,compCount, moveCount);
        time = clock() - time;
        m_duration = 1000 * (double)time /CLOCKS_PER_SEC;
        cout<< size << "      " << m_duration << "ms    " << compCount<< "     " << moveCount <<endl;
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
        delete [] arr4;
        moveCount = 0;
	compCount = 0;
    }

    cout<<"--------------------------------------------"<<endl;
    cout<<" Analysis of Quick Sort " <<endl;
    cout<<" Array Size   Elapsed Time  compCount  moveCount  "<<endl;
    for( int size = 6000; size <= 30000; size +=4000){
        createAscendingArrays( arr1, arr2, arr3, arr4, size);

        time = clock();
        quickSort(arr3,size,compCount, moveCount);
        time = clock() - time;
        q_duration = 1000 * (double)time /CLOCKS_PER_SEC;
        cout<< size << "     " << q_duration << " ms     " << compCount<< "   " << moveCount <<endl;
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
        delete [] arr4;
        moveCount = 0;
	compCount = 0;
    }

    cout<<"--------------------------------------------"<<endl;
    cout<<" Analysis of Radix Sort " <<endl;
    cout<<" Array Size  Elapsed Time "<<endl;
    for( int size = 6000; size <= 30000; size += 4000){
        createAscendingArrays( arr1, arr2, arr3, arr4, size);

        time = clock();
        radixSort(arr4,size);
        time = clock() - time;
        r_duration = 1000 * (double)time /CLOCKS_PER_SEC;
        cout<< size << "    " << r_duration << "ms"<<endl;
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
        delete [] arr4;
    }
    cout<<" Using Descending Inputs " <<endl;
    cout<<"--------------------------------------------"<<endl;
    cout<<" Analysis of Selection Sort " <<endl;
    cout<< "Array Size  Elapsed Time  compCount   moveCount  "<<endl;
    for( int size = 6000; size <= 30000; size +=4000){
        createDescendingArrays( arr1, arr2, arr3, arr4, size);

        time = clock();
        selectionSort(arr1,size,compCount, moveCount);
        time = clock() - time;
        s_duration = 1000 * (double)time /CLOCKS_PER_SEC;
        cout<< size << "      " << s_duration << "ms    " << compCount<< "   " << moveCount <<endl;
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
        delete [] arr4;
        moveCount = 0;
	compCount = 0;
    }

    cout<<"--------------------------------------------"<<endl;
    cout<<" Analysis of Merge Sort " <<endl;
    cout<<"Array Size  Elapsed Time compCount moveCount  "<<endl;
    for( int size = 6000; size <= 30000; size +=4000){
        createDescendingArrays( arr1, arr2, arr3, arr4, size);

        time = clock();
        mergeSort(arr2,size,compCount, moveCount);
        time = clock() - time;
        m_duration = 1000 * (double)time/CLOCKS_PER_SEC;
        cout<< size << "   " << m_duration << "ms     " << compCount<< "   " << moveCount <<endl;
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
        delete [] arr4;
        moveCount = 0;
	compCount = 0;
    }

    cout<<"--------------------------------------------"<<endl;
    cout<<" Analysis of Quick Sort " <<endl;
    cout<<" Array Size  Elapsed Time compCount  moveCount  "<<endl;
    for( int size = 6000; size <= 30000; size +=4000){
        createDescendingArrays( arr1, arr2, arr3, arr4, size);

        time = clock();
        quickSort(arr3,size,compCount, moveCount);
        time = clock() - time;
        q_duration = 1000 *  (double)time /CLOCKS_PER_SEC;
        cout<< size << "     " << q_duration << "ms     " << compCount<< "    " << moveCount <<endl;
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
        delete [] arr4;
        moveCount = 0;
	compCount = 0;
    }

    cout<<"--------------------------------------------"<<endl;
    cout<<" Analysis of Radix Sort " <<endl;
    cout<<" Array Size  Elapsed Time "<<endl;
    for( int size = 6000; size <= 30000; size +=4000){
        createDescendingArrays( arr1, arr2, arr3, arr4, size);

        time = clock();
	radixSort(arr4,size);
        time = clock() - time;
        r_duration = 1000 * (double)time /CLOCKS_PER_SEC;
        cout<< size << "   " << r_duration <<"ms"<<endl;
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
        delete [] arr4;
    }
}


