 
#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std; 
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


int main()
{

ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int t;
cin>>t;

ull answer = 0;

while(t--){
    answer = 0;
    vector<ull> v;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        ull k;
        cin>>k;
        v.push_back(k);
    }
    for(int i = 0; i<v.size()-1; i++){
        for(int j = i+1; j<v.size(); j++){
            answer+=gcd(v[i], v[j]);
        }
    }
    cout<<answer<<endl;
    
    }
    return 0;
}