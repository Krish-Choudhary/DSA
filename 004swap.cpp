#include<iostream>
using namespace std;

int main()
{
    //swap the values of a and b
    int a,b;
    cout<<"input a:";
    cin>>a;
    cout<<"input b:";
    cin>>b;

    int c;
    c=a;
    a=b;
    b=c;

    cout<<"a:"<<a<<endl<<"b:"<<b; 
}