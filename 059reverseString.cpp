#include <iostream>
using namespace std;
int getLength(char name[]){
    int count=0;
    for(int i=0;name[i] != '\0';i++){
        count++;
    }
    return count;
}
void reverse(char name[], int size){
    int start=0;
    int end=size-1;
    while(start<end){
        swap(name[start++],name[end--]);
    }
}

int main(){
    char name[20];
    cout<<"input name: ";
    cin>>name;
    cout<<"before reverse: "<<name;
    reverse(name,getLength(name));
    cout<<endl;
    cout<<"after reverse: "<<name;
}