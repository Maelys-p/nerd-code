#include <iostream>

int main(){
    int S,K,A,B;
    std::cin >> S >> K >> A >> B;
    bool possible = false;
    int N;
    for(int i = 1; i < 1001; ++i)
    {
        int l = A-K*i;
        int m = (B - l*S);
        if(l<=0 || m<0 || m%i != 0) continue;
        N = m / i;
        possible = true;
        break;

    }
    if(possible) std::cout<<N;
    else std::cout<<-1;
    return 0;
}
