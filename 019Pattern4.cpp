#include <iostream>
using namespace std;
//make a pattern like A B C
//                    A B C
//                    A B C
//toprint='A'+j-1
int main(){
    
    int n;
    cout<<"input n: ";
    cin>>n;

    int i=1;

    while(i<=n){
        int j=1;
        while(j<=n){
            char print;
            print='A'+j-1;
            cout<<print<<" ";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
    return 0;
}