#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<int> d;
    
    d.push_back(1);
    d.push_front(2);
    d.push_back(3);
    d.push_front(4);

    for(int i:d){
        cout<<i<<" ";       // 4 2 1 3
    }
    cout<<endl;

    d.pop_back();

    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;

    d.pop_front();

    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"First Element: "<<d.front()<<endl;
    cout<<"Last Element: "<<d.back()<<endl;
    cout<<"Element at index 1: "<<d.at(1)<<endl;
    cout<<"Is element empty: "<<d.empty()<<endl;
    cout<<"size before erase: "<<d.size()<<endl;
    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;
    d.erase(d.begin(),d.begin()+1);     //First element deleted
    cout<<"size after erase: "<<d.size()<<endl;
    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}