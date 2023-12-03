#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<string> q;
    q.push("First");
    q.push("Second");
    q.push("Third");

    cout<<q.front()<<" "<<q.back()<<endl;
    q.pop();    //First in First out
    cout<<"after pop"<<endl;
    cout<<q.front()<<" "<<q.back()<<endl;
    cout<<q.size()<<endl;
    cout<<"Is q empty: "<<q.empty();
}