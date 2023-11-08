#include <iostream>
using namespace std;

int main() {
   int t;
   cin >> t;
   
   while(t--){
       int N;
       string Chef;
       string Chefina;
       cin >> N;
       cin >> Chef;
       int chefpoints = 0 ;
       int chefinapoints = 0 ;
       cin >> Chefina;
       int diff = 0 ;
       
       for(int i = 0 ; i < N ; i++){
           if(Chef[i] == Chefina[i]){
               continue;
           }
           
           else if((Chef[i] =='R' && Chefina[i] == 'S') || (Chef[i] =='P' && Chefina[i] == 'R') || (Chef[i] =='S' && Chefina[i] == 'P')){
               chefpoints++;
           }
           else{
               chefinapoints++;
           }
       }
       
       if(chefpoints > chefinapoints){
           cout << "0" << endl;
       }
       else{
           diff = (chefpoints + chefinapoints)/2 + 1;
           cout << diff - chefpoints << endl;
       }
       
       
       
       
       
   }

   return 0;
}