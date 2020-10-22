int hashFun(string x) {
		int c=0;
		for(int i=0;i<x.size();i++){
			c+=int(x[i]);
		}
		return c%size; 
	} 