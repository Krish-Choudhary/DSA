#include <iostream>
using namespace std;
// This code was written by me
// In this code there is one problem we can't tell the index of the element
bool binarySearch(int *arr , int size , int key){
    int start = 0 , end = size - 1;
    int mid = start + (end - start)/2; 
    // base case
    if(arr[mid] == key){
        return true;
    }
    if(size <= 0 || start > end){
        return false;
    }
    // recursive call
    bool isPresent = false;
    if(arr[mid] > key){
        // we have to go to left part
        isPresent = binarySearch(arr , size - mid - 1 , key);
    }
    else if(arr[mid] < key){
        // we have to go to right part
        isPresent = binarySearch(arr + mid + 1 , size , key);
    }
    return isPresent;

}

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << "Is 7 present: " << binarySearch(arr ,10 , 7) << endl;
    cout << "Is 17 present: " << binarySearch(arr ,10 , 17) << endl;
    return 0;
}