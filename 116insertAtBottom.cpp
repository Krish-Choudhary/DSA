#include <bits/stdc++.h> 
using namespace std;

// https://www.codingninjas.com/studio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?leftPanelTabValue=PROBLEM

void solve(stack<int>& myStack, int x){
    if(myStack.empty()){
        myStack.push(x);
        return;
    }
    int num = myStack.top();
    myStack.pop();
    solve(myStack, x);
    myStack.push(num);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack, x);
    return myStack;
}
