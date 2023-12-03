#include <iostream>
using namespace std;
int gcd(int a, int b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    while(a!=b){
        if(a<b){
            b=b-a;
        }
        else{
            a=a-b;
        }
    }
    return a;
}

int main(){
    int num1,num2;
    cout<<"input num1: ";
    cin>>num1;
    cout<<"input num2: ";
    cin>>num2;
    cout<<"GCD: "<<gcd(num1,num2);
}