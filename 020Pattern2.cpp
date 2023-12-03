#include <iostream>
using namespace std;
//make a pattern like ****
//                    ***
//                    **
//                    *
//n-i+1 * in each row
int main(){
    
    int n;
    cout<<"input n: ";
    cin>>n;

    int i=1;

    while(i<=n){
        int j=1;
        
        while(j<=n-i+1){
            cout<<"*";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
    return 0;
}