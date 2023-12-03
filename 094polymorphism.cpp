#include <iostream>
using namespace std;

class B{
    public:
    int a,b;

    void operator + (B obj){
        // doing subtraction
        cout << "output: " << this -> a - obj.a << endl;
    }
};
int main(){
    B obj1;
    B obj2;
    obj1.a = 5;
    obj2.a = 3;
    obj1 + obj2;
    return 0;
}