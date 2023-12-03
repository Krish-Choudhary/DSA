#include <iostream>
using namespace std;

void printArray(int *arr, int sizeOfArray){
    //inside this function we have the access to the original array
    //because we have passed *arr= address of first memory block of arr

    for(int i=0;i<sizeOfArray;i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
    arr[2]=0;
}
int main(){
    int arr[5]={10,20,30,40,50};
    printArray(arr,5);
    for(int i=0;i<5;i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;

    return 0;
}