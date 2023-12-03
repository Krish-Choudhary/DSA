#include<iostream>
using namespace std;
int printArray(int array[],int n){
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"input n:";
    cin>>n;

    int array[n];
     for(int i=0;i<n;i++){
        int x;
        cin>>x;
        array[i]=x;
    }
   
    printArray(array,n);
    cout<<"Size of array is "<<sizeof(array)/sizeof(int);
    //size of array= memory used by array(size of data type of array*n)/size of data type of array=n
    //In this case data type of array is int so,
    //size of data type of array = 4
}