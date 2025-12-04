#include <bits/stdc++.h>
using namespace std;
const int mod = 1005;
long long dp[mod][mod];
int n,m;

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> dp[i][j]; 
        }
    }

    for (int i = 1; i <= n; i++){
        dp[i][1] += dp[i - 1][1];
    }

    for (int i = 1; i <= m; i++){
        dp[1][i] += dp[1][i - 1];
    }

    for (int i = 2; i <= n; i++){
        for (int j = 2; j <= m; j++){
            long long res = max(dp[i - 1][j],dp[i][j - 1]);
            res = max(res,dp[i - 1][j - 1]);
            dp[i][j] += res;
        }
    }
    cout << dp[n][m];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();

    return 0;
}