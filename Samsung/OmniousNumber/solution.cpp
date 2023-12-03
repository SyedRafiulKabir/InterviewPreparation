#include<iostream>

using namespace std;
bool omniousNum(int n) {
    int x;
    while(n) {
        if(n % 10 == 1 || n % 10 == 3 || n % 10 == 5) x++;
        if(x >= 3) return false;
        n /= 10;
    }
    return true;
}
int main() {
    freopen("in.txt", "r", stdin);
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>> n;
        cout<<omniousNum(n)<<endl;
    }
    
    return 0;
}