#include <map>
#include <iostream>
using namespace std;

int main(){
    map<int,string> m;

    m[1]="one";
    m[5]="two";
    m[13]="three";
    m.insert({2,"four"});

    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<"Is 13 present: "<<m.count(13)<<endl;
    m.erase(13);
    cout<<"after erase"<<endl;
    cout<<"Is 13 present: "<<m.count(13)<<endl;
}