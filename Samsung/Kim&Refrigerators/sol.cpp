#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
int n, ox, oy, hx, hy, ans;
int dis[12][12];
int  cor[12][2];
int dp[1 << 12][12];
int distan(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}
int solve(int mask, int crr) {
    if(mask == ((1 << (n+1)) - 1)) return distan(cor[crr][0], cor[crr][1], hx, hy);
    if(dp[mask][crr] != -1) return dp[mask][crr];
    int ans = 1000000;
    for(int i = 0;i <= n;i++) {
        if((mask & (1 << i)) == 0) {
            ans = min(ans, solve((mask | (1 << i)), i) + dis[crr][i]);
        }
    }
    return dp[mask][crr] = ans;
}
int main() {
    freopen("in.txt", "r", stdin);
    int t = 0;
    while(t++ < 10) {
        cin >> n >> ox >> oy >> hx >> hy;
        cor[0][0] = ox;
        cor[0][1] = oy;
        for(int i = 1;i <= n;i++) {
            cin >> cor[i][0] >> cor[i][1];
        }
        for(int i = 0;i <= n;i++) {
            for(int j = 0;j <= n;j++) {
                dis[i][j] = distan(cor[i][0], cor[i][1], cor[j][0],cor[j][1]);
            }
        }
        memset(dp, -1, sizeof(dp));
        cout<< "# " << t << " " << solve(1,0) << endl;
    }
    return 0;
}