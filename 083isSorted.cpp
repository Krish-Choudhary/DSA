#include <iostream>
using namespace std;

bool isSorted(int arr[] , int size){
    // base case
    if(size == 0 || size == 1)
        return true;
    // recursive call
    if(arr[0] > arr[1])
        return false;
    else{
        bool ans = isSorted(arr + 1 , size - 1);
        return ans;
    }
}
int main(){
    int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[7] = {1,2,3,4,8,7,5};
    cout << "Is arr1 sorted: " << isSorted(arr1,10) << endl;
    cout << "Is arr2 sorted: " << isSorted(arr2,7);
    return 0;
}