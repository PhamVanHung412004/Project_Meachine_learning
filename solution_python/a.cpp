#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,x,y,z; 
string s;
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("STRMIN.INP","r", stdin);
    // freopen("STRMIN.OUT", "w", stdout);
    cin >> n >> x >> y >> z;
    for( int i = 0; i < z ; i++){
        s += to_string(i);
    }

    int z1 = 65;
    for ( int i = 0 ; i < x; i++){
        s += (char)z1;
        z1++;
    }
    int z2 = 97;
    for ( int i = 0 ; i < y; i++){
        s += (char)z2;
        z2++;
    }
    cout << s;
    return 0;
}