#include <iostream>
using namespace std;
 
//  Multi-line Macro.
#define ABA 1, \
            2, \
            3
 
int main() {
    // Array arr[] with elements defined in macro 'ABA'.
    int arr[] = { ABA };
 
    cout<<"Elements of Array are:\n";
 
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << ' ';
    }
 
    return 0;
}