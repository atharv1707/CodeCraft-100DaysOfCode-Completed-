
#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#define ll long long

using namespace std;
//initialising the modulus function

//one of the main constraint is to maintain whatever result we get under 1e9+7
const int M = 1e9+7;

//the mod function takes an integer x, and divides it by modulus. It ensures that number is non-negative, if initially the x was negative number.
//After adding the M , it takes modulus again to ensure that it stays betweent [0, M-1].

ll mod(ll x){
    return (x%M + M )%M;
}

//then when we are multiplying , we are keeping it under mod again , to make sure all is under 1e9 + 7. We are multiplying because the answer is n^k. 
//Dry run it for the test case , and you will understand. 

ll multiply(ll a, ll b){
    return mod(mod(a) * mod(b));
}

void solve(){
    
    int t;
    cin >>t;
    
    while(t--){
        
        int n, k;
        cin >> n >>k;
        ll ans = 1;
        for(int i = 0 ; i < k ; i++){
            ans = multiply(ans, n);
        }
        
        cout << ans << endl;
        
    }
    
}


int main()
{
    solve();
    
    

    
}
