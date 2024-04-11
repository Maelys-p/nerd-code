    #include <iostream>
    #include <vector>
    using namespace std;
    int count = 0;
    void DFS(int v, vector<vector<int>>& graph, vector<bool>& visited, int& n, bool parent = false) {
        visited[v] = true; 
        for(int u = 0; u < n; ++u)
        {
            if(!visited[u] && graph[v][u])
            {
                DFS(u,graph,visited,n);
                
            }
        }
        if(parent)count++;   
    }

    int main() {
        int n;
        cin >> n;

        vector<vector<int>> graph(n, vector<int>(n));
        vector<bool> visited(n, false); 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> graph[i][j];
            }
        }
        for(int i = 0; i < n; ++i ){ 
            if(!visited[i]) DFS(i,graph,visited,n, true);
        }
   
        

        cout << count;

        return 0;
    }