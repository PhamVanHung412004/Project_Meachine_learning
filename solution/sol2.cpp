#include <bits/stdc++.h>
using namespace std;

vector<char> char_number,char_lower,char_upper;

void solve(){
    int n;
    cin >> n;
    int x, y, z; cin >> x >> y >> z;
    /*
    so: 48 -> 57
    chu hoa: 65 -> 90
    chu thuong: 97 -> 122
    */

    for (int i = 48; i <= 57; i++){
        char_number.push_back((char)i);
    }

    for (int i = 65; i <= 90; i++){
        char_lower.push_back((char)i);
    }

    for (int i = 97; i <= 122; i++){
        char_upper.push_back((char)i);
    }
    string ans = "";
    for (int i = 0; i < z; i++){
        ans += char_number[i];
    }

    for (int i = 0; i < x; i++){
        ans += char_lower[i];
    }

    for (int i = 0; i < y; i++){
        ans += char_upper[i];
    }
    cout << ans;


}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}