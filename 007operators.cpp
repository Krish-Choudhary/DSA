#include<iostream>
using namespace std;

int main(){
    
    int num1,num2;
    //bitwise operator
    cout<<"input num1: ";
    cin>>num1;

    cout<<"input num2: ";
    cin>>num2;

    cout<<"num1<<num2= "<<(num1<<num2)<<endl;   //multiply the decimal form by 2^num2
    cout<<"num1>>num2= "<<(num1>>num2)<<endl;   //divide the decimal form by 2^num2
    cout<<"num1&num2= "<<(num1&num2)<<endl;     //and function in binary form
    cout<<"num1|num2= "<<(num1|num2)<<endl;     //or function in binary form
   
    return 0;
}