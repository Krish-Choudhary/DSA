#include<iostream>
using namespace std;
// Make a pattern like  1
//                      2 2
//                      3 3 3
//                      4 4 4 4

int main(){
    
    int n;
    cout<<"input n: ";
    cin>>n;

    int i=1;

    while(i<=n){
        int j=1;
        while(j<=i){
            cout<<i<<" ";
            j=j+1;
        }
        i=i+1;
        cout<<endl;
    }
    return 0;
}