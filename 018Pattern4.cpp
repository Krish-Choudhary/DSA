#include<iostream>
using namespace std;
// Make a pattern like  4321
//                      4321
//                      4321
//                      4321
//A pattern with n rows and n columns
int main(){

    int n;
    cout<<"input n: ";
    cin>>n;

    int i;
    i=n;

    while(i>0){
        int j;
        j=n;
        while(j>0){
            cout<<j;
            j=j-1;
        }
        cout<<endl;
        i=i-1;
    }
    return 0;
}