#include<iostream>
using namespace std;

void insertionSort(int arr[],int n){
    
    for(int i = 1; i < n; i++) {
        //for round 1 to n-1
        int temp = arr[i];
        int j = i - 1;
        for(j; j >= 0; j--) {
            
            if(arr[j] > temp) {
                //shift
                arr[j + 1] = arr[j];
            }
            else { // already sorted hai, ruk jao
                break;
            }
            
        }
        //copy temp value
        arr[j + 1] = temp;
    } 
}

int main(){
    int arr[10]={4,5,2,1,46,87,45,52,56,36};
    insertionSort(arr,10);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}