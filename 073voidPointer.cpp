#include <iostream>
#include <string>
using namespace std;
int main(){
    int i=5;
    float f=21.5;
    double d=54.254;
    string s="Krish";

    //creating a void pointer
    void *ptr;
    //it can point to any data type
    
    //pointing to float data type
    ptr=&f;
    //pointing to double data type
    ptr=&d;
    //pointing to string data type
    ptr=&s;
    //pointing to integer data type
    ptr=&i;
    cout<<"sab sahi chal rha hai";

    // cout<<*ptr;
    // void pointer can't be derefrence
    // we can do that by typecasting

    int *integerPointer = (int *)ptr;
    cout<<*integerPointer;
    return 0;
}