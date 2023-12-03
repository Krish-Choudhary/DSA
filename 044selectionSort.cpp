#include<iostream>
using namespace std;

void selectionSort(int arr[], int n)
{   
    for(int i=0;i<n-1;i++){
        int minIndex=i;

        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        if(i!=minIndex){
        swap(arr[i],arr[minIndex]);         //optimised the code and decreased the number of times this line runs
        }
    }
}

int main(){
    int arr[10]={4,5,2,1,46,87,45,52,56,36};
    selectionSort(arr,10);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}