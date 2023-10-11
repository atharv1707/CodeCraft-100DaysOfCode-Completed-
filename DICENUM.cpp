#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int t;
	scanf("%d", &t);
	while(t--){
	    int A1, A2, A3;
	    int B1, B2, B3;
	    
	     scanf("%d %d %d %d %d %d", &A1, &A2, &A3, &B1, &B2, &B3);
	    
	    int max_num_A = max({A1, A2, A3});
	    int sec_max_num_A = min({max(A1,A2), max(A2,A3), max(A1,A3)});
	    int min_num_A = min({A1, A2, A3});
	    
	    int max_num_B = max({B1, B2, B3});
	    int sec_max_num_B = min({max(B1,B2), max(B2,B3), max(B1,B3)});
	    int min_num_B = min({B1, B2, B3});
	    
	    
	    
	    max_num_A += min_num_A + 10*sec_max_num_A + 100*max_num_A;
	    max_num_B += min_num_B + 10*sec_max_num_B + 100*max_num_B;
	    
	    
	    if(max_num_A > max_num_B){
	        cout << "Alice"<< endl;
	    }
	    else if(max_num_A == max_num_B){
	        cout << "tie" << endl;
	    }
	    
	    else{
	        cout << "Bob" << endl;
	    }
	        
	    }
	    
	    
	   return 0;
	}
	

