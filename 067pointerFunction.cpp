#include <iostream>
using namespace std;

void print(int *p){
    cout<<*p<<endl;
}

void update(int *p){
    p=p+1;
    *p=*p+1;
    cout<<"inside update function: "<<p<<endl;
}

int main(){
    int value=5;
    int *p=&value;
    print(p);
    cout<<"Before update function: "<<p<<" "<<*p<<endl;
    update(p);
    cout<<"After update function: "<<p<<" "<<*p<<endl;
    return 0;
}