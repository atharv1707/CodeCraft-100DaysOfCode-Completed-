class Solution {
public:
    int numRescueBoats(std::vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());
        int i = 0;
        int j = people.size() - 1;
        int count = 0;

        while (i <= j) {
            if (i == j) {
                count++;
                break;
            }

            if (people[i] + people[j] <= limit) {
                count++;
                i++;
                j--;
            } else {
                count++;
                j--;
            }
        }

        return count;
    }
};
