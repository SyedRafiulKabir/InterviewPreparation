#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> ppl(4), gate(4), vis(100);
int n,ans = INT_MAX;
int findLeft(int ind) {
    for(int i = ind-1;i > 0;i--) {
        if(vis[i] == 0) return i;
    }
    return INT_MAX;
}
int findRight(int ind) {
    for(int i = ind;i <= n;i++) {
        if(vis[i] == 0) return i;
    }
    return INT_MAX;
}
void func(int x, int y, int z, int st, int cost) {
    if(cost > ans) return;
    if(ppl[st] == 0) {
        if(st == x) st = y;
        else if(st == y) st = z;
        else {
            ans = min(ans, cost);
            return;
        }
    }
    int leftpos,ripos;
    leftpos = findLeft(gate[st]);
    ripos = findRight(gate[st]);
    int leftDis, riDis;
    leftDis = abs(gate[st] - leftpos) + 1;
    riDis = abs(ripos - gate[st]) + 1;
    int minpos,minDis;
    if(leftDis <= riDis) minpos = leftpos,minDis = leftDis;
    else minpos = ripos,minDis = riDis;
    if(ppl[st] == 1 && leftDis == riDis) {
        vis[leftpos] = 1;
        ppl[st]--;
        func(x,y,z,st,cost + leftDis);
        vis[leftpos] = 0;
        ppl[st]++;

        vis[ripos] = 1;
        ppl[st]--;
        func(x, y, z, st, cost + riDis);
        vis[ripos] = 0;
        ppl[st]++;
    }
    else {
        vis[minpos] = 1;
        ppl[st]--;
        func(x, y, z, st, cost + minDis);
        vis[minpos] = 0;
        ppl[st]++;
        
    }
}
void init() {
    for(int i = 0;i <= n;i++) vis[i] = 0;
    return;
}
void solve(int x, int y, int z, int st) {
    init();
    func(x, y, z, st, 0);
    return;
}
int main() {
    freopen("in.txt", "r", stdin);
    int t = 1;
    while(t--) {
        cin >> n;
        for(int i = 1;i <= 3;i++) {
            cin >> gate[i];
        }
        for(int i = 1;i <= 3;i++) {
            cin >> ppl[i];
        }
        solve(1,2,3,1);
        solve(1,3,2,1);
        solve(2,1,3,2);
        solve(2,3,1,2);
        solve(3,1,2,3);
        solve(3,2,1,3);
        cout << ans << endl;
    }
}