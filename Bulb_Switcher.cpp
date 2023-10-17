class Solution {
public:
    int bulbSwitch(int n) {

         int ans = (pow(n,2) == sqrt(n))? sqrt(n) : floor(sqrt(n));
        return ans;
    }
};