#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    cout<<"input str: ";
    getline(cin,str);
    cout<<str<<endl;
    string s1="fam",s2="ily";
    cout<<s1+s2<<endl;
    s1.append(s2);
    cout<<"new s1: "<<s1<<endl;
    s1.clear();
    cout<<"new s1 after clear: "<<s1<<endl;

    if(s1.compare(s2)==0){
        cout<<"s1 is equal to s2";
        cout<<endl;
    }
    
    if(s1.empty()){
        cout<<"s1 is empty";
        cout<<endl;
    }
    
    return 0;
}