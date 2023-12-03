#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int n, e, mini = INT_MAX;
vector<int> adj[15], prnt(50, 0), vis(50, 0), tem, ans;

void printarr(vector<int> adj[]) {
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j < adj[i].size();j++) {
            cout << i << " " << adj[i][j] << " ";
        }
        //cout << endl;
    }
}

void dfs(int node, int p) {
    vis[node] = 1;
    prnt[node] = p;
    for(int i = 0;i < adj[node].size();i++) {
        int s = adj[node][i];
        if(vis[s] == 0) {
            dfs(s, node);
        }
        //vis[s] == 1,means cycly detected
        else {
            int v = node, sum = node;
            tem.push_back(v);
            while(v != s && v > 0) {
                v = prnt[v];
                tem.push_back(v);
                sum += v;
            }
            if(sum < mini) {
                ans = tem;
                mini = sum;
            }
            tem.clear();

        }
    }
    vis[node] = 0;
}

int main() {
    freopen("in.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--) {
        cin >> n >> e;
    
        for(int i = 0;i < e;i++) {
            int x,y;
            cin>> x >> y;
            adj[x].push_back(y);
        }
        //printarr(adj);
        //cout<<endl;
        for(int i = 1;i <= n;i++) {
            if(vis[i] == 0) {
                dfs(i, -1);
            }
        }
        sort(ans.begin(), ans.end());
        
        for(auto &itr : ans)
            cout<<itr<<' ';
        cout<<endl;
        ans.clear();
        for(int i = 1;i <=n;i++) {
            adj[i].clear();
        }
        prnt.clear();
        vis.clear();
        mini = INT_MAX;
    }
    return 0;
}