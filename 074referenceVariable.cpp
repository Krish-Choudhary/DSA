#include <iostream>
using namespace std;
int main(){
    int i=5;
    int &j=i;       //reference variable

    cout<<i<<endl;
    cout<<j<<endl;
    cout<<endl;
    i++;
    cout<<i<<endl;
    cout<<j<<endl;
    cout<<endl;
    // If we change any one of i and j the other one will also get changed
    // as i and j are the same variable with different names
    j++;
    cout<<i<<endl;
    cout<<j<<endl;
    return 0;
}