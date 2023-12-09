#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    int t = 1;
    //cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int sx = n -1,sy = 0;
        vector<vector<int>> arr(n, vector<int>(m)), vis(n, vector<int>(m,0));
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cin >> arr[i][j];
                //vis[i][j] = 0;
                //if(arr[i][j] == 2) sx = i,sy = j;
                //else if(arr[i][j] == 3) dx = i, dy = j;
            }
        }
        int ans = INT_MIN;
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {sx,sy}});
        while(!pq.empty()) {
            auto it = pq.top();
            int jump = it.first;
            int x = it.second.first, y = it.second.second;
            pq.pop();
            vis[x][y] = 1;
            ans = max(ans, -jump);
            if(arr[x][y] == 3) break;
            //upa
            for(int i = x - 1;i >= 0;i--) {
                if(arr[i][y] == 0) continue;
                if(vis[i][y] == 0) {
                    pq.push({-abs(x-i), {i, y}});
                    break;
                }
            }
            //down
            for(int i = x + 1;i < n; i++) {
                if(arr[i][y] == 0) continue;
                if(vis[i][y] == 0) {
                    pq.push({-abs(i-x), {i, y}});
                    break;
                }
            }
            //left
            for(int i = y - 1; i >= 0;i--) {
                if(arr[x][i] == 0) break;
                if(vis[x][i] == 0) {
                    pq.push({0, {x, i}});
                    break;
                }
            }
            //right
            for(int i = y + 1; i < m;i++) {
                if(arr[x][i] == 0) break;
                if(vis[x][i] == 0) {
                    pq.push({0, {x, i}});
                    break;
                }
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}
