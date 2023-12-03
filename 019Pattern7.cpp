#include <iostream>
using namespace std;
//make a pattern like A
//                    B B
//                    C C C
int main(){
    
    int n;
    cout<<"input n: ";
    cin>>n;

    int i=1;

    while(i<=n){
        int j=1;
        
        while(j<=i){
            char print;
            print='A'+i-1;
            cout<<print<<" ";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
    return 0;
}