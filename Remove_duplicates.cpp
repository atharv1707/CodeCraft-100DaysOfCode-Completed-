class Solution{
public:	
		
	string removeDups(string S) 
	{
	    // Your code goes here
	    unordered_map<char,bool> encountered;
	    string output ;
	    
	    for(char i : S){
	        if(encountered.find(i)== encountered.end()){
	            output += i;
	            //update that we have encountered this letter after it's first occurence;
	            encountered[i] =true;
	        }
	            
	        }
	        
	        return output;
	    }
	    
	
};