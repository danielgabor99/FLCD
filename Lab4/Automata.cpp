using namespace std;
#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include "Transition.cpp"
class Automata{

    public: 
        vector<string> states;
        vector<string> alphabet;
        string initialState;
        vector<string> finalStates;
        vector<Transition> transitions;


    void readFiniteAutomata(){
        ifstream f("text.txt");
        string statesLine;
        getline(f,statesLine);
        size_t pos = 0;
        string delimiter=",";
        std::string token;
        while ((pos = statesLine.find(delimiter)) != std::string::npos) {
            token = statesLine.substr(0, pos);
            states.push_back(token);
            statesLine.erase(0, pos + delimiter.length());
        }
        states.push_back(statesLine);
        
        pos=0;
        string alphabetLine;
        getline(f,alphabetLine);
        while ((pos = alphabetLine.find(delimiter)) != std::string::npos) {
            token = alphabetLine.substr(0, pos);
            alphabet.push_back(token);
            alphabetLine.erase(0, pos + delimiter.length());
        }
        alphabet.push_back(alphabetLine);
        getline(f,initialState);
        string finalStat;
        getline(f,finalStat);
        pos=0;
        while ((pos = finalStat.find(delimiter)) != std::string::npos) {
            token = finalStat.substr(0, pos);
            finalStates.push_back(token);
            finalStat.erase(0, pos + delimiter.length());
        }
        finalStates.push_back(finalStat);

        string transition;
        while(getline(f,transition)){
            vector<string> tran;
            pos=0;
            while ((pos = transition.find(delimiter)) != std::string::npos) {
                token = transition.substr(0, pos);
                tran.push_back(token);
                transition.erase(0, pos + delimiter.length());
            }
            tran.push_back(transition);
           
            Transition t(tran[0],tran[1],tran[2]);
            transitions.push_back(t);
        }
    }
    bool isDeterministic(){
        for(int i=0;i<transitions.size();i++)
            for(int j=i+1;j<transitions.size();j++)
                if(transitions[i].initialState==transitions[j].initialState && transitions[i].literal==transitions[j].literal)
                    return false;
        return true;
    }

    void checkSequence(string sequence){
        string sq="";
        sq+=sequence[0];
        string nextState;
        for(Transition tr:this->transitions)
                if(tr.initialState==this->initialState&&sq==tr.literal)
                {
                    nextState=tr.next;
                    break;
                }
        for(int i=1;i<sequence.size();i++)
        {   
            sq="";
            sq+=sequence[i];
            for (Transition tr:this->transitions)
                if(tr.initialState==nextState&&sq==tr.literal)
                {
                    nextState=tr.next;
                    break;
                }
            
        }
        for(string s :this->finalStates)
            if(s==nextState)
                {
                    cout<<"Good sequence\n";
                    return;
                }
        cout<<"Bad sequence\n";
    }

};