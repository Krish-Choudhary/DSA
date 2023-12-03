#include <iostream>
using namespace std;
#define Area(l,b) (l*b)
int main(){
    int l,b;
    cout<<"input length of rectangle: ";
    cin>>l;
    cout<<"input breadth of rectangle: ";
    cin>>b;
    cout<<"Area of rectangle is "<<Area(l,b);

    return 0;
}