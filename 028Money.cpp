#include <iostream>
using namespace std;
int main(){
    
    int amount;
    cout<<"Input amount: ";
    cin>>amount;
    
    int x;

    switch(1){
        case 1: cout<<"Number of 2000 Ruppees notes: "<<amount/2000<<endl;
        x=amount/2000;
        amount=amount-(2000*x);

        case 2: cout<<"Number of 500 Ruppees notes: "<<amount/500<<endl;
        x=amount/500;
        amount=amount-(x*500);
        
        case 3: cout<<"Number of 200 Ruppees notes: "<<amount/200<<endl;
        x=amount/200;
        amount=amount-(x*200);
        
        case 4: cout<<"Number of 100 Ruppees notes: "<<amount/100<<endl;
        x=amount/100;
        amount=amount-(x*100);
        
        case 5: cout<<"Number of 50 Ruppees notes: "<<amount/50<<endl;
        x=amount/50;
        amount=amount-(x*50);
        
        case 6: cout<<"Number of 20 Ruppees notes: "<<amount/20<<endl;
        x=amount/20;
        amount=amount-(x*20);
        
        case 7: cout<<"Number of 10 Ruppees notes: "<<amount/10<<endl;
        x=amount/10;
        amount=amount-(x*10);
        
        case 8: cout<<"Number of 5 Ruppees coins: "<<amount/5<<endl;
        x=amount/5;
        amount=amount-(x*5);
        
        case 9: cout<<"Number of 2 Ruppees notes: "<<amount/2<<endl;
        x=amount/2;
        amount=amount-(x*2);
        
        case 10: cout<<"Number of 1 Ruppees notes: "<<amount<<endl;
    }
    return 0;
}