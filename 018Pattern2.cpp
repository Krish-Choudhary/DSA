#include<iostream>
using namespace std;
// Make a pattern like  111
//                      222
//                      333
//A pattern with n rows and n columns
int main(){
    int n;
    cout<<"input n: ";
    cin>>n;

    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
        cout<<i;
        j=j+1;
        }
        cout<<endl;
        i=i+1;

    }
    return 0;
}