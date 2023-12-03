#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"input n: ";
    cin>>n;

    int i=1;
    int sum=0;
    while(i<=n){
        sum=sum+i;
        i=i+1;
    }
    cout<<"sum of numbers ranging from 1 to n is: "<<sum;
    return 0;
}