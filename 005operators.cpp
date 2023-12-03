#include<iostream>
using namespace std;

int main(){

    int num1,num2;

    cout<<"input num1:";
    cin>>num1;

    cout<<"input num2:";
    cin>>num2;
    
    //Arithmetic Operators
    cout<<"num1+num2="<<num1+num2<<endl;
    cout<<"num1-num2="<<num1-num2<<endl;
    cout<<"num1*num2="<<num1*num2<<endl;
    cout<<"num1/num2="<<num1/num2<<endl;
    cout<<"num1%num2="<<num1%num2<<endl;

    //Relational Operators
    cout<<(num1==num2)<<endl; //0 means False and 1 means True
    cout<<(num1!=num2)<<endl;
    cout<<(num1<=num2)<<endl;
    cout<<(num1>=num2)<<endl;

    //Assignment Operators
    num1+=3;
    num2-=4;
    cout<<num1<<endl;
    cout<<num2<<endl;

    return 0;
}