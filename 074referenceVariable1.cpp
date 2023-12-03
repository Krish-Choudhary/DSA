#include <iostream>
using namespace std;

void update1(int n){
    // call by value
    n++;
}

void update2(int &n){
    // call by reference
    n++;
}

int main(){
    int i=5;
    update1(i);
    cout<<i<<endl;
    
    update2(i);
    cout<<i<<endl;

    return 0;
}