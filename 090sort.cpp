#include <iostream>
using namespace std;

void bubbleSort(int *arr, int size){
    // base case
    if(size == 0 || size == 1){
        // sorted
        return;
    }

    // solving for 1 element
    for(int i = 0; i < size ; i++){
        if(arr[i] > arr[i+1])
            swap(arr[i],arr[i+1]);
    }
    // 1 element i.e. maximum is at its correct spot in the end
    // recurssive call
    bubbleSort(arr,size-1);
}

void selectionSort(int *arr , int size){
    // base case
    if(size == 0 || size == 1){
        // sorted
        return;
    }
    // solving for 1 element
    int minIndex = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] < arr[minIndex])
            minIndex = i;
    }
    swap(arr[0],arr[minIndex]);
    // 1 case solved, minimum elemnet at 1st spot
    // recurssive call
    selectionSort(arr+1,size-1);
}

void insertionSort(int *arr , int size){
    // Base case
    if (size <= 1)
        return;
  
    // Sort first n-1 elements
    insertionSort( arr, size-1 );
  
    // Insert last element at its correct position
    int last = arr[size - 1];
    int j = size-2;
  
    /* Move elements of arr[0..i-1], that are
    greater than key, to one position ahead
    of their current position */
    while (j >= 0 && arr[j] > last)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}


void printArray(int *arr , int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[10] = {1,5,9,47,85,41,23,25,45,69};
    bubbleSort(arr,10);
    printArray(arr, 10);

    int arr1[10] = {1,5,9,47,85,41,23,25,45,69};
    selectionSort(arr1,10);
    printArray(arr1,10);

    int arr2[10] = {1,5,9,47,85,41,23,25,45,69};
    insertionSort(arr2,10);
    printArray(arr2,10);

    return 0;
}