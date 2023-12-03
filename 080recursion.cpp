#include <iostream>
using namespace std;

int factorial(int n){
    if(n == 0){
        // base case
        return 1;
    }
    else{
        return n * factorial(n - 1);
    }
}

int power(int n, int m){
    if(m==0){
        return 1;
    }

    else{
        return n * power(n,m-1);
    }
}

void counting(int start, int end){
    if(start == end){
        cout << start;
    }

    else{
        cout << start << " ";
        counting(start+1, end);
    }
}

int main(){
    // factorial
    int n;
    cout << "Input n: ";
    cin >> n;
    cout << n << "!= " << factorial(n);
    cout << endl << endl;

    // power n^m
    int m;
    cout << "input m: ";
    cin >> m;
    cout << "n^m =" << power(n,m) << endl << endl;

    // counting
    counting(n,m);

    return 0;
}