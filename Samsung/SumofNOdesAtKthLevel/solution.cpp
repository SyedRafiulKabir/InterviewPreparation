#include<iostream>
#include<string.h>

using namespace std;

void solve(int level, string s) {
    int k = -1,sum = 0;
    for(int i = 0;i < s.length();i++) {
        if(s[i] == '(') k++;
        else if(s[i] == ')') k--;
        else if (k == level) {
            string tem = "";
            while(i < s.length() && isdigit(s[i])) {
                tem += s[i];
                i++;
            }
            i--;
            sum += stoi(tem);
        }
    }
    cout << sum <<endl;
}
int main() {
    freopen("in.txt" , "r", stdin);
    int k;
    cin >> k;
    string s;
    cin >> s;
    solve(k,s);
    return 0;
}