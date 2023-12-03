#include <iostream>
using namespace std;
//make a pattern like ****
//                    _***
//                    __**
//                    ___*
// _ denotes " ". _ is just used for clarity
//Its an n*n square pattern
//each row have n-i+1 *
int main(){
    
    int n;
    cout<<"input n: ";
    cin>>n;

    int i=1;

    while(i<=n){
        int j=1;
        int space=i-1;

        while(space>0){
            cout<<" ";
            space=space-1;
        }
        
        while(j<=n-i+1){
            cout<<"*";
            j=j+1;
        }

        cout<<endl;
        i=i+1;
    }
    return 0;
}