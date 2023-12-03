#include <iostream>
using namespace std;
//make a pattern like ___1___
//                    __123__
//                    _12321_
//                    1234321
// _ denotes " ". _ is just used for clarity
int main(){
    
    int n;
    cout<<"input n: ";
    cin>>n;

    int i=1;

    while(i<=n){
        int j=1;
        int space=n-i;

        while(space>0){
            cout<<" ";
            space=space-1;
        }
        
        while(j<=i){
            cout<<j;
            j=j+1;
        }
        int start=i-1;
        while(start>0){
            cout<<start;
            start=start-1;
        }
        space=n-i;
        while(space>0){
            cout<<" ";
            space=space-1;
        }
        cout<<endl;
        i=i+1;
    }
    return 0;
}