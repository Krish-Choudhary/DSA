#include <iostream>
using namespace std;
int main(){
    int arr[2][2];
    //taking input row wise
    cout<<"taking input row wise"<<endl;
    for(int i=0;i<2;i++){
        //for loop for rows
        for(int j=0;j<2;j++){
            //loop for columns
            cin>>arr[i][j];
        }
    }
    //prinnting the array
    for(int i=0;i<2;i++){
        //for loop for rows
        for(int j=0;j<2;j++){
            //loop for columns
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int arr1[3][4];
    //taking input column wise
    cout<<"taking input column wise"<<endl;
    for(int j=0;j<4;j++){
        //for loop for columns
        for(int i=0;i<3;i++){
            //loop for rows
            cin>>arr[i][j];
        }
    }
    //prinnting the array
    for(int i=0;i<3;i++){
        //for loop for rows
        for(int j=0;j<4;j++){
            //loop for columns
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}