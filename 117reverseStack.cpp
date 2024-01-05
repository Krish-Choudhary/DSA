#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/reverse-stack-using-recursion_631875?leftPanelTabValue=PROBLEM

void insertAtBottom(stack<int> &myStack, int x){
    if(myStack.empty()){
        myStack.push(x);
        return;
    }
    int num = myStack.top();
    myStack.pop();
    insertAtBottom(myStack, x);
    myStack.push(num);
}

void reverseStack(stack<int> &stack) {
    // base case
    if(stack.empty())   return;

    int num = stack.top();
    stack.pop();

    reverseStack(stack);
    insertAtBottom(stack,num);
}