#include <iostream>
using namespace std;
//make a pattern like A B C
//                    D E F
//                    G H I
int main(){
    
    int n;
    cout<<"input n: ";
    cin>>n;

    int i=1;
    char print='A';

    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<print<<" ";
            j=j+1;
            print=print+1;
        }
        cout<<endl;
        i=i+1;
    }
    return 0;
}