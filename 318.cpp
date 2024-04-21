#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

using ull = unsigned long long;

struct hash_pair {
    size_t operator()(const pair<int, int>& p) const {
        size_t hash1 = hash<int>{}(p.first);
        size_t hash2 = hash<int>{}(p.second);
        return hash1 ^ (hash2 << 1);
    }
};

typedef unordered_map<pair<ull, ull>, ull, hash_pair> Memo;
Memo memo;

ull gcd(ull a, ull b){
    if(b > a) swap(a,b);
    ull r = a%b;
    while(r != 0)
    {
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}


ull C(ull n, ull k) {
    if (k > n / 2) k = n - k;
 
    auto key = make_pair(n, k);
    if(memo.contains(key)) return memo[{key}];
    ull result = 1;
    for(int i = 0; i < k; ++i){
        ull div = gcd(result,i + 1);
        ull divi = (n-i)/ ((i+1)/div);
        result = result/ div * divi;
    }
    
    memo.insert(Memo::value_type(key,result));        
    return result;
}

int main() {
   int t;
    cin >> t;
    ull n, k;
    while (t--) {
        cin >> n >> k;
        cout << C(n, k) << endl;
    }
}