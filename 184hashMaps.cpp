#include <bits/stdc++.h>
using namespace std;

int main(){
    /*
    // creation
    unordered_map<string, int> m;

    // insertion
    // 1
    pair<string, int> p1 = make_pair("hello", 1);
    m.insert(p1);

    // 2
    pair<string, int> p2("hi", 2);
    m.insert(p2);

    // 3
    m["wooohooo"] = 3;

    // updation
    m["hi"] = 4;

    // search
    cout << m["mera"] << endl;      // It is not present but it will create a entry corresponding to 0
    // cout << m.at("kya");            // error as it is not present
    cout << "hi " << m.at("hi") << endl;

    // size
    cout << "Size of map: " << m.size() << endl;

    // to check presence
    cout << "Is \"name\" present: " << m.count("name") << endl;
    cout << "Is \"wooohooo\" present: " << m.count("wooohooo") << endl;

    // erase
    m.erase("hello");

    // size
    cout << "size of map: " << m.size() << endl;

    // printing
    cout << endl << "Printing map" << endl;
    for(auto i: m){
        cout << i.first << " " << i.second << endl;
    }

    // iterator
    cout << endl << "Printing with iterartor" << endl;
    unordered_map<string, int> :: iterator it = m.begin();
    while(it != m.end()){
        cout << it -> first << " " << it -> second << endl;
        it++;
    }
    */



    // Using map, the order is preserved 
    // but if we use unordered map the output is not preserved
    // creation
    map<string, int> m;

    // insertion
    // 1
    pair<string, int> p1 = make_pair("hello", 1);
    m.insert(p1);

    // 2
    pair<string, int> p2("hi", 2);
    m.insert(p2);

    // 3
    m["wooohooo"] = 3;

    // updation
    m["hi"] = 4;

    // search
    cout << m["mera"] << endl;      // It is not present but it will create a entry corresponding to 0
    // cout << m.at("kya");            // error as it is not present
    cout << "hi " << m.at("hi") << endl;

    // size
    cout << "Size of map: " << m.size() << endl;

    // to check presence
    cout << "Is \"name\" present: " << m.count("name") << endl;
    cout << "Is \"wooohooo\" present: " << m.count("wooohooo") << endl;

    // erase
    m.erase("hello");

    // size
    cout << "size of map: " << m.size() << endl;

    // printing
    cout << endl << "Printing map" << endl;
    for(auto i: m){
        cout << i.first << " " << i.second << endl;
    }

    // iterator
    cout << endl << "Printing with iterartor" << endl;
    map<string, int> :: iterator it = m.begin();
    while(it != m.end()){
        cout << it -> first << " " << it -> second << endl;
        it++;
    }
    return 0;
}