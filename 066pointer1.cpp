#include <iostream>
using namespace std;
int main(){
    int arr[10]={1,20,3,4,5,6,7,8,9,10};
    cout<<"Address of first memory block of array: "<<arr<<endl;
    cout<<"Address of first memory block of array: "<<&arr[0]<<endl;
    cout<<"value at 0th index of arr: "<<*arr<<endl;
    cout<<"value at 1st index of arr: "<<*(arr+1)<<endl;
    cout<<"value at 1st index of arr: "<<arr[1]<<endl;
    //*(arr+1)==arr[1]
    cout<<endl;

    int i=3;
    cout<<"i[arr]=arr[i]= "<<i[arr]<<endl;
    //i[arr]=arr[i]
    cout<<endl;

    int *ptr=&arr[0];
    cout<<"sizeof(ptr): "<<sizeof(ptr)<<endl;        //this is machine dependent in some machines it will show 8 bytes
    cout<<"sizeof(*ptr): "<<sizeof(*ptr)<<endl;
    cout<<"sizeof(arr): "<<sizeof(arr)<<endl;
    cout<<"ptr != &ptr : "<<ptr<<" "<<&ptr<<endl;
    return 0;
}