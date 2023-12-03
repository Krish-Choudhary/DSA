#include <iostream>
using namespace std;
class earthian{
    int oxygenIntake;
};
class human{
    public:
    int height , weight , age;
};
class male: public human , protected earthian{
    public:
    int shopping;
};

int main(){
    male krish;
    cout << krish.height << endl << krish.shopping << endl;
    return 0;
}