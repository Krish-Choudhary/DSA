#include<iostream>
using namespace std;
//Print sum of first n natural numbers with the help of for loop

int main(){
int n,sum=0;
cout<<"input n: ";
cin>>n;

for(int i=1;i<=n;i++){
    sum=sum+i;
}
cout<<sum;
return 0;
}
