#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int sum_g = 0;
    int sum_h = 0;
    int count_g = 0;
    std::vector<int> dif_positive;
    std::vector<int> dif_negative;

    int n, g, h;
    std::cin >> n >> g >> h;

    if ((g + h) > n) {
        std::cout << -1;
        return 0;
    }

    int grunt, headhunter;
    int result = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> grunt >> headhunter;

        if (grunt >= headhunter) {
            result += grunt;
            ++count_g;
        } else {
            result += headhunter;
        }

        int difference = headhunter - grunt;
        if (difference > 0) {
            dif_positive.push_back(difference);
        } else {
            dif_negative.push_back(difference);
        }
    }

    std::sort(dif_positive.begin(), dif_positive.end(), std::greater<>());
    std::sort(dif_negative.begin(), dif_negative.end());

    if (count_g < g && count_g != n) {
        int lack = g - count_g;
        for (int i = 0; i < lack; ++i) {
            result -= dif_positive.back();
            dif_positive.pop_back();
        }
    } else if ((n - count_g) < h) {
        int lack = h - (n - count_g);
        for (int i = 0; i < lack; ++i) {
            result += dif_negative.back();
            dif_negative.pop_back();
        }
    }

    std::cout << result;

    return 0;
}
