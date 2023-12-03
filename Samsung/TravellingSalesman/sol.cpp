#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
//vector<vector<int>> arr;
int n;
int arr[20][20];
int dp[1 << 20][20];
int solve(int mask, int crr) {
    if((mask == ((1 << n) - 1))) return arr[crr][0];
    if(dp[mask][crr] != -1) return dp[mask][crr];
    int ans = 1000000;
    for(int i = 0;i < n;i++) {
        if((mask & (1 << i)) == 0) {
            ans = min(ans, solve((mask | (1 << i)), i) + arr[crr][i]);
        }
    }
    return dp[mask][crr] = ans;



}
int main() {
    freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                cin >> arr[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        
        cout << solve(1, 0) << endl;
        //ans = 1000000;
    }
    return 0;
}