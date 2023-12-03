#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <climits>
#define pii pair<int,int>
using namespace std;

int n , mx , cnt , c;
int vis[20][20];

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

bool valid(int x , int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}

void bfs(int x, int y, vector<vector<int>> &adj){
    vis[x][y] = 1;
    queue < pii > q;
    q.push({x,y});

    while(!q.empty()){
        auto it = q.front();
        int u = it.first;
        int v = it.second;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int xx = u + fx[i];
            int yy = v + fy[i];

            if(valid(xx, yy) && adj[xx][yy] != 0 && vis[xx][yy] == 0 && cnt < c){
                vis[xx][yy] = vis[u][v] + 1;
                q.push({xx,yy});

                if(adj[xx][yy] == 2){
                    mx = max(mx, vis[xx][yy]);
                    cnt++;
                }
            }
        }
    }
}

int findLongestDist(int x, int y, vector<vector<int>> &adj){
    cnt = 0;
    mx = 0;
    memset(vis, 0, sizeof(vis));
    bfs(x, y, adj);
    return (cnt < c) ? INT_MAX : mx - 1;
}


int main(){
    freopen("in.txt","r",stdin);

    int tc, a, b, ans = INT_MAX , cs = 1;
    cin>>tc;

    while(tc--){
        cin>>n>>c;
        int rare[c+1][2];
        for(int i = 0 ; i < c; i++){
            cin>>a>>b;
            rare[i][0] = a - 1;
            rare[i][1] = b - 1;
        }
        vector<vector<int>> adj(n, vector<int>(n));
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < n ; j++){
                cin>>adj[i][j];
            }
        }
        for(int i = 0; i < c; i++){
            adj[rare[i][0]][rare[i][1]] = 2;
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(adj[i][j] != 0){
                    ans = min(ans, findLongestDist(i, j, adj));
                }
            }
        }

        cout<<'#'<<cs++<<": "<<ans<<endl;
        ans = INT_MAX;

    }
    return 0;
}