#include <array>
#include <iostream>
using namespace std;

int main(){
    int basic[3]={1,2,3};
    array<int,4> a={1,2,3,4};

    int size=a.size();

    for(int i=0;i<size;i++){
        cout<<a.at(i)<<" ";
    }
cout<<endl;
cout<<"Element at 2nd index: "<<a.at(2)<<endl;
cout<<"Is array empty "<<a.empty()<<endl;
cout<<"First element "<<a.front()<<endl;
cout<<"Last Element "<<a.back()<<endl;
}