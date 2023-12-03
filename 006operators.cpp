#include<iostream>
using namespace std;

int main(){

    bool exp1,exp2;

    cout<<"exp1:";
    cin>>exp1;      //Input should be 0 or 1 only

    cout<<"exp2:";
    cin>>exp2;
    
    //Logical Operators
    cout<<(exp1&&exp2)<<endl;
    cout<<(exp1||exp2)<<endl;
    cout<<(!exp1)<<endl;
    cout<<(!exp2)<<endl;

    return 0;
}