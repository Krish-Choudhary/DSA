#include<iostream>
using namespace std;
// Make a pattern like  1234
//                      1234
//                      1234
//                      1234
//A pattern with n rows and n columns
int main(){
    
    int n;
    cout<<"input n: ";
    cin>>n;
    
    int i=1;

    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<j;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
    return 0;
}