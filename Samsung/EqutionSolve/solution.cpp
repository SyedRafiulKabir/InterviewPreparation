#include<iostream>
#include<cmath>
#define ll long long
//f(k) = a * k + b * k * log2(k) + c * k^3
using namespace std;
ll a,b,c,x;
ll eqn(int k) {
    return a * k + b * k * log2(k) + c * k * k * k;
}
int main() {
    freopen("input.txt", "r", stdin);
    cin>> a >> b >> c >> x;
    ll l = -x ,r = x ;
    
    while(l<=r) {
        ll mid = (l+r) / 2;
        if(eqn(mid) == x) {
            cout<<mid<<endl;
            break;
        }
        else if(eqn(mid) > x) {
            r = mid -1;
        }
        else {
            l = mid + 1;
        }
    }
    return 0;
}