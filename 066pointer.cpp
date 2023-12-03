#include <iostream>
using namespace std;

int main(){
    int num=5;
    int *pointer=&num;

    cout<<"Address of num: "<< pointer<<endl;
    cout<<"Address of num: "<< &num<<endl;
    cout<<"Size of pointer: "<<sizeof(pointer)<<endl;
    cout<<"value at pointer: "<<*pointer<<endl;
    cout<<endl;
    
    (*pointer)++;
    cout<<"value at pointer: "<<*pointer<<endl;
    cout<<"value of num: "<<num<<endl;
    cout<<endl;

    //copying a pointer
    int *pointer1=pointer;
    cout<<*pointer1<<"="<<*pointer<<endl;
    cout<<pointer1<<"="<<pointer<<endl;
    cout<<endl;

    cout<<"Before"<<endl;
    cout<<"Address of pointer: "<< pointer<<endl;
    pointer++;
    cout<<"after"<<endl;
    cout<<"Address of pointer: "<< pointer<<endl;
}