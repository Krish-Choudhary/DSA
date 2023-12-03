#include <iostream>
using namespace std;

int main(){
    char name[20];
    cout<<"Input name: ";
    cin>>name;      //space,tab and enter behave as terminators in cout command
    //name[2]='\0';
    cout<<"name "<<name<<endl;
}