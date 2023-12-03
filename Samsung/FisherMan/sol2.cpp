#include<iostream>
#include<vector>
using namespace std;
int ans = INT_MAX,n;

int findLeftPos(int k, vector<bool>& vis) {
    for(int i = k - 1;i > 0;i--) {
        if(!vis[i]) return i;
    }
    return INT_MAX;
}
int findRightPos(int k, vector<bool>& vis) {
    for(int i = k;i <= n;i++) {
        if(!vis[i]) return i;
    }
    return INT_MAX;
}


void solve(int g1, int g2, int g3, int g, vector<bool>& vis, vector<int>& gate, vector<int>& p, int cost) {
    if(cost > ans) return;
    if(p[g] == 0) {
        if(g == g1) g = g2;
        else if (g == g2) g = g3;
        else {
            ans = min(ans, cost);
            return;
        }
    }
    int lpos = findLeftPos(gate[g], vis);
    int rpos = findRightPos(gate[g], vis);
    int ldis = abs(gate[g] - lpos) + 1;
    int rdis = abs(gate[g] - rpos) + 1;
    int minPos, minDis;
    if(ldis <= rdis) minPos = lpos, minDis = ldis;
    else minPos = rpos, minDis = rdis;
    
    if(p[g] == 1 && ldis == rdis) {
        //left
        vis[lpos] = 1;
        p[g]--;
        solve(g1, g2, g3, g, vis, gate, p, cost + ldis);
        vis[lpos] = 0;
        p[g]++;
        //right
        vis[rpos] = 1;
        p[g]--;
        solve(g1, g2, g3, g, vis, gate, p, cost + rdis);
        vis[rpos] = 0;
        p[g]++;
    }
    else {
        vis[minPos] = 1;
        p[g]--;
        solve(g1, g2, g3, g, vis, gate, p, cost + minDis);
        vis[minPos] = 0;
        p[g]++;
    }
}

void solution(int x, int y, int z, int open, vector<bool>& vis, vector<int>& gate, vector<int>& p) {
    solve(x, y, z, open, vis, gate, p, 0);
    return;
}

int main() {
    freopen("in.txt", "r", stdin);
    int t = 1;
    //cin >> t;
    while(t--) {
        cin >> n;
        vector<bool> vis(n+1,0);
        vector<int> gate(4), p(4);
        for(int i = 1;i < 4;i++) {
            cin >> gate[i];
        }
        for(int i = 1;i < 4;i++) {
            cin >> p[i];
        }
        solution(1, 2, 3, 1, vis, gate, p);
        solution(1, 3, 2, 1, vis, gate, p);
        solution(2, 1, 3, 2, vis, gate, p);
        solution(2, 3, 1, 2, vis, gate, p);
        solution(3, 1, 2, 3, vis, gate, p);
        solution(3, 2, 1, 3, vis, gate, p);
        cout << ans << endl;
        ans = INT_MAX;


    }
    return 0;
}