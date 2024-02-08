// https://www.codingninjas.com/studio/problems/circular-queue_1170058

#include <bits/stdc++.h> 
using namespace std;
class CircularQueue{

    public:

    int *arr;

    int front;

    int rear;

    int size;

    // Initialize your data structure.

    CircularQueue(int n){

        size=n;

        arr=new int[size];

        front=rear=-1;

    }

 // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.

    bool enqueue(int value){

        

        //if the queue is full

        if( (front==0 && rear==size-1) || (rear==(front-1)) ){

            return false;

        }

        else{

            //for the first element

            if(front ==-1){

                front=0;

                rear=0;

            }

            else if(rear==size-1 && front!=0){

                rear=0;  //for maintaing the cylic nature of the queue

            }

            else{          

                rear++;

            }

            arr[rear]=value;

            return true;

        }

    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.

    int dequeue(){

        //if the queue is empty

        if(front==-1){

            return -1;

        }

        else{

            int ans=arr[front];

            arr[front]=-1;

            //if single element is present

            if(front==rear){

                front=-1;

            }

            else if(front==size-1){

                front=0;

            }

            else{

                front++;

            }

            return ans;

        }

 

    }

};