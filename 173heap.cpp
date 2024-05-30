#include <bits/stdc++.h>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        int index = ++size;
        arr[index] = val;
        while(index > 1){
            int parent = index / 2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else    return;
        }
    }

    void print(){
        for(int i = 1; i <= size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deletion(){
        if(size == 0){
            cout << "Nothing to delete" << endl;
            return;
        }
        arr[1] = arr[size];
        size--;

        // Take root node to its correct position
        int i = 1;
        while(i < size){
            int leftChildIndex = 2*i;
            int rightChildIndex = 2*i + 1;
            if(leftChildIndex <= size && arr[i] < arr[leftChildIndex]){
                swap(arr[leftChildIndex], arr[i]);
                i = leftChildIndex;
            }
            else if(rightChildIndex <= size && arr[i] < arr[rightChildIndex]){
                swap(arr[rightChildIndex], arr[i]);
                i = rightChildIndex;
            }
            else    return;
        }
    }
};

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[left] > arr[largest])   largest = left;
    if(right <= n && arr[right] > arr[largest]) largest = right;
    
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    int size = n;
    while(size > 1){
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
}

int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletion();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    // Heap create
    for(int i = n/2; i > 0; i--){
        heapify(arr, n, i);
    }
    cout << "printing the array: " << endl;
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    // heapsort
    heapSort(arr, n);
    cout << "printing the sorted array: " << endl;
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}