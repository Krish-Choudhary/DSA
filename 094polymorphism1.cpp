#include <iostream>
using namespace std;
// method overriding
class parent{
    public:
    void speak(){
        cout << "inside parent" << endl;
    }
};
class child: public parent{
    public:
    void speak(){
        cout << "inside child" << endl;
    }
};

int main(){
    child baby;
    baby.speak();
    return 0;
}