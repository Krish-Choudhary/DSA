#include <iostream>
//for using pow function we have to include the package math.h
#include <math.h>
using namespace std;
int main(){
    int n;
    cout<<"Input n: ";
    cin>>n;

    int ans=0,i=0;

    while(n!=0){
        int bit=n&1;
        ans=(bit*pow(10,i))+ans;
        n=n>>1;
        i++;
    }
    cout<<ans;
    return 0;
}