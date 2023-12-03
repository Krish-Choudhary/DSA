#include <iostream>
using namespace std;
//make a pattern like A
//                    B C
//                    C D E
// toprint='A'+i+j-2
int main(){
    
    int n;
    cout<<"input n: ";
    cin>>n;

    int i=1;

    while(i<=n){
        int j=1;
        
        while(j<=i){
            char print;
            print='A'+i+j-2;
            cout<<print<<" ";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
    return 0;
}