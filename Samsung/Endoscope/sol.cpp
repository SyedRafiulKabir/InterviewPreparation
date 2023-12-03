#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m, u, v, l;
bool isValid(int x, int y,vector<vector<int>>& arr, vector<vector<int>>& vis) {
    return x >= 0 && y >= 0 && x < n && y < m && arr[x][y] != 0 && vis[x][y] == 0;
}
/*
left = 1, 3, 6, 7
right =1 3, 4, 5
up = 1, 2, 4, 7
down =1, 2, 5, 6
*/
bool left(int num) {
    return num == 1 || num == 3 || num == 6 || num == 7;
}
bool right(int num) {
    return num == 1 || num == 3 || num == 4 || num == 5;
}
bool up(int num) {
    return num == 1 || num == 2 || num == 4 || num == 7;
}
bool down(int num) {
    return num == 1 || num == 2 || num == 5 || num == 6;
}
int bfs(vector<vector<int>>& arr, vector<vector<int>>& vis) {
    vis[u][v] = 1;
    int ans = 0;
    queue<pair<int, int>> q;
    q.push({u,v});
    while(!q.empty()) {
        auto it = q.front();
        int x = it.first;
        int y = it.second;
        q.pop();
        if(arr[x][y] == 0 || vis[x][y] > l) continue;

        ans++;
        //left
        int lft = y-1;
        if(isValid(x, lft, arr, vis) && left(arr[x][y]) && right(arr[x][lft])) {
            vis[x][lft] = vis[x][y] + 1;
            q.push({x,lft});
        }
        //right 
        int r = y+1;
        if(isValid(x, r, arr, vis) && left(arr[x][r]) && right(arr[x][y])) {
            vis[x][r] = vis[x][y] + 1;
            q.push({x,r});
        }
        //up
        int upp = x-1;
        if(isValid(upp, y, arr, vis) && up(arr[x][y]) && down(arr[upp][y])) {
            vis[upp][y] = vis[x][y] + 1;
            q.push({upp,y});
        }
        //down
        int dwn = x+1;
        if(isValid(dwn, y, arr, vis) && down(arr[x][y]) && up(arr[dwn][y])) {
            vis[dwn][y] = vis[x][y] + 1;
            q.push({dwn,y});
        }

    }
    return ans;
}

int main() {
    freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m >> u >> v >> l;
        vector<vector<int>> arr(n, vector<int>(m));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++) {
            for(int j =0;j < m;j++) {
                cin >> arr[i][j];
                //cout << arr[i][j] <<" ";
            }
            //cout<<endl;
        }
    cout << bfs(arr, vis) <<endl;
    }
    return 0;
}