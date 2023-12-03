#include <iostream>
using namespace std;

int BinarySearch(int arr[], int size, int key){
    
    int start=0,end=size-1;
    //int mid=(start+end)/2;
    //So that (start+end) do not exceed the int limit i.e. 2^32 - 1
    int mid=start+(end-start)/2;

    while (start<=end){
        if(arr[mid]==key){
            return mid;
        }
        else if(key<arr[mid]){
            end=end-1;
        }
        else if(key>arr[mid]){
            start=mid+1;
        }
        //mid=(start+end)/2;
        mid=start+(end-start)/2;
    }
    return -1;
}

int main(){
    int array[6]={2,4,6,8,12,18};
    int array1[5]={3,8,11,14,16};
    
    int index=BinarySearch(array,6,12);
    int index1=BinarySearch(array1,5,11);
    cout<<index<<endl<<index1;
}