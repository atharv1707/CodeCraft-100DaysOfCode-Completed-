class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> charCounts; 

        // Populate the map with character counts from the magazine
        for (char c : magazine) {
            charCounts[c]++;
        } //if the char c is not present in the charCounts, it will automatically assign it in the map, intialising the count to 1.

        // Check if characters in the ransomNote can be constructed from the magazine
        for (char c : ransomNote) {
            if (charCounts[c] > 0) {
                charCounts[c]--;  // Decrement the count for the character
            } else {
                return false;  // The character is not available in sufficient quantity
            }
        }

        return true;  // All characters in ransomNote can be constructed from the magazine
    }
};
