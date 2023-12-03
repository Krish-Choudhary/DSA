#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"input n: ";
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cout<<"input "<<i+1<<"th element: ";
        cin>>*(arr+i);      // we can also put *(arr+i)=arr[i] because we know that they are equal
    }
    cout<<"printing array: ";
    for(int i=0;i<n;i++){
        cout<<*(arr+i)<<" ";
    }
    return 0;
}