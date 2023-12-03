#include<iostream>
using namespace std;

int main(){
    int a,b;

    cout<<"Input a: ";
    cin>>a;

    cout<<"Input b: ";
    cin>>b;

    if (a>0){
        cout<<"a is positive"<<endl;
    }
    
    else if(a<0){
        cout<<"a is negative"<<endl;
        }
    else{
            cout<<"a is zero";
        }
    if (b>0){
        cout<<"b is positive"<<endl;
    }
    
    else if(b<0){
        cout<<"b is negative"<<endl;
        }
    else{
            cout<<"b is zero";
        }

return 0;
}