#include<iostream>
using namespace std;
int main(){
    int array1[10]={0};         //[0,0,0,0,0,0,0,0,0,0]
    cout<<array1[5]<<endl;

    int array2[10]={1};         //[1,0,0,0,0,0,0,0,0,0]
    cout<<array2[0]<<endl;
    cout<<array2[5]<<endl;

    int array3[10];
    for(int i=0;i<10;i++){
        array3[i]=5;            //[5,5,5,5,5,5,5,5,5,5]
        cout<<array3[i]<<endl;
    }
    return 0;
}