#include <bits/stdc++.h> 
using namespace std;

// https://www.codingninjas.com/studio/problems/two-stacks_983634?leftPanelTabValue=PROBLEM

class TwoStack {

public:
    int* arr;
    int topIndex1;
    int topIndex2;
    int size;

    // Initialize TwoStack.
    TwoStack(int s) {
        this -> size = s;
        topIndex1 = -1;
        topIndex2 = s;
        arr = new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
        if(topIndex2 - topIndex1 > 1)   arr[++topIndex1] = num;
        // Mentioned in question
        // While performing Push operations, do nothing in the situation of the overflow of the stack.
        // else     cout << "Stack Overflow" << endl;
    }

    // Push in stack 2.
    void push2(int num) {
        if(topIndex2 - topIndex1 > 1)   arr[--topIndex2] = num;
        // Mentioned in question
        // While performing Push operations, do nothing in the situation of the overflow of the stack.
        // else     cout << "Stack Overflow" << endl;
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(topIndex1 >= 0)  return arr[topIndex1--];
        else    return -1;
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(topIndex2 < size)  return arr[topIndex2++];
        else    return -1;
    }
};
