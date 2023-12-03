#include<iostream>
#include<climits>
#include<vector>

using namespace std;
int n;
int func(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = INT_MIN;
    for(int index = i; index <= j; index++) {
        int coins = 0;
        if(i == 1 && j == n) {
            coins = arr[index] + func(i, index - 1, arr, dp) + func(index + 1, j, arr, dp);
        }
        else {
            coins = arr[i-1] * arr[j+1] + func(i, index - 1, arr, dp) + func(index + 1, j, arr, dp);
        }
        ans = max(ans, coins);
    } 
    return dp[i][j] = ans;
}
int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    vector<int> arr;
    arr.push_back(1);
    for(int i = 0;i < n;i++) {
        int num;
        cin>>num;
        arr.push_back(num);
    }
    arr.push_back(1);
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    cout << func(1, n, arr, dp) << endl;
    return 0;
}