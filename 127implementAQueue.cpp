// https://www.codingninjas.com/studio/problems/queue-using-array-or-singly-linked-list_2099908?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
using namespace std;
class Queue {
private:
    int* arr;
    int qfront;
    int rear;
    int size;
public:
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront == rear)   return true;

        return false;
    }

    void enqueue(int data) {
        if (rear == size){
        // Queue is full
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if(qfront == rear)   return -1;

        int ans = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        if(qfront == rear){
            qfront = 0;
            rear = 0;
        }
        return ans;
    }

    int front() {
        if(qfront == rear)   return -1;

        return arr[qfront];
    }
};