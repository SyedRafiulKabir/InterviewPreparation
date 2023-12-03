#include<iostream>
#include<string.h>
#include<climits>
using namespace std;
int ans = INT_MIN;

void printarr(int arr[][5],int n,int m) {
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void solve(int arr[][5], int row, int col, bool bombUsed, int rowleft, int coins) {
    if(row < 0 || col < 0 || col >= 5) {
        ans = max(ans, coins);
        return;
    }
    if(arr[row][col] == 0 || arr[row][col] == 1) {
        if(arr[row][col] == 1) coins++;
        if(bombUsed) rowleft--;
        solve(arr, row - 1, col - 1, bombUsed, rowleft, coins);
        solve(arr, row - 1, col, bombUsed, rowleft, coins);
        solve(arr, row - 1, col + 1, bombUsed, rowleft, coins);
    }
    else if(arr[row][col] == 2) {
        if(bombUsed) {
            if(rowleft > 0) {
                rowleft--;
                solve(arr, row - 1, col - 1, bombUsed, rowleft, coins);
                solve(arr, row - 1, col, bombUsed, rowleft, coins);
                solve(arr, row - 1, col + 1, bombUsed, rowleft, coins);
            }
            else {
                ans = max(ans, coins);
                return;
            }
        }
        else {
            bombUsed = true;
            rowleft = 5;
            solve(arr, row - 1, col - 1, bombUsed, rowleft, coins);
            solve(arr, row - 1, col, bombUsed, rowleft, coins);
            solve(arr, row - 1, col + 1, bombUsed, rowleft, coins);
        }

    }
}
int main() {
    freopen("input.txt","r",stdin);
    int testcase;
    cin >> testcase;
    for(int t = 1;t <= testcase;t++) {
        int n, m = 5;
        cin >> n;
        int arr[n][5];
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cin >> arr[i][j]; 
            }
        }
        //printarr(arr,n,m);
        solve(arr, n - 1, 1, false, 0, 0);
        solve(arr, n - 1, 2, false, 0, 0);
        solve(arr, n - 1, 3, false, 0, 0);
        cout<<"#"<<t<<" "<<ans<<endl;
        ans = INT_MIN;
    }
    return 0;
}