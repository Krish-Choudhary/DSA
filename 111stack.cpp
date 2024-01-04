#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << "Size of stack: " << s.size() << endl;
    cout << "Top element: " << s.top() << endl;
    s.pop();
    cout << "Top element: " << s.top() << endl;
    s.pop();
    cout << "Is stack empty: " << s.empty() << endl;
    s.pop();
    cout << "Is stack empty: " << s.empty() << endl;
}