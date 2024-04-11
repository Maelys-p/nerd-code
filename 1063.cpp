#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int row[] = {-1, 0, 1, 0}; 
int col[] = {0, 1, 0, -1};

bool Check(int r, int c, int& m, int& n, vector<vector<bool>>& visited, vector<vector<char>>& graph){
    return (r >= 0 && r < m && c >= 0 && c < n && !visited[r][c] && graph[r][c] == '#');


}

void BFS(int r, int c, vector<vector<char>>& graph, vector<vector<bool>>& visited, int& m, int& n) {
 
    queue<pair<int,int>> q;
    q.push({r,c});
    visited[r][c] = true;
  
    while(!q.empty())
    {
        pair<int,int> current = q.front();
        int x = current.first;
        int y = current.second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int a_x = x + row[i];
            int a_y = y + col[i];
            if(Check(a_x,a_y,m,n,visited, graph)){
                q.push({a_x, a_y});
                visited[a_x][a_y] = true;
            }


        }


    }

    
        
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> graph(m, vector<char>(n));
    vector<vector<bool>> visited(m, vector<bool>(n,false)); 
   

    for (int i = 0; i < m; ++i) {
       for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }
    int count = 0;

      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!visited[i][j] && graph[i][j] == '#') {
                BFS(i, j, graph, visited, m, n);
                count++;
            }
        }
    }
    

    cout << count ;

    return 0;
}