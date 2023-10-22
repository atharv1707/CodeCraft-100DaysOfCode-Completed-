#include <iostream>
#include <set>

using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin >> t;
    cin.ignore();
	while(t--){
	    
	    string s;
	    getline(cin, s);
	    
	    set<char> vowels;

    // Insert vowels into the set
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');
        
        bool status = false;
        
        for(int i = 0 ; i < s.size()-2;i++){
            if(vowels.find(s[i])!= vowels.end() && vowels.find(s[i+1])!= vowels.end() && vowels.find(s[i+2])!= vowels.end()){
                status = true;
                break;
                
            }
        }
        
        if(status){
            printf("Happy\n");
        }
        else{
            printf("Sad\n");
        }
	}
	return 0;
}
