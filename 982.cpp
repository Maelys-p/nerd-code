#include <iostream>
#include <vector>
using namespace std;
int count = 0;
void DFS(int v, vector<vector<int>> edges, bool visited[], int &n)
{
    visited[v] = true;
    count++;
    if(count >= n) return;
    for(auto u : edges[v])
    {
        if(!visited[u]) DFS(u, edges, visited, n);
    }

}
 
int main(){
    int n,m;
    cin>>n >> m;
    vector<vector<int>> edges(n); 
    bool visited[n] = {false};  

    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);

    }
    DFS(0,edges,visited, n);
     
 
    if(count == n) cout<<"YES";
    else cout<<"NO";

    return 0;
}