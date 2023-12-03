#include <iostream>
using namespace std;
//make a pattern like C
//                    B C
//                    A B C
int main(){
    
    int n;
    cout<<"input n: ";
    cin>>n;

    int i=1;

    while(i<=n){
        char print;
        print='A'+n-i;
        int j=1;
        
        while(j<=i){
            cout<<print<<" ";
            j=j+1;
            print=print+1;
        }
        cout<<endl;
        i=i+1;
    }
    return 0;
}