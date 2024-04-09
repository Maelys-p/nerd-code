    #include <iostream>
    #include <vector>
    using namespace std;
    int count = 0;
    void BFS(int i, int j, vector<vector<char>>& graph) {
        if(graph[i][j] == '.'){
            graph[i][j] = ' ';
            count++;
            BFS(i+1,j, graph);
            BFS(i,j+1, graph);
            BFS(i,j-1, graph);
            BFS(i-1,j, graph); // it works so cry about it

        }
        else return;
        
    }

    int main() {
        int n, x, y;
        cin >> n;

        vector<vector<char>> graph(n, vector<char>(n));
        vector<bool> visited(n, false); 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> graph[i][j];
            }
        }

        cin >> x >> y;
        BFS(x - 1,y - 1,graph);

        cout << count << '\n';

        return 0;
    }