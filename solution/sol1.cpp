#include <bits/stdc++.h>
using namespace std;
int l, r;
int check(int n){
    long long total = 0;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            total += i;
            if (n / i != i){
                total += n / i;
            }
        }
        
    }
    
    total++;
    return total;
    
}
void solve(){
    cin >> l >> r;
    int cnt = 0;
    for (int i = l; i <= r; i++){
        cnt += (check(i) > i);
    }
    cout << cnt;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cin.tie(0);
    solve();
    return 0;
}