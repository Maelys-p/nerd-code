#include <iostream>
#include <vector>
#include <iomanip>

#define ull unsigned long long

ull C(ull n, ull k) {
    if (k == 0 || k == n) return 1;

    if (k > n / 2)  k = n - k;

    std::vector<ull> dp(k + 1, 0);
    dp[0] = 1;

    for (ull i = 1; i <= n; ++i) {
        for (ull j = std::min(i, k); j > 0; --j) {
            dp[j] = dp[j] + dp[j - 1];
        }
    }

    return dp[k];
}

int main() {
    ull n, k;
    std::cin >> n >> k;
    std::vector<ull> coeff(n - k + 1, 0);
    for (ull i = 1; i <= n - k + 1; ++i) {
        coeff[i - 1] = C(n - i, k - 1);
    }

    double result = 0.0;
    double sum = 0.0;
    for (ull i = 0; i < coeff.size(); ++i) {
        result += coeff[i] * (1ULL << (i + 1));
        sum += coeff[i];
    }

    std::cout << std::setprecision(7) << result / sum;

    return 0;
}
