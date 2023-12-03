#include<iostream>
#include "Empty.cpp"
using namespace std;
class Hero{
    private:
    int xp;
    public:
    static int timetocomplete;
    int health;
    int level;
    int getxp(){
        return xp;
    }
    void setxp(int xp){
        this -> xp = xp;
    }
    static int random(){
        // return health;       error as it is a non-static keyword
        return timetocomplete;
    }
    // simple constructor
    Hero(){
        cout << "Simple constructor called" << endl;
    }
    // parameterized constructor
    Hero(int health , int level , int xp){
        cout << "parameterized constructor called" << endl;
        this -> health = health;
        this -> level = level;
        this -> xp = xp;
    }
    // copy constructor
    Hero(Hero& temp){
        cout << "copy constructor called" << endl;
        this -> health = temp.health;
        this -> level = temp.level;
        this -> xp = temp.xp;
    }
};
class padding{
    public:
    padding(){
        cout << "constructor called by default" << endl;
    }
    int health,xp;    // 4 + 4
    char c;             // 1 + 7 padding
    double db;          // 8
    // set of 8
};
int Hero::timetocomplete = 60;

int main(){
    cout << endl << Hero::timetocomplete << endl << endl;
    cout << Hero::random() << endl;
    Hero h1;                    // stack memory
    Hero *h2 = new Hero();      // Dynamic memory
    Empty e1;
    cout << sizeof(h1) << " " << sizeof(h2) << endl << sizeof(e1) << endl;
    h1.level = 10;
    h1.health = 100;
    (*h2).level = 8;
    (*h2).health = 80;
    cout << "health of h1 is: " << h1.health << endl << "health of h2 is: " << (*h2).health << " = " << h2 -> health << " = " << h2->health << endl;
    h1.setxp(100);
    int h1xp = h1.getxp();
    cout << "XP of h1 = " << h1xp << endl;
    padding c;
    // constructor called at time of initialisation
    cout << "size of padding:" << sizeof(c) << endl;
    Hero h3(h1);    // h3 is a copy of h1
    return 0;
}