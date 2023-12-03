#include <iostream>
using namespace std;
int main(){
    // creating member arrays
    int arr1[3]={9,6,5};
    int arr2[2]={0,1};
    int arr3[5]={1,5,8,7,6};
    int arr4[1]={3};

    // creating an array containg number of elements in each member array
    int size[4]={3,2,5,1};

    // creating jagged array
    int *jagged[]={arr1, arr2, arr3, arr4};

    // printing the array
    cout<<"printing the array:"<<endl;
    for(int i=0;i<4;i++){
        int* ptr = jagged[i];
        for(int j=0;j<size[i];j++){
            cout<<*(ptr+j)<<" ";
        }
        cout<<endl;
    }
    return 0;
}