#include <iostream>
using namespace std;
//make a pattern like ___1
//                    __23
//                    _456
//                    78910
// _ denotes " ". _ is just used for clarity
//Its an n*n square pattern
int main(){
    
    int n;
    cout<<"input n: ";
    cin>>n;

    int i=1;
    int count=1;

    while(i<=n){
        int j=1;
        int space=n-i;

        while(space>0){
            cout<<" ";
            space=space-1;
        }
        
        while(j<=i){
            cout<<count;
            j=j+1;
            count=count+1;
        }
        cout<<endl;
        i=i+1;
    }
    return 0;
}