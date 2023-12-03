#include<iostream>
using namespace std;

void printArray(int array[],int n){

    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void swapAlternate(int array[],int n){
    int first=0, second=1;
    while(second<=n){
        swap(array[first],array[second]);
        first+=2;
        second+=2;
    }
}

int main(){
    int array[6]={1,4,0,5,-2,15};
    int array1[5]={2,6,3,9,4};

    swapAlternate(array,6);
    swapAlternate(array1,5);
    printArray(array,6);
    printArray(array1,5);

    return 0;
}