#include<iostream>
using namespace std;

int main(){

int num=4;
char name='n';
    cout<<"size of char: "<<sizeof(name)<<endl;     //1
    cout<<"size of int: "<<sizeof(num)<<endl;      //4

    bool flag;
    num==name? flag = true : flag = false;
    cout<<flag<<endl;                               //0
    cout<<"address of num1: "<<(&num)<<endl;

    //Post and Pre increment operator
    cout<<"num++ = "<<(num++)<<endl;                //4 >>>>> 5
    cout<<"++num = "<<(++num)<<endl;                //5 >>>>> 6

return 0;
}