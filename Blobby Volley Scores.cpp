#include <iostream>
using namespace std;
//the trick is to keep the track of who is the server, and only server can actually earn a point.
int main() {
	// your code goes here
	
	int t;
	scanf("%d", &t);
	while(t--){
	    int n;
    cin >> n;
    string s;
    cin >> s;

    int aliceScore = 0;
    int bobScore = 0;
    
    char server = 'A';
    
    for(int i = 0 ; i < n ; i++){
        if(s[i] == 'A'){
            if(server == 'A'){
                aliceScore++;
            }
            
            server = 'A';
        }
        
        else if(s[i] == 'B'){
            if(server == 'B'){
                bobScore++;
            }
            
            server = 'B';
            
        }
        
        

        
        
    }
    cout << aliceScore << " " << bobScore << endl;
	}
	
	return 0;
}
