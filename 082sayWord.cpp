#include <iostream>
#include <string>
using namespace std;

void sayDigit(int n){
    string word[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    if(n == 0){
        return;
    }
    int digit = n % 10;
    n = n / 10;

    sayDigit(n);

    cout << word[digit] << " ";
}

int main(){
    int n;
    cout << "input n: ";
    cin >> n;
    sayDigit(n);

    return 0;
}