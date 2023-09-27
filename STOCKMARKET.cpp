#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--){
	    
	    //storing value in std::vector<T> ;
	    int x;
	    cin >>x;
	    
	    vector<int> storage(x);
	    for(int i = 0 ; i<x;i++){
	        cin >> storage[i];
	    }
	    
	    sort(storage.begin(), storage.end());
	    
	    
	    int sum = 0 ; 
	    for(int i = 1;i< x; i++){
	        sum += storage[i];
	    }
	    
	    cout<<sum<< endl;
	    
	    
	    
	}
	
	return 0;
}
