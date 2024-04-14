#include <iostream>
#include <vector>

 
int main() {
    int n,k;
    std::cin >> n >> k;
    if(k>n/2) k = n-k;
 
 
    std::vector<unsigned long long int> Current(k + 1, 0);
    std::vector<unsigned long long int> Previous(k + 1, 0); 
    Previous[0] = 1; 
    for (int i = 1; i <= n; ++i) {
        Current[0] = 1;
       

        for (int j = 1; j <= std::min(i, k); ++j) {
            Current[j] = Previous[j - 1] + Previous[j]  ;
        } 
        for (int j = 0; j <= k; ++j) {
            Previous[j] = Current[j];
        }
    }
 

    std::cout << Current[k];

    return 0;
}
