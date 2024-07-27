#include <bits/stdc++.h>
#include <set>
using namespace std;

 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, T;
    cin >> n >> T;
    vector<vector<pair<int,int>>> v(n + 1);
    vector<int> res;
    set<pair<int,int>> s;
    int sum = 0; 
    for(int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(make_pair(b,i));
    }
    for(int k = n; k> 0; k--){
        for(auto vp : v[k])
        {
            sum+=vp.first;
            s.emplace(vp);
        }
        while(s.size() > k){
            sum-=(--s.end())->first;
            s.erase(--s.end()); 
        }
        if(s.size() == k && sum <= T)
        {for(auto p : s) res.push_back(p.second); break;}

    }
    int size = res.size();
    cout<<size<<'\n'<<size<<'\n';
    for(int i = 0; i < size; ++i)
        cout<<res[i] + 1<<' ';
    cout<<'\n';
}