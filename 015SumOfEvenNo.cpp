#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"input n: ";
    cin>>n;

    int i,sum;
    sum=0;
    i=2;

    while(i<=n){
        sum=sum+i;
        i=i+2;
    }
    cout<<"Sum of even numbers in the range 1 to n is: "<<sum;
    return 0;
}