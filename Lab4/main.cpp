#include "Automata.cpp"
void menu(Automata automata){
    bool t=true;
    while(t){
        cout<<"1-Show states\n";
        cout<<"2-Show alphabet\n";
        cout<<"3-Show the transitions\n";
        cout<<"4-Show initial state\n";
        cout<<"5-Show final\n";
        int n;
        cin>>n;
        switch (n)
        {
        case 1: 
            cout<<"The States: \n";
            for(int i=0;i<automata.states.size();i++)
                cout<<automata.states[i]<<" ";
            cout<<"\n\n";
            break;
        case 2: 
            cout<<"The alphabet: \n";
            for(int i=0;i<automata.alphabet.size();i++)
                cout<<automata.alphabet[i]<<" ";
            cout<<"\n\n";
            break;
        case 3: 
            for(int i=0;i<automata.transitions.size();i++){
                cout<<"Transition "<<i+1<<": \n";
                cout<<automata.transitions[i].initialState<<" "<<automata.transitions[i].literal<<" "<<automata.transitions[i].next<<"\n\n";
            }
            break;
        case 4: 
            cout<<"The initial state: "<<automata.initialState<<"\n";
            cout<<"\n";
            break;
        case 5: 
            cout<<"The final state: "<<automata.finalStates[0]<<"\n";
            cout<<"\n";
            break;
        
        default:
            t=false;
            break;
        }

    }
}

int main(){
    Automata a;
    a.readFiniteAutomata();
    menu(a);
}