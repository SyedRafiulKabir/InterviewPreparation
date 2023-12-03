#include<iostream>
#include<climits>

using namespace std;
int arr[12][12], vis[12][12];
int dx, dy, n, m; 
int ans = INT_MAX;

bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void solve(int x, int y, int jump) {
    if(!isValid(x,y)) return;
    if(x == dx && y == dy) {
        ans = min(ans, jump);
        return;
    }
    vis[x][y] = 1;
    //up
    int up = x - 1;
    while(up >= 0 && arr[up][y] == 0) up--;
    if(up >=0 && vis[up][y] == 0) {
        solve(up, y, max(jump, (x-up)));
    }
    //down
    int down = x+1;
    while(down < n && arr[down][y] == 0) down++;
    if(down < n && vis[down][y] == 0) {
        solve(down, y, max(jump,(down - x)));
    }
    //left
    int left = y-1;
    if(left >= 0 && arr[x][left] != 0 && vis[x][left] == 0) {
        solve(x, left, jump);
    }
    int right = y+1;
    if(right < m && arr[x][right] != 0 && vis[x][right] == 0) {
        solve(x, right, jump);
    }
    vis[x][y] = 0;

}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 3) {
                dx = i;
                dy = j;
            }
        }
    }
    solve(n-1, 0, 0);
    cout << ans << endl;
    return 0;
}