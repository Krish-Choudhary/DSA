#include <iostream>
using namespace std;
int getLength(char name[]){
    int count=0;
    for(int i=0;name[i] != '\0';i++){
        count++;
    }
    return count;
}
bool checkPalindrome(char a[],int size){
    int start=0, end=size-1;
    while(start<end){
        if(a[start]!=a[end]){
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