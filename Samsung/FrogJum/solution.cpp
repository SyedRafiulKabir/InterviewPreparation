#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n, m, dx, dy;
int dir[] = {0, -1, 0, 1, 0};

bool isValid(int x, int y) {
    return x >=0 && y >= 0 && x < n && y < m;
}
int solve(int hx, int hy, vector<vector<int>>& arr, vector<vector<int>>& vis, vector<vector<int>>& level) {
    queue<pair<int, int>> q;
    q.push({hx,hy});
    level[hx][hy] = 0;

    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        int x = it.first;
        int y = it.second;
        vis[x][y] = 1;
        if(x == dx && y == dy) return level[x][y];
        for(int i = 0;i < 4;i++) {
            int xx = x + dir[i];
            int yy = y + dir[i+1];
            if(isValid(xx,yy) && arr[xx][yy] == 1 && vis[xx][yy] != 1) {
                level[xx][yy] = level[x][y];
                if(x != xx) level[xx][yy]++;
                q.push({xx,yy});
            }
        }
    }
    return level[dx][dy];
}

int main() {
    freopen("in.txt", "r", stdin);
    int t, hx, hy;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<int>> level(n, vector<int>(m,0));
        vector<vector<int>> arr(n, vector<int>(m));
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cin >> arr[i][j];
            }
        }
        cin >> hx >> hy >> dx >> dy;
        cout << solve(hx, hy, arr, vis, level) << endl;
    }
    return 0;
    
}