#define ll long long

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        ll mod = 1e9+7;
        ll low = 1, mid;
        ll high = static_cast<ll>(min(a, b)) * n; // Use 'll' for 'high' and 'static_cast'

         // Initialize low and high
        ll lcm_ab = lcm(a, b);

        while (low < high) { // Use '<' instead of '<='
            mid = low + (high - low) / 2;
            ll target = mid / a + mid / b - mid / lcm_ab;

            if (target < n) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return (high % mod);
    }
    
private:
    ll gcd(ll a, ll b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    ll lcm(ll a, ll b) {
        return a / gcd(a, b) * b;
    }
};
