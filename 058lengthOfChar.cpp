#include <iostream>
using namespace std;
int getLength(char name[]){
    int count=0;
    for(int i=0;name[i] != '\0';i++){
        count++;
    }
    return count;
}
int main(){
    char name[20];
    cout<<"Input name: ";
    cin>>name;      //space,tab and enter behave as terminators in cout command
    cout<<"name: "<<name<<endl;
    cout<<"Length of array: "<<getLength(name);
}