#include <bits/stdc++.h>
using namespace std;
const int mod = 1e5 + 5;
long long n, q;
long long a[mod];

int lower(int val, int l, int r){
    int ans = - 1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if (a[mid] == val){
            ans = mid;
            r = mid - 1;
        }
        else if (a[mid] < val){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }

    }   
    return ans;
}

int upper(int val, int l, int r){
    int ans = - 1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if (a[mid] == val){
            ans = mid;
            l = mid + 1;
        }
        else if (a[mid] < val){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }   
    return ans;
}


void solve(){
    cin >> n >> q;

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);

    long long cnt = 0;
    for (int i = 0; i < n; i++){
        int val = a[i] + q;
        long long l = lower(val,i + 1, n);
        long long r = upper(val,i + 1, n);
        if (l != -1 && r != -1){
            cnt += (r - l + 1);
        }
    }
    cout << cnt;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cin.tie(0);
    freopen("khieuvu.inp","r", stdin);
    freopen("khieuvu.out", "w", stdout);
    solve();
    return 0;
}
