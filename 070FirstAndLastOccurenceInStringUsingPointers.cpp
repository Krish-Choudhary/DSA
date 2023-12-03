#include <iostream>
#include <string>
using namespace std;

void firstAndLastOccurenceIndex(string s, char ch, int *first, int *last){
    //first occurence
    for(int i=0;i<s.size();i++){
        if(s[i]==ch){
            *first=i;
            break;
        }
    }

    //last occurence
    for(int i=s.size() - 1; i >= 0; i--){
        if(s[i]==ch){
            *last=i;
            break;
        }
    }
}

int main(){
    string s="aaabac";
    //initialising first and last index
    int first=-1, last=-1;
    int *ptrFirst=&first, *ptrLast=&last;

    firstAndLastOccurenceIndex(s,'a',ptrFirst,ptrLast);

    cout<<first<<" "<<last<<endl;
    cout<<*ptrFirst<<" "<<*ptrLast<<endl;
    
    return 0;
}