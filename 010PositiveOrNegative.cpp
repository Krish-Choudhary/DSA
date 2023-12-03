#include<iostream>
using namespace std;

int main(){
    int a;

    cout<<"Input a: ";
    cin>>a;

    if (a>0){
        cout<<"a is positive"<<endl;
    }
    
    else{
        if(a<0){
        cout<<"a is negative"<<endl;
        }
        else{
            cout<<"a is zero";
        }
        //This code is looking messy as we are using else then inside else we are writing if. 
        //In the next program there is an upgraded version of this code with else if concept and with 2 numbers
    }

return 0;
}
