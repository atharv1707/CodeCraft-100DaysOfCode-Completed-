#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        int N;
        cin >> N;
        cin.ignore();

        int arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        unordered_map<int, int> freqMap;

        for (int i = 0; i < N; i++) {
            freqMap[arr[i]]++; //it automatically adds if element doesn't exist beforehand
        }

        bool hasDominant = false;

        for (const auto& entry : freqMap) {
            int element = entry.first;
            int frequency = entry.second;

            bool isDominant = true;

            for (const auto& other : freqMap) {
                //checking if element are not same and then the checking the frequency.
                if (element != other.first && frequency <= other.second) {
                    isDominant = false;
                    break;
                }
            } //this loop is for checking each element of the freqmap with the all other elements of the freqmap, to see if there is any element with more freq or not. If there are elements with equal frequency, then too it can't be dominant.

            if (isDominant) {
                hasDominant = true;
                break;
            }
        }

        if (hasDominant) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
