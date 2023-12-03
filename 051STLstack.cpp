#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<string> s;
    s.push("One");
    s.push("Two");
    s.push("Three");
    cout<<"Top element: "<<s.top()<<endl;
    s.pop();
    cout<<"Size of stack: "<<s.size()<<endl;
    cout<<"Is stack empty: "<<s.empty();
}