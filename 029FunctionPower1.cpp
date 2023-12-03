//This code is the updated version of the previous code
#include <iostream>
using namespace std;
int power(){
    int a,b;
    cout<<"input a: ";
    cin>>a;
    cout<<"input b: ";
    cin>>b;
    int ans=1;
    for(int i=1;i<=b;i++){
        ans=ans*a;
    }
        return ans;
}

int main(){

    int answer;

    answer=power();
    cout<<answer<<endl;

    answer=power();
    cout<<answer<<endl;

    answer=power();
    cout<<answer<<endl;

    answer=power();
    cout<<answer<<endl;

    answer=power();
    cout<<answer<<endl;

    answer=power();
    cout<<answer<<endl;
    return 0;
}