#include<iostream>
using namespace std;

int main(){

    char a;
    cout<<"input a: ";
    cin>>a;
    // 'A' is 65
    // 'a' is 97
    // '0' is 48
    
    if(a>='A' && a<='Z'){
        cout<<"a is Upper case";
    }

    else if(a>='a' && a<='z'){
        cout<<"a is Lower case";
    }

    else if(a>='0' && a<= '9'){
        cout<<"a is Numeric";
    }

    return 0;
}