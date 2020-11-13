using namespace std;
#include<vector>
#include<string>
#include<iostream>
#include<fstream>
class Transition{
    public:
        string initialState;
        string literal;
        string next;
    Transition(string i, string l,string n){
        initialState=i;
        literal=l;
        next=n;
    }
};