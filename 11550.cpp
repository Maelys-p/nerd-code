#include <iostream>
#include <vector>
#define ull unsigned long long
#include <map>
using namespace std;
map<pair<ull, ull>, ull> memo;
ull C(ull n, ull k) {
    if (k == 0 || k == n) return 1;
    if (memo.find({n, k}) != memo.end()) return memo[{n, k}];
    if (k > n / 2) {memo[{n,k}] = C(n,n-k); return memo[{n,k}];};

    std::vector<ull> dp(k + 1, 0);
    dp[0] = 1;
   

    for (ull i = 1; i <= n; ++i) {
        for (ull j = std::min(i, k); j > 0; --j) {
            dp[j] = dp[j] + dp[j - 1];
        }
    }
    memo[{n,k}] = dp[k];
    return dp[k];
}

int main() {
    ull n,k;
    cin >> k >> n; 
    cout << C(n-1,k-1);

    return 0;
}