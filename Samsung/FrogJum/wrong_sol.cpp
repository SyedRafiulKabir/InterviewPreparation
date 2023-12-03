#include<iostream>
#include<vector>
using namespace std;

int n, m, dx, dy, hx, hy, ans = 1000000;
int arr[15][15], vis[15][15]; 

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >=0 && y < m;
}
void solve(int x, int y, int jump) {
    if(!isValid(x,y)) return;
    vis[x][y] = 1;
    if(x == dx && y == dy) {
        ans = min(ans, jump);
        return;
    }
    //up
    int up = x-1;
    if(arr[up][y] == 1 && vis[up][y] == 0) {
        solve(up, y, jump+1);
    }
    //down
    int down = x+1;
    if(arr[down][y] == 1 && vis[down][y] == 0) {
        solve(down, y, jump + 1);
    }
    //left
    int left = y-1;
    if(arr[x][left] == 1 && vis[x][left] == 0) {
        solve(x, left, jump);
    }
    //right
    int right = y+1;
    if(arr[x][right] == 1 && vis[x][right] == 0) {
        solve(x, right, jump);
    }
    vis[x][y] = 0;

}
int main() {
    freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cin >> arr[i][j];
                vis[i][j] = 0;
            }
        }
        cin >> hx >> hy >> dx >> dy;
        solve(hx, hy, 0);
        cout << ans <<endl;
        ans = 1000000;

    }
    return 0;
    
}