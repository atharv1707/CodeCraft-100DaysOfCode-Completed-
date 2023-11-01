//or just use -> N(N-1)

#include <iostream>
using namespace std;

int factorial(int n){
    if(n ==0 || n==1){
        return 1;
    }
    return n * factorial(n-1);
}


int main() {
	// your code goes here
	int t;
	scanf("%d", &t);
	
	while(t--){
	    int N;
	     cin>>N;
	    
	    int ANS = factorial(N)/(factorial(N-2)*2);
	     ANS = ANS*2;
	    cout <<ANS << endl;
	    
	    
	    
	    
	    
	}

	return 0;
}
