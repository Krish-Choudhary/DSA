#include <iostream>
using namespace std;
int main(){
    int i=5;
    int *ptr1=&i;
    int **ptr2=&ptr1;

    cout<<"value of i= "<<i<<" = "<<*ptr1<<" = "<<**ptr2<<endl;

    cout<<"address of i= "<<&i<<" = "<<ptr1<<" = "<<*ptr2<<endl;

    cout<<"address of ptr1= "<<&ptr1<<" = "<<ptr2<<endl;

    return 0;
}