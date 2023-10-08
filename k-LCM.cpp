/*
the intuition behind this solution is , we HAVE to break down a number. Breaking down a number won't affect it's sum,
but it will sure affect it's overall LCM. That is the thing we have to focus on here. Because this was the easy version, we have k=3.
Take 3 cases : 1)  n is even  2) n is even but n/2 is odd 3) n is odd. Simply break them down and you will see the pattern. 
It is just another pattern question, once you understand it, and give it enought time. 
*/

#include <iostream>

using namespace std;


void solve(){
    int t ;
    cin >>t;
    while(t--){
        int n;
        int k =3;
        cin >>n;
        
        //first we see if the number is odd or even
        //CASE 1 : Odd
        if(n%2 == 1){
            cout << n/2 << " " << n/2 << " " << 1 << endl;
            
        }
        
        else{
            if(n%4 == 0 ){
                        //if number is  divisble by 4, which means n/2 is even
        
                cout << n/4 << " " << n/4 <<" " << n/2  << endl; 
            }
            else{
                   //if number is not divisble by 4, which means n/2 is not even
             
                cout << (n/2)-1 << " " << (n/2)-1 << " " << 2 << endl; 

            }
                
            }
        }
    }


int main()
{
    solve();

    return 0;
}