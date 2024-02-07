#include <bits/stdc++.h>
using namespace std;


int main(){
    queue<int> q;
    cout << "Is queue empty: " << q.empty() << endl;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "Is queue empty: " << q.empty() << endl << endl;
    cout << "queue front: " << q.front() << endl;
    cout << "queue back: " << q.back() << endl;
    q.pop();
    cout << endl << "After popping" << endl;
    cout << "queue front: " << q.front() << endl;
    cout << "queue back: " << q.back() << endl;
    return 0;
}