#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"input n:";
    cin>>n;

    int array[n];
    for(int i=0;i<n;i++){
        cout<<"input "<<i+1<<"th element of array: ";
        cin>>array[i];
    }
    int max=array[0],min=array[0];
    for(int i=0;i<n;i++){
        if(array[i]>max){
            max=array[i];
        }
        if(array[i]<min){
            min=array[i];
        }
    }
    cout<<"Max: "<<max<<endl<<"Min: "<<min;
    return 0;
}