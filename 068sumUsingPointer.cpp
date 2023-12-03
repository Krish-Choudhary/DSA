#include <iostream>
using namespace std;
int main(){
    
    int x,y;
    cout<<"input x: ";
    cin>>x;
    cout<<"input y: ";
    cin>>y;

    int *ptrx=&x;
    int *ptry=&y;

    int sum;
    int *ptrSum=&sum;
    *ptrSum = *ptrx + *ptry;
    cout<<"sum of x and y: "<<*ptrSum<<" = "<<sum;
    return 0;
}