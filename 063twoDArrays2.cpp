#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPresent(int arr[][4],int target, int row, int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]==target){
                return 1;
            }
        }
    }
    return 0;
}

void rowWiseSum(int arr[][4],int row,int col){
    for(int i=0;i<row;i++){
        int sum=0;
        for(int j=0;j<col;j++){
            sum+=arr[i][j];
        }
        cout<<sum<<endl;
    }
}

void colWiseSum(int arr[][4],int row,int col){
    for(int j=0;j<col;j++){
        int sum=0;
        for(int i=0;i<row;i++){
            sum+=arr[i][j];
        }
        cout<<sum<<endl;
    }
}

int largestRowSum(int arr[][4],int row,int col){
    int maxi= INT_MIN;
    int rowindex=-1;
    for(int i=0;i<row;i++){
        int sum=0 ;
        for(int j=0;j<col;j++){
            sum+=arr[i][j];
        }
        if(sum>maxi){
            maxi=sum;
            rowindex=i;
        }
    }
    cout<<"Maximum row sum: "<<maxi<<endl;
    return rowindex;
}

int main(){
    int arr[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    int arr1[3][4]={{1,11,111,1111},{2,22,222,2222},{3,33,333,3333}};
    for(int i=0;i<3;i++){
        //for loop for rows
        for(int j=0;j<4;j++){
            //loop for columns
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<3;i++){
        //for loop for rows
        for(int j=0;j<4;j++){
            //loop for columns
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }

    if(isPresent(arr,13,3,4)){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
    cout<<"row wise sum"<<endl;
    rowWiseSum(arr,3,4);
    cout<<"col wise sum"<<endl;
    colWiseSum(arr,3,4);
    cout<<largestRowSum(arr,3,4)+1<<endl;
}