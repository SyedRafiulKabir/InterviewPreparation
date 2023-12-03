#include<iostream>
#include<climits>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int n, r_num, mx, cnt;
int vis[20][20];
//int arr[20][20];
int rare[5][2];
int xdir[] = {0, 1, 0, -1};
int ydir[] = {1, 0, -1, 0};
bool isValid(int x, int y) {
    return x >= 0 && y >=0 && x < n && y < n;
}

void bfs(int u, int v, vector<vector<int>>& arr) {
    vis[u][v] = 1;
    queue<pair<int, int>> q;
    q.push({u,v});
    while(!q.empty()) {
        auto it = q.front();
        int x = it.first;
        int y = it.second;
        //cout<<x<<","<<y<<" ";
        q.pop();
        for(int i = 0;i < 4;i++) {
            int xx = x + xdir[i];
            int yy = y + ydir[i];
            // cout<<x<<","<<y<<" "<<xx<<","<<yy<<endl;
            // cout<<isValid(xx,yy)<<endl;
            if(isValid(xx, yy) && arr[xx][yy] != 0 && vis[xx][yy] == 0 && cnt < r_num) {
                vis[xx][yy] = vis[x][y] + 1;
                //cout<<xx<<","<<yy<<" "<<"vis"<<vis[xx][yy]<<" "<<"previs"<<vis[x][y]<<endl;
                q.push({xx,yy});
                if(arr[xx][yy] == 2) {
                    //cout<<vis[xx][yy]<<endl;
                    mx = max(mx, vis[xx][yy]);
                    cnt++;
                    //cout<<mx<<" "<<cnt<<endl;;
                }
            }
        }
    }
}

int findLongestDis(int x, int y,vector<vector<int>>& arr) {
    mx = 0;
    cnt = 0;
    memset(vis, 0, sizeof(vis));
    bfs(x, y, arr);
    //cout<<cnt<<" "<<mx<<endl;
    return (cnt == r_num) ? mx - 1 : INT_MAX;

}

int main() {
    freopen("in.txt", "r", stdin);
    int test,a,b,cs = 1;
    cin >> test;
    while(test--) {
        cin >> n >> r_num;
        int  ans = INT_MAX;
        vector<vector<int>> arr(n, vector<int>(n));
        for(int i = 0;i < r_num;i++) {
            cin >> a >> b;
            rare[i][0] = a-1;
            rare[i][1] = b-1;
        }
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                cin >> arr[i][j];
                //vis[i][j] = 0;
            }
        }
        for(int i = 0;i < r_num;i++) {
            arr[rare[i][0]][rare[i][1]] = 2;
        }
        // for(int i = 0;i < r_num;i++) {
        //     cout << rare[i][0] << " " << rare[i][1] << endl;
        // }
        // for(int i = 0;i < n;i++) {
        //     for(int j = 0;j < n;j++) {
        //         cout << arr[i][j] << " ";
        //         //vis[i][j] = 0;
        //     }
        //     cout<<endl;
        // }
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                if(arr[i][j] != 0) {
                    ans = min(ans, findLongestDis(i, j, arr));
                    //cout<< findLongestDis(i, j, arr) << " ";
                }
            }
        }
        cout<<'#'<<cs++<<": "<<ans<<endl;
        //ans = INT_MAX;

    }
    return 0;
}