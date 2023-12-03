#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    cout<<"Capacity: "<<v.capacity()<<endl;

    v.push_back(1);
    cout<<"Capacity: "<<v.capacity()<<endl;

    v.push_back(2);
    cout<<"Capacity: "<<v.capacity()<<endl;

    v.push_back(3);
    cout<<"Capacity: "<<v.capacity()<<endl;
    cout<<"size: "<<v.size()<<endl;

    v.push_back(4);
    cout<<"Capacity: "<<v.capacity()<<endl;
    cout<<"size: "<<v.size()<<endl;

    cout<<"Element at 2nd index: "<<v.at(2)<<endl;
    cout<<"Element at first place: "<<v.front()<<endl;
    cout<<"Element at last index: "<<v.back()<<endl;

    //print v
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;

    vector<int> a(5,1);
    //vector with size 5 and all elements equal to 1
    //{1,1,1,1,1}
    //print a
    cout<<"Capacity of a: "<<a.capacity()<<endl;
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;

    //make a copy of vector a
    vector<int> copy(a);
    for(int i:copy){
        cout<<i<<" ";
    }

    return 0;
}