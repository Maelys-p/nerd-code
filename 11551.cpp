#include <iostream>
#include <vector>
#define ull unsigned long long

using namespace std;

ull C(ull n, int k) {
    if (k == 0 || k == n) return 1;
    
    if (k > n / 2) k=n-k;

    std::vector<ull> dp(k + 1, 0);
    dp[0] = 1;
   

    for (ull i = 1; i <= n; ++i) {
        for (ull j = (i<k)?i:k; j > 0; --j) {
            dp[j] = dp[j] + dp[j - 1];
        }
    }

    return dp[k];
}

int main() {
    ull n,k;
    cin >> k >> n;
    ull result;
    for(int i = k-1;i>-1;--i){
        result+=C(n-1,i)*C(k,k-i-1);
    }
    cout << result;

    return 0;
}