#include <iostream>
using namespace std;
int main(){
    int arr[5]={1,2,3,4,5};
    char ch[6]="abcde";

    cout<<arr<<endl;
    //attention here as there is some difference in implementation of int array and char array
    cout<<ch<<endl;

    char *c=&ch[0];
    //printsentire string
    //it instruct  the cout function to start printing from c address and stop when you find a null character i.e. /0
    cout<<c<<endl;
    cout<<endl;

    char ch1='z';
    char *p=&ch1;
    cout<<p<<endl;

    return 0;
}