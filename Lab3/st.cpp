#include<bits/stdc++.h>
#include <fstream> 
using namespace std; 
class ST 
{ 
	int size; 
	list<string> *table; 
public: 
	ST(int size){ 
		this->size = size; 
		table = new list<string>[size]; 
	}  
	void insertValue(string value){
		if(alreadyexists(value)==false){
			int index = hashFun(value); 
			table[index].push_back(value); 
		}
	} 
	bool alreadyexists(string value){
		for(int i=0;i<size;i++){
			for (auto var : table[i]) 
				if(value==var)
					return true;
		}
		return false;
	}
	 
	int hashFun(string value) {
		int c=0;
		for(int i=0;i<value.size();i++){
			c+=int(value[i]);
		}
		return c%size; 
	} 

	void showST(){
		ofstream stFile;
		stFile.open("ST.txt");
		for (int i = 0; i < size; i++) { 
			stFile << i; 
			for (auto x : table[i]) 
			stFile << " --> " << x; 
			stFile << endl; 
		}
	}  
}; 


