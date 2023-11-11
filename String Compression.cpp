
class Solution {
public:
    int compress(std::vector<char>& chars) {
        int i = 0;
        int ansIndex = 0;
        int n = chars.size();

        while (i < n) {
            int j = i + 1;
            while (j < n && chars[i] == chars[j]) {
                j++;
            }

            int count = j - i;
            chars[ansIndex++] = chars[i];

            if (count > 1) {
                string cnt = to_string(count);
                for (char c : cnt) {
                    chars[ansIndex++] = c;
                }
            }

            i = j;
        }

        return ansIndex;
    }
};
