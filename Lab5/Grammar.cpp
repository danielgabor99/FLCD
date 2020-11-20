using namespace std;
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include<fstream>
class Grammar{

    
    public: 
        string grammar;
        vector<string> nonterminals;
        vector<string> terminals;
        vector<std::pair<string,string>> set; 
    Grammar(string grammar){
        this->grammar=grammar;
        readGrammar();
    }
    void readGrammar(){
        ifstream f(this->grammar);
        string statesLine;
        getline(f,statesLine);
        size_t pos = 0;
        string delimiter=" ";
        std::string token;
        while ((pos = statesLine.find(delimiter)) != std::string::npos) {
            token = statesLine.substr(0, pos);
            terminals.push_back(token);
            statesLine.erase(0, pos + delimiter.length());
        }
        terminals.push_back(statesLine);
        
        pos=0;
        string alphabetLine;
        getline(f,alphabetLine);
        while ((pos = alphabetLine.find(delimiter)) != std::string::npos) {
            token = alphabetLine.substr(0, pos);
            nonterminals.push_back(token);
            alphabetLine.erase(0, pos + delimiter.length());
        }
        nonterminals.push_back(alphabetLine);
        string line;
        string first;
        string second;
        while(getline(f,line)){
            first=line[0];
            second=line.substr(line.find(">") + 1); 
            std::pair<string,string> p;
            p.first=first;
            p.second=second;
            set.push_back(p);
        }
    
    }
    void getProductions(string s){
        cout<<endl<<s<<"->";
        for(auto i:this->set){
            if(i.first==s){
                cout<<i.second;
            }
        }
    }
};
int main(){
    Grammar g=Grammar("g1.txt");
    cout<<"terminals:   ";
    for(auto i:g.terminals){
        cout<<i<<"   ";
    }
    cout<<endl<<endl<<"nonterminals:   ";
    for(auto i:g.nonterminals){
        cout<<i<<"   ";
    }
    cout<<endl<<endl<<"productions:   ";
    for(auto i:g.set){
        cout<<endl;
        cout<<i.first<<"->"<<i.second;
    }
    g.getProductions("S");
    return 0;
}