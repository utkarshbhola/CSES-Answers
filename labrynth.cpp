#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    // Directions: U, D, L, R
    vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<char> dirChar = {'U','D','L','R'};
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));
    vector<vector<char>> moveDir(n, vector<char>(m));
    
    pair<int,int> start, end;
    
    // Find A and B
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') start = {i,j};
            if (grid[i][j] == 'B') end = {i,j};
        }
    }
    
    queue<pair<int,int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
    
    bool found = false;
    
    // BFS
    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        
        if (y == end.first && x == end.second) {
            found = true;
            break;
        }
        
        for (int k = 0; k < 4; k++) {
            int ny = y + dirs[k].first;
            int nx = x + dirs[k].second;
            
            if (ny >= 0 && ny < n && nx >= 0 && nx < m && !visited[ny][nx] && grid[ny][nx] != '#') {
                visited[ny][nx] = true;
                parent[ny][nx] = {y, x};
                moveDir[ny][nx] = dirChar[k];
                q.push({ny, nx});
            }
        }
    }
    
    if (found) {
        cout << "YES\n";
        string path;
        pair<int,int> cur = end;
        
        // Reconstruct path
        while (cur != start) {
            path.push_back(moveDir[cur.first][cur.second]);
            cur = parent[cur.first][cur.second];
        }
        reverse(path.begin(), path.end());
        
        cout << path.size() << "\n";
        cout << path << "\n";
    } else {
        cout << "NO\n";
    }
    
    return 0;
}
