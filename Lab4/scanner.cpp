#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <regex>
#include "st.cpp"
using namespace std;

void createPIF(string token, string pif){
    

}


int main(){
    ST st(10);
    string line,tokenline,pifline;
    ifstream myfile,token;
    fstream pif;
    vector<string> tokenArray;
    myfile.open("perr.txt");
    token.open("token.txt");
    pif.open("pif.txt", ios::in | ios::out | ios::app);
    int ok;
    //creating a vector with all the tokens
    while(getline(token,tokenline)){
        tokenArray.push_back(tokenline.substr(0,tokenline.find(" ")));
    }
    int count=0;
    while(getline(myfile,line)){
        count++;
        //for the tokens
        regex reg1("((->)|;|(\\()|(\\))|(\\[)|(\\]))|([a-zA-Z0-9]+)");
        regex regloop("(loop.*;.*;.*(go))");
        regex regif(".*(if.*(go))");
        regex regpara(".*(\\().*\\)");
        regex regpara2(".*(\\[).*\\]");
        regex regnum("[0-9]+");
        
        for( sregex_iterator it(line.begin(), line.end(), reg1), it_end; it != it_end; ++it )
        {
            if(find(tokenArray.begin(),tokenArray.end(),(*it)[0])!=tokenArray.end())
            {
                if((*it)[0]=="loop")
                    if(regex_match(line,regloop)==0)
                        cout<<"loop error on line "<<count<<endl;
                if((*it)[0]=="if")
                    if(regex_match(line,regif)==0)
                        cout<<"if error on line "<<count<<endl;
                if((*it)[0]=="(")
                    if(regex_match(line,regpara)==0)
                        cout<<"( error on line "<<count<<endl;
                if((*it)[0]=="[")
                    if(regex_match(line,regpara)==0)
                        cout<<"[] error on line "<<count<<endl;

                pif.clear();
                pif.seekg(0);
                
                pif.close();
                pif.open("pif.txt", ios::in | ios::out | ios::app);
                    
                pif<<(*it)[0]<<string(10-(*it)[0].str().size(), ' ' )<<"0"<<"\n";
                
                
            }
            else{
                //insert identifiers
                if((*it)[0]!="")
                    st.insertValue((*it)[0]);
                pif.clear();
                pif.seekg(0);
                
                pif.close();
                pif.open("pif.txt", ios::in | ios::out | ios::app);
                if(((*it)[0])!="" && regex_match((*it)[0].str(),regnum)==1){
                    string x=((*it)[0]);
                    pif<<(*it)[0]<<string(10-(*it)[0].str().size(), ' ' )<<0<<"\n";
                }else{
                    pif<<(*it)[0]<<string(10-(*it)[0].str().size(), ' ' )<<st.hashFun((*it)[0])<<"\n";
                }
            }
        }
        // for( sregex_iterator it(line.begin(), line.end(), reg1), it_end; it != it_end; ++it ){
        //     cout<<(*it)[0];
        // }

    }
    st.showST();
    
}
