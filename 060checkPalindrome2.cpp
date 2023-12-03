#include <iostream>
using namespace std;
int getLength(char name[]){
    int count=0;
    for(int i=0;name[i] != '\0';i++){
        count++;
    }
    return count;
}
char toLowerCase(char ch){
    if(ch>='a' && ch<='z'){
        return ch;
    }
    else{
        char temp=ch-'A'+'a';
        return temp;
    }
}
bool checkPalindrome(char a[],int n){
    int start=0, end=n-1;
    while(start<end){
        if(toLowerCase(a[start])!=toLowerCase(a[end])){
            return 0;
        }
        else{
            start++;
            end--;
        }
    }
    return 1;
}

int main(){
    char a[20];
    cout<<"input a: ";
    cin>>a;
    cout<<checkPalindrome(a,getLength(a));
}