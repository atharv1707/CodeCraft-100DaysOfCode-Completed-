#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	
	while(t--){
	    
	    int n, m;
	    cin>>n>>m;
	    string s, k;
	    cin>>s>>k;
	    //this loop is for jumping across the main string basically, about step length of key string
	    
	    int ans = 9*m; //worst case 
	    for(int i = 0 ; i<= n-m; i++){
	        int moves = 0;
	        for(int j = i; j<i+m;j++){
	            int a = s[j] - '0';
	            int b = k[j-i] - '0';
	            moves += min(abs(b-a), 10- abs(a-b));
	        }
	        ans = min(moves, ans);
	        
	        
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
