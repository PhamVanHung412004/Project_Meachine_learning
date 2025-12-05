#include <bits/stdc++.h>
using namespace std;
const int mod = 3 * 1e6 + 5;
int l, r;
long long dp[mod];

void check(int n){
    for (int i = 1; i <= n; i++){
        dp[i] = 1;
    }
    dp[1] = 0;
    for (int i = 2; 2 * i <= n; i++){
        for (int j = 2 * i; j <= n; j += i){
            dp[j] += i;
        }
    }
}

void solve(){
    cin >> l >> r;
    check(r);
    int cnt = 0;
    for (int i = l; i <= r; i++){
        cnt += (dp[i] > i);
    }
    cout << cnt;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cin.tie(0);
    freopen("SPECIAL.INP","r", stdin);
    freopen("SPECIAL.OUT", "w", stdout);
    solve();
    return 0;
}