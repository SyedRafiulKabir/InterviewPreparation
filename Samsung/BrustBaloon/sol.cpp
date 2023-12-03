#include<iostream>
#include<vector>
using namespace std;
int n;
int solve(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = INT_MIN;
    for(int ind = i; ind <= j;ind++) {
        int coins = 0;
        if(i == 1 && j == n) {
            coins = arr[ind] + solve(i, ind - 1, arr, dp) +  solve(ind + 1, j, arr, dp);
        }
        else {
            coins = arr[i-1] * arr[j+1] + solve(i, ind - 1, arr, dp) +  solve(ind + 1, j, arr, dp);
        }
        ans = max(ans, coins);
    }
    return dp[i][j] = ans;
}
int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    vector<int> loon;
    loon.push_back(1);
    for(int i = 0;i < n;i++) {
        int tem;
        cin >> tem;
        loon.push_back(tem);
    }
    loon.push_back(1);
    vector<vector<int>> dp(n+2,vector<int>(n+2, -1));
    cout << solve(1, n, loon, dp) << endl;
    return 0;

}