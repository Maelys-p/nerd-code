#include <iostream>
#include <vector>

 
int main() {
    int n;
    std::cin >> n;

    std::vector<unsigned long long> C(n+1);

    C[0] = 1;
    C[n] = 1;
    unsigned long long answer = 0;
    for(int k = 0; k < n; ++k){
        C[k+1] = (C[k] * (n-k)) / (k+1);
        answer+=C[k]*C[k];
    }
    answer++;

    std::cout << answer;

    return 0;
}
