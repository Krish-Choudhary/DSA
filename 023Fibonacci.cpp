#include<iostream>
using namespace std;
//Print fibonacci series i.e. a_n+2 = a_n + a_n+1
// 0,1,1,2,3,5,8,13...

int main(){
    //we have to assume first two numbers i.e. 0 and 1
    int a=0,b=1,n;
    cout<<"input n: ";
    cin>>n;
    if(n<=0){
        return 0;
    }
    if(n>=1){
        cout<<a<<" ";
    }
    if(n>=2){
        cout<<b<<" ";

    }
    if(n>=3){
    for(int i=3;i<=n;i++){
        int x=a+b;
        cout<<x<<" ";
        a=b;
        b=x;
    }
    }
    return 0;
}