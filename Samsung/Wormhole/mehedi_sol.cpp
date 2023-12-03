
#include<iostream>
#include<climits>
using namespace std;
int w[35][5];
int mask[35];
int N;
int ans;

int dist(int sX, int sY, int dX, int dY){
    return abs(sX- dX) + abs(sY - dY);
}
void solve(int sX, int sY, int dX, int dY, int val){
    ans = min(ans, dist(sX, sY, dX, dY) + val);
    for(int i = 0; i < N; i++){
        if(mask[i] == 0){
            mask[i] = 1;

            int tmp = dist(sX, sY, w[i][0], w[i][1]) + w[i][4] + val;
            solve(w[i][2], w[i][3], dX, dY, tmp);

            tmp = dist(sX, sY, w[i][2], w[i][3]) + w[i][4] + val;
            solve(w[i][0], w[i][1], dX, dY, tmp);
            
            mask[i] = 0;
        }
    }
}



int main(){
    freopen("in.txt", "r", stdin);
    int testcase;
    cin>>testcase;
    while(testcase--){
        ans = INT_MAX;
        int sX, sY, dX, dY;
        cin>>N;
        cin>>sX>>sY>>dX>>dY;
        for(int i = 0; i < N; i++){
            mask[i] = 0;
            for(int j = 0; j < 5; j++){
                cin>>w[i][j];
            }
        }

        solve(sX, sY, dX, dY, 0);
        cout<<ans<<endl;
    }

    return 0;
}