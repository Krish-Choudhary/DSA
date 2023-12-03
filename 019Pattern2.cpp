#include<iostream>
using namespace std;
// Make a pattern like  1
//                      2 1
//                      3 2 1
//                      4 3 2 1

int main(){
    
    int n;
    cout<<"input n: ";
    cin>>n;

    int i=1;
    while(i<=n){
        int j=1;
        int print;
        print=i;
        while(j<=i){
            cout<<print<<" ";
            j=j+1;
            print=print-1;
        }
        i=i+1;
        cout<<endl;
    }
    return 0;
}