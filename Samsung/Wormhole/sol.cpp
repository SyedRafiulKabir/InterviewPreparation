#include<iostream>
#include<vector>
#include<climits>

using namespace std;
int arr[10][5];
int n, ans;
bool vis[10];
int dis(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void solve(int sx, int sy, int dx, int dy, int val) {
    ans = min(ans, (dis(sx, sy, dx, dy) + val));
    for(int i = 0;i < n;i++) {
        if(vis[i] == false) {
            vis[i] = true;
            int tem = dis(sx, sy, arr[i][0], arr[i][1]) + arr[i][4] + val;
            solve(arr[i][2], arr[i][3], dx, dy, tem);
            tem = dis(sx, sy, arr[i][2], arr[i][3]) + arr[i][4] + val;
            solve(arr[i][0], arr[i][1], dx, dy, tem);
            vis[i] = false;
        }
    }

}

int main() {
    freopen("in.txt", "r", stdin);
    int test;
    cin >> test;
    while(test--) {
        ans = INT_MAX;
        cin >> n;
        int sx,sy,dx,dy;
        cin >> sx >> sy >> dx >> dy;
        for(int i = 0;i < n;i++) {
            vis[i] = false;
            for(int j = 0;j < 5;j++) {
                cin >> arr[i][j];
            }
        }
        solve(sx, sy, dx, dy, 0);
        cout << ans << endl;
    }
    return 0;
}