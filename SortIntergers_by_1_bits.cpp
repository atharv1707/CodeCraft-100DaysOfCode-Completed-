class Solution {
public:
    bool static compare(int a, int b) {
    int countA = __builtin_popcount(a); 
    int countB = __builtin_popcount(b);

    if (countA == countB) {
        return a < b; // If counts are the same, sort in ascending order
    }

    return countA < countB; //If countA is greater than countB, then a will come after b in the sorted order..
}

vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), compare);
    return arr;
}
};
