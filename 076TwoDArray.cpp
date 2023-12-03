#include <iostream>
using namespace std;
int main(){

    int row;
    cout<<"input number of rows: ";
    cin>>row;
    int column;
    cout<<"input number of columns: ";
    cin>>column;

    int **arr = new int*[row];
    for(int i=0;i<row;i++){
        arr[i]= new int[column];
    }

    // 2d array created

    // taking input in 2d array
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cout<<"input ("<<i<<","<<j<<") index element of array: ";
            cin>>arr[i][j];
        }
    }

    // printing the array
    cout<<"printing the array"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    // releasing memory
    for(int i=0; i<row;i++){
        delete []arr[i];
    }
    delete []arr;

    return 0;
}