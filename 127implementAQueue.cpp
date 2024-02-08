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

/*
    Time complexity: O(q)
    Space complexity: O(q)

    Where q is the number of queries.
*/

class Node {
public :
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class QueueViaLinkedList {
public:

    Node *head;
    Node *tail;
    int size;

    QueueViaLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    ~QueueViaLinkedList() {
        Node *temp = head;
        while (temp)
        {
            Node *t = temp;
            temp = temp->next;
            delete t;
        }
    }

    // Function to check if the queue is empty.
    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int data) {

        // Increase the count of elements present in the List.
        size++;

        // Create a new node.
        Node *newNode = new Node(data);

        // Check if the Queue is empty.
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }

        // Push the element to the last of the queue.
        tail->next = newNode;
        tail = newNode;
        return;
    }

    int dequeue() {

        // Check if the queue is empty.
        if (isEmpty()) {
            return -1;
        }

        int ans = head->data;


        Node *tmp = head;
        head = head->next;

        // If the queue is empty make the tail pointer NULL.
        if (head == NULL) {
            tail = NULL;
        }
        delete tmp;

        size--;

        return ans;
    }

    int front() {

        // Check if the queue is empty.
        if (isEmpty())  {
            return -1;
        }

        // Return the element at the front.
        return head->data;
    }
};