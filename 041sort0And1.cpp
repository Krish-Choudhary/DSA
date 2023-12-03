#include <iostream>
using namespace std;
//using 2 pointer approach

void printArray(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void sort0And1(int arr[],int size){
    int left=0 , right=size-1;

    while(left<=right){
        if(arr[left]==1 && arr[right]==0){
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
        else if(arr[left]==0){
            left++;
        }
        else if(arr[right]==1){
            right--;
        }
    }
}

int main(){
    int arr[8]={0,1,0,1,1,1,0,0};
    sort0And1(arr,8);
    printArray(arr,8);
    return 0;
}