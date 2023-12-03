#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"input n: ";
    cin>>n;

    int i=2;
    while(i<n){
        if(n%i==0){
            cout<<"Given number is not a prime number"<<endl;
            return 0;
        }
        i=i+1;
    }
    cout<<"Given number is a prime number";
    return 0;
    }