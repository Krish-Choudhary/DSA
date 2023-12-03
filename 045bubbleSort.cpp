#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
  for (int i = 1; i < n ; i++) {
    // for round 1 to n-1
    bool swapped=false;
    for(int j=0;j<n-i;j++){
        //for index 0 to n-i
        //it will work on elements from index 0 to n-i+1
        //as in the if statement we are comparing arr[j] and arr[j+1]
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
            swapped=true;
        }
    }
    if(swapped==false){
        //already sorted
        break;
    }
  }
}

int main(){
    int arr[10]={4,5,2,1,45,87,46,52,56,36};
    bubbleSort(arr,10);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}