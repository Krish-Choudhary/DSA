#include <iostream>
using namespace std;
int main(){
    
    int num1,num2;
    char operation;
    
    cout<<"Input num1: ";
    cin>>num1;
    
    cout<<"input num2: ";
    cin>>num2;

    cout<<"Which Operation do you want to perform: ";
    cin>>operation;

    switch(operation){
        case '+': cout<<(num1+num2)<<endl;
        break;
        case '-': cout<<(num1-num2)<<endl;
        break;
        case '*': cout<<(num1*num2)<<endl;
        break;
        case '/': cout<<(num1/num2)<<endl;
        break;
        case '%': cout<<(num1%num2)<<endl;
        break;
        default: cout<<"This operation is not supported";
    }
    return 0;
}