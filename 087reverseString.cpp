#include <iostream>
#include <string>
using namespace std;

void solve(string &str , int i, int j){
    if(i > j){
        return;
    }
    swap(str[i++],str[j--]);
    solve( str , i, j);
}

void reverseString(string &str){
    solve(str , 0 , str.length()-1);
}
int main(){
    string str = "abcdef";
    reverseString(str);
    for(int i = 0 ; i <= str.length() ; i++){
        cout << str[i];
    }

    return 0;
}