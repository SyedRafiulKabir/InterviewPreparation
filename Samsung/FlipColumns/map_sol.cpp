#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int n,m;

int solve(vector<vector<int>>& arr, int k) {
    int ans = 0;
    unordered_map<string, int> mp;
    for(int i = 0;i < n;i++) {
        string s = "";
        int zeros = 0;
        for(int j = 0;j < m;j++) {
            s += arr[i][j] + '0';
            if(arr[i][j] == 0) zeros++;
        }
        if(zeros <= k && (k - zeros) % 2 == 0) {
            mp[s]++;
        }
        ans = max(ans, mp[s]);
    }
    return ans;
}

int main() {
    freopen("in.txt", "r", stdin);
    int k;
    cin >> n >> m >> k;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> arr[i][j];
        }
    }
    
    cout << solve(arr, k) << endl;
    return 0;
}