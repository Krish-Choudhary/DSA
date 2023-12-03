#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int> maxi;      //default case of Max
    priority_queue<int,vector<int>,greater<int>> mini;  //Minimum case

    cout<<"in case of maxi"<<endl;
    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);

    int size=maxi.size();
    for(int i=0;i<size;i++){
        cout<<maxi.top()<<" ";
        maxi.pop();
    }
    cout<<endl<<"In case of mini"<<endl;

    mini.push(1);
    mini.push(3);
    mini.push(2);
    mini.push(0);

    size=mini.size();
    for(int i=0;i<size;i++){
        cout<<mini.top()<<" ";
        mini.pop();
    }
    cout<<endl<<"Maxi is empty: "<<maxi.empty();
    }