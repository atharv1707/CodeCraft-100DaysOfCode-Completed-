class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        bool result;

        if(flowerbed.size()==1 && flowerbed[0]==0&& n==1){
            return true;
        }
        for(int i = 1 ; i<flowerbed.size()-1;i++){

            if(flowerbed[0] == 0 && flowerbed[1] == 0){
                flowerbed[0] = 1;
                n--;
            }
            else if(flowerbed[flowerbed.size()-1] == 0 && flowerbed[flowerbed.size()-2] == 0){
                flowerbed[flowerbed.size()-1] == 1;
                n--;
            }
            else if((flowerbed[i-1] == 0 and flowerbed[i+1]==0) && flowerbed[i]==0){
                flowerbed[i] = 1;
                n--;
            }
            else{
                continue;
            }

        }

        if(n<=0){
            result = true;
        }
        else{
            result = false;
        }

        return result;
    }
};