#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<vector<int>> arr,vis;
int ans, n, m, u, v, level;
bool isValid(int x, int y) {
    return x < n && x >=0 && y < m && y >=0 && arr[x][y] != 0 && vis[x][y] == 0;
}
/*
left = 1, 3, 6, 7
right =1 3, 4, 5
up = 1, 2, 4, 7
down =1, 2, 5, 6
*/
bool right(int x, int y) {
    return arr[x][y] == 1 || arr[x][y] == 3 || arr[x][y] == 4 || arr[x][y] == 5;
}
bool left(int x, int y) {
    return arr[x][y] == 1 || arr[x][y] == 3 || arr[x][y] == 6 || arr[x][y] == 7;
}
bool up(int x, int y) {
    return arr[x][y] == 1 || arr[x][y] == 2 || arr[x][y] == 4 || arr[x][y] == 7;
}
bool down(int x, int y) {
    return arr[x][y] == 1 || arr[x][y] == 2 || arr[x][y] == 5 || arr[x][y] == 6;
}

void bfs() {
    vis[u][v] = 1;
    queue<pair<int, int>>q;
    q.push({u,v});
    while(!q.empty()) {
        auto it = q.front();
        int x = it.first;
        int y = it.second;
        q.pop();
        if(arr[x][y] == 0 || vis[x][y] > level) continue;
        ans++;
        //left
        if(isValid(x,y-1) && left(x,y) && right(x,y-1)) {
            vis[x][y-1] = vis[x][y] + 1;
            q.push({x,y-1});
        }
        //right
        if(isValid(x,y+1) && right(x,y) && left(x,y+1)) {
            vis[x][y+1] = vis[x][y] + 1;
            q.push({x,y+1});
        }
        //up
        if(isValid(x-1,y) && up(x,y) && down(x-1,y)) {
            vis[x-1][y] = vis[x][y] + 1;
            q.push({x-1,y});
        }
        //down
        if(isValid(x+1,y) && down(x,y) && up(x+1,y)) {
            vis[x+1][y] = vis[x][y] + 1;
            q.push({x+1,y});
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--) {
        ans = 0;
        arr.clear();
        vis.clear();
        cin >> n >> m >> u >> v >> level;
        for(int i = 0;i < n;i++) {
            vector<int> tem,tem2;
            for(int j = 0;j < m;j++) {
                int num;
                cin>>num;
                tem.push_back(num);
                tem2.push_back(0);
            }
            vis.push_back(tem2);
            arr.push_back(tem);
            tem.clear();
        }

        bfs();
        cout << ans << endl;
    }

    return 0;
}