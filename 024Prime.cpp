//Check whether the number is prime or not by using gor loop
#include <iostream>
using namespace std;

int main(){

    int n;
    cout<<"input n: ";
    cin>>n;

    for(int i=2;i<n;i++){
        if(n%i==0){
            cout<<"Not Prime";
            return 0;
        }
    }
    cout<<"Prime";
    return 0;
}