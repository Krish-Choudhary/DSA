#include <iostream>
#include <list>
using namespace std;

int main(){
    
    list<int> l;
    
    l.push_back(1);
    l.push_front(2);
    
    for(int i:l){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Size before erase: "<<l.size()<<endl;

    l.erase(l.begin());     //erase 1st element
    cout<<"after erase"<<endl;
    cout<<"Size after erase: "<<l.size()<<endl;
    for(int i:l){
        cout<<i<<" ";
    }
    cout<<endl;
    
    cout<<"New list"<<endl;
    list<int> n(5,100);     //[100,100,100,100,100]
    for(int i:n){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"New list"<<endl;
    list<int> x(n);     //copy of n
    for(int i:x){
        cout<<i<<" ";
    }
    cout<<endl;
    n.pop_front();
}