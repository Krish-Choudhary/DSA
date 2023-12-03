#include<iostream>
using namespace std;

void reverse(int array[],int n){
    int start=0, end=n-1;

    while(start<=end){
        swap(array[start],array[end]);
        start++;
        end--;
    }
}

void printArray(int array[],int n){

    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int array[6]={1,4,0,5,-2,15};
    int array1[5]={2,6,3,9,4};

    reverse(array,6);
    reverse(array1,5);
    printArray(array,6);
    printArray(array1,5);

    return 0;
}