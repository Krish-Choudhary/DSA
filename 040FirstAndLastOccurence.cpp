#include <iostream>
using namespace std;

int FirstOccurence(int arr[], int size, int key){
    
    int start=0,end=size-1;
    //int mid=(start+end)/2;
    //So that (start+end) do not exceed the int limit i.e. 2^32 - 1
    int mid=start+(end-start)/2;
    int ans=-1;

    while (start<=end){
        if(arr[mid]==key){
            ans=mid;
            end=mid-1;
        }
        else if(key<arr[mid]){
            end=mid-1;
        }
        else if(key>arr[mid]){
            start=mid+1;
        }
        //mid=(start+end)/2;
        mid=start+(end-start)/2;
    }
    return ans;
}

int LastOccurence(int arr[], int size, int key){
    
    int start=0,end=size-1;
    //int mid=(start+end)/2;
    //So that (start+end) do not exceed the int limit i.e. 2^32 - 1
    int mid=start+(end-start)/2;
    int ans=-1;

    while (start<=end){
        if(arr[mid]==key){
            ans=mid;
            start=mid+1;
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
    return ans;
}

int main(){
    int even[5]={1,2,3,3,3};
    cout<<"First Occurence of 3 is at index: "<<FirstOccurence(even,5,3)<<endl<<"Last Occurence of 3 is at index: "<<LastOccurence(even,5,3);
    return 0;
}