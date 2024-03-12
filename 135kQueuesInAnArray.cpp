#include <bits/stdc++.h>
using namespace std;

class kQueue{
    private:
        int n;
        int k;
        int *front;
        int *rear;
        int *arr;
        int freespot;
        int *next;
    
    public:
        // constructor
        kQueue(int n, int k){
            this -> n = n;
            this -> k = k;
            front = new int[k];
            rear = new int[k];
            arr = new int[n];
            next = new int[n];
            freespot = 0;

            for(int i = 0; i < k; i++){
                front[i] = -1;
                rear[i] = -1;
            }

            for(int i = 0; i < n - 1; i++){
                next[i] = i + 1;
            }

            next[n - 1] = -1;
        }

        void enqueue(int data, int qn){
            // overflow
            if(freespot == -1){
                cout << "Queue overflow" << endl;
                return;
            }

            // find first free index
            int index = freespot;

            // update freespot
            freespot = next[index];

            // check whether first element
            if(front[qn - 1] == -1){
                front[qn - 1] = index;
            }
            else{
                // link new element to prev element
                next[rear[qn - 1]] = index;
            }

            // update next
            next[index] = -1;

            // update rear
            rear[qn - 1] = index;

            // push element
            arr[index] = data;

        }

        int dequeue(int qn){
            // underflow
            if(front[qn - 1] == -1){
                cout << "underflow\n";
                return -1; 
            }

            // find index to pop
            int index = front[qn - 1];

            // update front
            front[qn - 1] = next[index];

            // manage freespots
            next[index] = freespot;
            freespot = index;
            return arr[index];
        }

};

int main(){

    return 0;
}