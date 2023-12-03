//Given AP 3n+7
// Take input n and print an
#include <iostream>
using namespace std;
int nthTerm(int n){
    cout<<"input n:";
    cin>>n;
    return (3*n)+7;
}
int main(){
    int n;
    cout<<nthTerm(n);
}