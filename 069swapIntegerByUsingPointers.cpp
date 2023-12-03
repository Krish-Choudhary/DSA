#include <iostream>
using namespace std;
void swap(int x, int y){
    //swapping x and y
    int temp=x;
    x=y;
    y=temp;
}

void swapByPointer(int *ptrx, int *ptry){
    //swapping x and y
    int temp=*ptrx;
    *ptrx=*ptry;
    *ptry=temp;
}

int main(){
    int x=5, y=10;
    //pass by value
    swap(x,y);
    cout<<x<<" "<<y<<endl;
    //x and y didn't swap as in  the swap function it is a copy of x not x and y itself
    //this problem can be solved using pointers
    //as by using pointers we will pass the address of x and y

    cout<<"By using pointers"<<endl;
    int *ptrx=&x, *ptry=&y;
    //Pass by reference
    swapByPointer(ptrx,ptry);
    cout<<x<<" "<<y<<endl;

    return 0;
}