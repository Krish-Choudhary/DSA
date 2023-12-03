#include <iostream>
using namespace std;

void merge(int *arr , int start , int end){
    int mid = start + (end - start)/2;
    int len1 = mid - start + 1;
    int len2 = end - mid;
    // creating 2 arrays in dynamic memory
    int *first = new int[len1];
    int *second = new int[len2];

    // copy values
    int mainArrayIndex = start;
    for(int i = 0 ; i < len1 ; i++){
        first[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = mid + 1;
    for(int i = 0 ; i < len2 ; i++){
        second[i] = arr[mainArrayIndex++];
    }

    // merge 2 sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = start;

    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2])
            arr[mainArrayIndex++] = first[index1++];
        else
            arr[mainArrayIndex++] = second[index2++];
    }
    while(index1 < len1){
        arr[mainArrayIndex++] = first[index1++];
    }
    while(index2 < len2){
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;

}

void mergeSortSolve(int *arr , int start , int end){
    // Base case
    if(start >= end)
        return;

    int mid = start + (end - start)/2;
    // sorting left part
    mergeSortSolve(arr , start , mid);
    // sorting right part
    mergeSortSolve(arr , mid + 1 , end);

    // merge
    merge(arr , start , end);
}

void mergeSort(int *arr , int size){
    mergeSortSolve(arr , 0 , size - 1);
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
    mergeSort(arr,10);
    printArray(arr,10);
    return 0;
}