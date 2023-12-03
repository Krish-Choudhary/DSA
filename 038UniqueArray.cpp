//This code is only valid in case of an array with odd number of elements 
//having only 1 unique element and other elements in a pair of two

#include<iostream>
using namespace std;

void printArray(int array[],int n){

    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int unique(int array[],int n){
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans^array[i];
        }
        return ans;
}

int main(){
    int array[7]={1,1,5,5,4,4,8};
    int array1[5]={2,2,6,5,6};
    int x=unique(array,7);
    int y=unique(array1,5);
    cout<<x<<endl<<y;

    return 0;
}