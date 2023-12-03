
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <iomanip>
#define pd pair<int,double>
using namespace std;

unordered_map < int , bool > vis;
unordered_map < int , double > probablility;

double maxProb;
int node;
vector < pd > adj[100];

void bfs(int s , int duration){
    vis[s] = 1;
    queue < int > q;
    q.push(s);
    vis.clear();
    probablility.clear();

    probablility[s] = 1;

    while(!q.empty()){
        
        int sz = q.size();

        maxProb = 0;

        while(sz--){
            int u = q.front();
            q.pop();

            for(int i = 0 ; i <  adj[u].size(); i++){
                int v = adj[u][i].first;
                double w = adj[u][i].second;

                if(u == v)
                    continue;

                if(vis[v] == 0)
                    q.push(v) , vis[v] = 1;

                probablility[v] = probablility[v] + w * probablility[u];
                if(maxProb < probablility[v])
                    maxProb = probablility[v] , node = v;

            }
        }

        duration -= 10;

        if(duration <= 0)
            break;
    }
}

int main(){
    freopen("in.txt","r",stdin);

    int i , j , n , t , e , duration , x , y;
    double prob;
    cin>>t;

    while(t--){
        cin>>n>>e>>duration;

        for(i = 0; i < e ; i++){
            cin>>x>>y>>prob;
            adj[x].push_back({y,prob});
        }

        bfs(1,duration);

        for(i = 1 ; i <= n ; i++){
            adj[i].clear();
        }
        
        cout<<node<<' '<<setprecision(6)<<fixed<<maxProb<<endl;

    }
    return 0;
}