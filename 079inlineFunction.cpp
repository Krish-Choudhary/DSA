#include <iostream>
using namespace std;
int a = 5 ; 
// global variable

inline int getMax(int a,int b){
    return (a > b) ? a : b ;
}

int main(){
    int b = 10 ;
    cout<< getMax(a,b) ;

    return 0;
}