#include<iostream>
#include<vector>

using namespace std;
int n, m = 5, ans = 0;
vector<vector<int>> arr;
void printarr() {
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}
void solve (int row, int col, bool bombUsed, int rowleft, int coin) {
    if(!isValid(row,col)) {
        ans = max(ans, coin);
        return;
    }
    if(arr[row][col] == 0 || arr[row][col] == 1) {
        if(arr[row][col] == 1) coin++;
        if(bombUsed) rowleft--;
        solve(row - 1, col - 1, bombUsed, rowleft, coin);
        solve(row - 1, col, bombUsed, rowleft, coin);
        solve(row - 1, col + 1, bombUsed, rowleft, coin);
    }
    else if(arr[row][col] == 2) {
        if(bombUsed) {
            if(rowleft > 0) {
                rowleft--;
                solve(row - 1, col - 1, bombUsed, rowleft, coin);
                solve(row - 1, col, bombUsed, rowleft, coin);
                solve(row - 1, col + 1, bombUsed, rowleft, coin);
            }
            else {
                ans = max(ans, coin);
                return;
            }
        }
        else {
            bombUsed = true;
            rowleft = 5;
            solve(row - 1, col - 1, bombUsed, rowleft, coin);
            solve(row - 1, col, bombUsed, rowleft, coin);
            solve(row - 1, col + 1, bombUsed, rowleft, coin);
        }
    }

}
int main() {
    freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    for(int no = 1;no <= t;no++) {
        cin >> n;
        vector<int> tem;
        for(int i = 0;i < n;i++) {
            int num;
            for(int j = 0;j < m;j++) {
                cin >> num;
                tem.push_back(num);
            }
            arr.push_back(tem);
            tem.clear();
        }
        //printarr();
        solve(n - 1, 1, false, 0, 0);
        solve(n - 1, 2, false, 0, 0);
        solve(n - 1, 3, false, 0, 0);


        cout<<"#"<<no<<" "<<ans<<endl;
        arr.clear();
        ans = 0;
    }
    return 0;
}