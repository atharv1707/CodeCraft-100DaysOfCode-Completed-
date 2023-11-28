class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();i++){
    
  if(m.count(nums[i])!=0 and (i-m[nums[i]]<=k)){
      return true;
  }   
    
  m[nums[i]]=i; 
      
}

    return false;
    
}
        
    
};


//approach 2

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> store;

        int i = 0;
        int j = 0;

        for(j = 0 ; j < nums.size();j++){
            if(j-i > k){
                store.erase(nums[i]);
                i++;
            }

            //that means we are in the correct window size
            //now we check for the duplicate
            if(store.find(nums[j]) != store.end()){
                //if we are in the window size , and we found a duplicate , that means we return true;
                return true;
            }

            store.insert(nums[j]);
        }

        return false;
        
    }
};
