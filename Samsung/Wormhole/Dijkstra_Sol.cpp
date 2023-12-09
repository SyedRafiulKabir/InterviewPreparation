#include<iostream>
#include<unordered_map>
#include<climits>
#include<vector>
#include<queue>
#define pii pair<int,int>
using namespace std;
unordered_map<int , vector<int>> adj;
int dijkstra(int n) {
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,0});
    vector<int> dis(n, INT_MAX);
    dis[0] = 0;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int node=it.second;
        for(int i=0;i<adj[node].size();i++) {
            if(dis[node] + adj[i][node] < dis[i]) {
                dis[i] = dis[node] + adj[i][node];
                pq.push({dis[i], i});
            }
        }
    }
    return dis[n-1];
}
void init(int n) {
    for(int i = 0;i < n;i++) adj[i].clear();

}
int main() {
    freopen("in.txt","r",stdin);
    int test;
    cin>>test;
    while(test--){
        int w;
        cin >> w;
        int n = 2*(w+1);
        init(n);
        int x[n],y[n],cost[n];
        cin>>x[0]>>y[0]>>x[n-1]>>y[n-1];
        cost[0]=0;
        cost[n-1]=0;
        for(int i=1;i < n-1;i+=2) {
            cin>>x[i]>>y[i]>>x[i+1]>>y[i+1]>>cost[i];
            cost[i+1] = cost[i];
        }
        for(int i=0;i<n;i++) {
            int d1 = abs(x[0]-x[i]) + abs(y[0]-y[i]);
            int d2 = abs(x[n-1]-x[i]) + abs(y[n-1]-y[i]);
            adj[0].push_back(d1);
            adj[n-1].push_back(d2);
        }
        for(int i=1;i<n-1;i++) {
            for(int j=0;j<n;j++) {
                if(i==j) {
                    adj[i].push_back(0);
                }
                else{
                    int val;
                    if(1 & i) {
                        val = abs(x[i+1]-x[j]) + abs(y[i+1]-y[j]) + cost[i];
                    }
                    else{
                        val = abs(x[i-1]-x[j]) + abs(y[i-1]-y[j]) + cost[i];
                    }
                    adj[i].push_back(val);
                }
            }
        }

        cout<<dijkstra(n)<<endl;
    }
    return 0;
}