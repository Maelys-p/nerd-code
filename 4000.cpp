    #include <iostream>
    #include <vector>
    using namespace std;

    void DFS(int v, vector<bool>& visited, vector<vector<int>>& graph) {
        visited[v] = true;
        for (int i = 0; i < graph.size(); ++i) {
            if(i == v) continue;
            if (graph[v][i] == 1 && !visited[i]) {
                DFS(i, visited, graph);
            }
        }
    }

    int main() {
        int n, s;
        cin >> n >> s;

    vector<vector<int>> graph(n, vector<int>(n, 0));
        vector<bool> visited(n, false); 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> graph[i][j];
            }
        }

        DFS(s - 1, visited, graph); 
        int count = 0;
        for (bool v : visited) {
            if (v) count++;
        }

        cout << count << '\n';

        return 0;
    }