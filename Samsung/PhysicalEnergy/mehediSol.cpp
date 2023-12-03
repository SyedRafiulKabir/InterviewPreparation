#include<vector>
#include<iostream>
#include<string.h>
using namespace std;
#define inf 2e9
int n = 5;
int dp[4001][1001][5];

vector<int> energy(n), time(n);

int solve(int h, int d, int itr){
    if(itr < 0 || h < 0){
        return inf;
    }
    if(d == 0) return 0;
    if(dp[h][d][itr] != -1) return dp[h][d][itr];
    int ans = min(solve(h, d, itr-1), time[itr] + solve(h - energy[itr], d-1, itr));
    cout<<ans<<endl;

    return dp[h][d][itr] = ans;
}

int main(){
    freopen("in.txt", "r", stdin);
    int testcase;
    cin>>testcase;
    while(testcase--){
        int h, d;
        cin>>h>>d;
        for(int i = 0; i < n; i++){
            cin>>energy[i];
        }
        for(int i = 0; i < n; i++){
            cin>>time[i];
        }
        memset(dp, -1, sizeof(dp));
        int ans = solve(h, d, 4);
        cout<<ans<<endl;
    }
    return 0;
}