#define ll long long

class Solution {
private:
    ll gcd(ll a, ll b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    ll lcm(ll a, ll b) {
        return (a * b) / gcd(a, b);
    }

public:
    int nthMagicalNumber(int n, int a, int b) {
        ll mod = 1e9 + 7;
        ll low = 1;
        ll mid;
        ll high = static_cast<ll>(min(a, b) ) * n; //narrowing the search space 
        ll target;
        ll lcm_ab = lcm(a, b);

        while (low < high) {
            mid = low + (high - low) / 2;
            target = mid / a + mid / b - mid / lcm_ab; // 

            if (target >= n) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return static_cast<int>(high % mod);
    }
};
