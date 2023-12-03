#include <iostream>
using namespace std;

int sumOfArray(int arr[] , int size){
    int sum = arr[0];
    // base case
    if(size <= 0)
        return 0;
    else{
        sum = sum + sumOfArray(arr + 1 , size - 1);
        return sum;
    }
}
int main(){
    int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << sumOfArray(arr1 , 10);

    return 0;
}