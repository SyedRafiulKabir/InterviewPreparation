#include<iostream>
#include<vector>

using namespace std;
int n, m, maxi = 0;
vector<vector<int>> flip(vector<vector<int>>& arr, int j) {
    for(int i = 0;i < n;i++) {
        arr[i][j] = 1- arr[i][j];
    }
    return arr;
}
void solve(vector<vector<int>>& arr, int k) {
    if(k == 0) {
        int ans = 0;
        for(int i = 0;i < n;i++) {
            int zeros = 0;
            for(int j = 0;j < m;j++) {
                if(arr[i][j] == 0) zeros++;
            }
            if(zeros == 0) ans++;
        }
        maxi = max(ans, maxi);
        return;
    }
    for(int i = 0;i < m;i++) {
        arr = flip(arr, i);
        solve(arr, k-1);
        arr = flip(arr, i);
    }


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
    solve(arr, k);
    cout << maxi << endl;
    return 0;
}