#include<iostream>
using namespace std;
// Make a pattern like  9 8 7
//                      6 5 4
//                      3 2 1
//A pattern with n rows and n columns
//The first element is n^2
int main(){
    
    int n;
    cout<<"input n: ";
    cin>>n;

    int i=1;
    int count;
    count=n*n;

    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<count<<" ";
            count=count-1;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
    return 0;
}