#include <iostream>
using namespace std;
int power(int a, int b){
    int ans=1;
    for(int i=1;i<=b;i++){
        ans=ans*a;
    }
        return ans;
}

int main(){
    int a,b;
    cout<<"input a: ";
    cin>>a;
    cout<<"input b: ";
    cin>>b;

    int answer;
    answer=power(a,b);
    cout<<answer;
    return 0;
}