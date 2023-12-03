#include <iostream>
using namespace std;
// This code was taught by Love Babbar
bool binarySearch(int arr[], int start, int end, int key) {
    if (start > end) {
        return false;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == key) {
        return true;
    } else if (arr[mid] > key) {
        return binarySearch(arr, start, mid - 1, key);
    } else {
        return binarySearch(arr, mid + 1, end, key);
    }
}

int binarySearchIndex(int arr[], int start, int end, int key) {
    if (start > end) {
        return -1;
        // not present
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == key) {
        return mid;
    } else if (arr[mid] > key) {
        return binarySearchIndex(arr, start, mid - 1, key);
    } else {
        return binarySearchIndex(arr, mid + 1, end, key);
    }
}

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << "Is 7 present: " << binarySearchIndex(arr ,0,9 , 7) << endl;
    cout << "Is 17 present: " << binarySearchIndex(arr ,0,9 , 17) << endl;
    return 0;
}