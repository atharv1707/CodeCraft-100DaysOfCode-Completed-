#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int X;
        cin >> X;
        int N;
        cin >> N;

        int req = (N + 99) / 100;  // This rounds up N/100
        if(X >= req){
            int ans = 0;
            cout << ans << endl;
        } else {
            int ans = req  - X;
            cout << ans << endl;
        }
    }
    return 0;
}
