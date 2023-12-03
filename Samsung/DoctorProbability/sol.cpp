#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
#include <iomanip>
using namespace std;
vector< pair <int, double>> adj[100];
unordered_map<int, bool> vis;
unordered_map<int, double> probability;
int finalNode;
double maxProbability;

void bfs(int s, int time) {
    vis[s] = 1;
    queue<int> q;
    q.push(s);
    probability.clear();
    vis.clear();
    probability[s] = 1;

    while (!q.empty()) {
        int sz = q.size();
        maxProbability = 0;

        while(sz--) {
            int u = q.front();
            q.pop();
            for(int i = 0;i < adj[u].size();i++) {
                int v = adj[u][i].first;
                double prob = adj[u][i].second;
                if(u == v) continue;
                if(vis[v] == false) {
                    vis[v] = true;
                    q.push(v);
                }
                probability[v] = probability[v] + prob * probability[u];
                if(probability[v] > maxProbability) {
                    finalNode = v;
                    maxProbability = probability[v];
                }
            }
        }
        time -= 10;
        if(time <= 0) break;
    }
    
    
}

int main() {
    freopen("in.txt", "r", stdin);
    int n,e,t,time;
    cin >> t;
    while(t--) {
        cin >> n >> e >> time;
        for(int i = 0;i < e;i++) {
            int x, y;
            double p;
            cin >> x >> y >> p;
            adj[x].push_back({y,p});
        }
        
        bfs(1, time);
        
        cout<<finalNode<<' '<< setprecision(6)<<fixed<< maxProbability << endl;
        
        for(int i = 1;i <= n;i++) adj[i].clear();
    }
    return 0;
}