#include <bits/stdc++.h>
using namespace std;
const int mod = 1005;
long long dp[mod][mod];
long long a[mod][mod];
int n,m;

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> dp[i][j]; 
            a[i][j] = dp[i][j]; 
        }
    }

    for (int i = 1; i <= n; i++){
        if (dp[i][1] == 0){
            continue;
        }
        else{
            dp[i][1] += dp[i - 1][1];
        }
    }

    for (int i = 1; i <= m; i++){
        if (dp[1][i] == 0){
            continue;
        }
        else{
            dp[1][i] += dp[1][i - 1];
        }
    }

    for (int i = 2; i <= n; i++){
        for (int j = 2; j <= m; j++){
            if (dp[i - 1][j] == 0 || dp[i][j - 1] == 0){
                continue;
            }
            else{
                long long tmp = max(dp[i - 1][j],dp[i][j - 1]);
                tmp += dp[i][j];
                dp[i][j] = tmp;
            }
        }
    }
    cout << (dp[n][m] != a[n][m])? dp[n][m] : 0;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}