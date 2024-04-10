#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> color;

bool dfs(int v, int c) {
    color[v] = c;
    for (int u : graph[v]) {
        if (color[u] == -1) {
            if (!dfs(u, 1 - c))
                return false;
        } else if (color[u] == c) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n);
    color.assign(n, -1);

     for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }


    bool possible = true;
    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
            if (!dfs(i, 0)) {
                possible = false;
                break;
            }
        }
    }

    if (possible)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}