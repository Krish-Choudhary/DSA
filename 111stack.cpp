#include <bits/stdc++.h>
using namespace std;

class Stack1{
    public:
    int *arr;
    int topIndex;
    int size;

    Stack1(int size){
        this -> size = size;
        arr = new int[size];
        topIndex = -1;
    }

    void push(int element){
        if(size - topIndex > 1){
            // space available
            // topIndex++;
            // arr[topIndex] = element;
            arr[++topIndex] = element;
        }
        else    cout << "Stack overflow" << endl;
    }

    void pop(){
        if(topIndex >= 0)   topIndex--;
        else    cout << "Stack underflow" << endl;
    }

    int peek(){
        if(topIndex >= 0)   return arr[topIndex];
        else{
            cout << "Stack is empty" << endl;
            return -1;
        }

    }

    bool isEmpty(){
        if(topIndex == -1)  return true;
        else    return false;
    }
};

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

class Stack2{
    public:
    Node* top;

    Stack2(){
        top = NULL;
    }

    void push(int val){
        Node* temp = new Node(val);
        if(top == NULL){
            top = temp;
            return;
        }
        temp -> next = top;
        top = temp;
    }

    void pop(){
        if(top != NULL){
            Node* temp = top;
            top = top -> next;
            free(temp);
        }
        else    cout << "Stack underflow" << endl;
    }

    int peek(){
        if(top != NULL) return top -> data;
        else{
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty(){
        return top == NULL;
    }
};



void insertAtHead(Node* &head, int val){
    Node* temp = new Node(val);
    if(head == NULL){
        head = temp;
        return;
    }
    temp -> next = head;
    head = temp;

}

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
    
    cout << endl << endl << endl;

    Stack1 s1(5);
    s1.push(22);
    s1.push(43);
    s1.push(44);
    cout << "Stack top: " << s1.peek() << endl;
    s1.pop();
    cout << "Stack top: " << s1.peek() << endl;
    cout << "Is stack empty: " << s1.isEmpty() << endl;
    s1.pop();
    s1.pop();
    cout << "Is stack empty: " << s1.isEmpty() << endl;

    cout << endl << endl << endl;

    Stack2 s2;
    s2.push(1);
    s2.push(2);
    s2.push(3);
    s2.push(4);
    cout << "Stack top: " << s2.peek() << endl;
    s2.pop();
    cout << "Stack top: " << s2.peek() << endl;
    s2.pop();
    cout << "Is stack empty: " << s2.isEmpty() << endl;
    s2.pop();
    s2.pop();
    s2.pop();
    cout << "Is stack empty: " << s2.isEmpty() << endl;

    return 0;
}