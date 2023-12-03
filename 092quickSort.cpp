#include<iostream>
using namespace std;


int partition( int arr[], int start, int end) {

    int pivot = arr[start];

    int cnt = 0;
    for(int i = start+1; i<=end; i++) {
        if(arr[i] <=pivot) {
            cnt++;
        }
    }

    //place pivot at right position
    int pivotIndex = start + cnt;
    swap(arr[pivotIndex], arr[start]);

    //left and right wala part smbhal lete h 
    int i = start, j = end;

    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot) 
        {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }

    }

    return pivotIndex;

}

void quickSortSolve(int arr[], int start, int end) {

    //base case
    if(start >= end) 
        return ;

    //partitioon karenfe
    int p = partition(arr, start, end);

    //left part sort karo
    quickSortSolve(arr, start, p-1);

    //right wala part sort karo
    quickSortSolve(arr, p+1, end);

}

void quickSort(int *arr , int size){
    quickSortSolve(arr , 0 , size - 1);
}

void printArray(int *arr , int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[10] = {1,5,9,47,85,41,23,25,45,69};
    printArray(arr,10);
    quickSort(arr,10);
    printArray(arr,10);
    return 0;
}