#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
#include<string.h>
using namespace std;

int n = 5;
int dp[4001][1001][5];
int energy[5], time[5];

int solve(int en, int d, int it) {
    if(it < 0 || en < 0) {
        return INT_MAX;
    }
    if(d == 0) return 0;
    if(dp[en][d][it] != -1) return dp[en][d][it];
    int ans = min(solve(en, d, it-1), time[it] + solve(en - energy[it], d-1, it));
    cout<<ans<<endl;
    return dp[en][d][it] = ans;
}


int main() {
    freopen("in.txt", "r", stdin);
    int t;
    cin>> t;
    while(t--) {
        int en,d;
        cin>>en>>d;
        for(int i = 0;i < 5;i++) {
            cin >> energy[i];
        }
        for(int i = 0;i < 5;i++) {
            cin >> time[i];
        }
        // for(int i = 0;i < 5;i++) {
        //     cout << energy[i]<<" ";
        // }
        // cout<<endl;
        // for(int i = 0;i < 5;i++) {
        //     cout << time[i]<<" ";
        // }
        // cout<<endl;
        memset(dp, -1, sizeof(dp));
        int ans = solve(en, d, 4);
        cout << ans << endl;

    }
    return 0;
}