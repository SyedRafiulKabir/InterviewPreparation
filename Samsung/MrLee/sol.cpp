#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std;
int dp[1 << 12][12];
int solve(int mask, int crr, int n, vector<vector<int>>& arr, int cost) {
    if(mask == ((1 << n) - 1)) return cost + arr[crr][0];
    if(dp[mask][crr] != -1) return dp[mask][crr];
    int ans = INT_MAX;
    for(int i = 1;i < n;i++) {
        if((mask & (1 << i)) == 0) {
            if(arr[crr][i] != 0)
            ans = min(ans, solve((mask | (1 << i)), i, n, arr, cost + arr[crr][i]));

        }
    }
    return dp[mask][crr] = ans;

}

int main() {
    freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(n));
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                cin >> arr[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        cout << solve(1 ,0, n, arr, 0) << endl;
    }
    return 0;
}