// C++ Program to implement Jagged array
// 2nd way: Dynamic 2D array
#include <iostream>
using namespace std;

int main()
{

	int row, col;
    cout<<"input number of rows: ";
    cin>>row;

	// Create Row Array- dynamic array of pointers
	int** arr = new int*[row];
    int *sizes= new int[row];

	// no of columns for each row as input from user
	for (int i = 0; i < row; i++) {
		cout<<"input number of columns for "<<i+1<<"th row: ";
		cin>>col;	 //if col is taken as input
		sizes[i]=col;
		// store each col number in size 
		
		*(arr + i) = new int[sizes[i]];
        // *(arr+i)= arr[i]
	}

	// input from user
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < sizes[i]; j++) {
            cout<<"input arr["<<i<<"]["<<j<<"]: ";
			cin>>arr[i][j];
		}
	}

	cout << "printing the array:" << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < sizes[i]; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
