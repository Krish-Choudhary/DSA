#include <iostream>
using namespace std;

int fibonnaci(int n){
    if(n == 1){
        return 0;
        // first fibonnaci number = 0
    }

    else if(n == 2){
        return 1;
        // second fibonnaci number = 1
    }

    else{
        return fibonnaci(n - 1) + fibonnaci(n - 2);
    }
}

int main(){
    int n;
    cout << "input n: ";
    cin >> n;
    cout << n << "th element of fibonnaci series is " << fibonnaci(n);
    return 0;
}