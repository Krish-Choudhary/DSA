#include<iostream>
using namespace std;

int main(){
    float F;
    cout<<"Input Temperature in Fahrenheit: ";
    cin>>F;
    
    float C;
    C=((F-32)*5)/9;

    cout<<"Temperature in Fahrenheit: "<<F<<endl<<"Temperature in Celsius: "<<C;

    return 0;
}