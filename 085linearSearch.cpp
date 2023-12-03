#include <iostream>
using namespace std;

bool linearSearch(int *arr , int size , int key){
    // base case
    if (arr[0] == key){
        return true;
    }
    if (size <= 0){
        return false;
    }
    else{
        bool isPresent = linearSearch(arr + 1 , size - 1 ,key);
        return isPresent;
    }

}

int main(){
    int arr[10] = {1,2,3,4,5,15,6,8,7,9};
    cout << "Is 17 present: " << linearSearch(arr ,10 , 17) << endl;
    cout << "Is 15 present: " << linearSearch(arr ,10 , 15) << endl;
    return 0;
}