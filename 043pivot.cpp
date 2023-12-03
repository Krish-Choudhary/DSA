#include <iostream>
using namespace std;
int getPivotElement(int arr[],int size){
    int start=0, end=size-1, mid=start+(end-start)/2;

    while(start<end){
        if(arr[mid]>=arr[0]){    //element lie on line 1 (reference to notes)
            start=mid+1;
        }
        else{                    // element lie on line 2
            end=mid;
        }
        mid=start+(end-start)/2;
    }
    // In case of pivot element start=end
    // So we can return any 1 of start or end
    return end;
}

int main(){
    int arr[5]={3,8,10,1,2};
    int pivot=getPivotElement(arr,5);
    cout<<"Pivot element is: "<<arr[pivot];
    return 0;
}