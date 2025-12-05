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

    string res = "";
    if (x == 0){
        int t = abs(n - y);
        if (t % 2 == 0){
            res += "01";
            int test = t / 2;
            test--;
            while(test--){
                res += "01";
            }
        }
        else{
            res += "01";
            int test = t / 2;
            test--;
            while(test--){
                res += "01";
            }
            res += '2';
        }
        for (int i = 0; i < y; i++){
            res += char_upper[i];
        }
    }
    else if (y == 0){
        int t = abs(n - x);
        if (t % 2 == 0){
            res += "01";
            int test = t / 2;
            test--;
            while(test--){
                res += "01";
            }
        }
        else{
            res += "01";
            int test = t / 2;
            test--;
            while(test--){
                res += "01";
            }
            res += '2';
        }
        for (int i = 0; i < x; i++){
            res += char_lower[i];
        }
    }
    else if (z == 0){
        int t = abs(n - y);
        if (t % 2 == 0){
            res += "AB";
            int test = t / 2;  
            test--;
            while(test--){
                res += "AB";
            }
        }
        else{
            res += "AB";
            int test = t / 2;  
            test--;
            while(test--){
                res += "AB";
            }
            res += 'C';
        }
        for (int i = 0; i < y; i++){
            res += char_upper[i];
        }
    }
    else{
        if (x + y + z == n){
            for (int i = 0; i < z; i++){
                res += char_number[i];
            }

            for (int i = 0; i < x; i++){
                res += char_lower[i];
            }

            for (int i = 0; i < y; i++){
                res += char_upper[i];
            }
        }
        else{
            int t = x + y + z;
            int test = n - t;

            for (int i = 0; i < z; i++){
                res += char_number[i];
            }
            int i = z;
            if (test % 2 == 0){
                int ttt = 2;
                string s_tmp = "";
                while(ttt--){
                    res += char_number[i];
                    s_tmp += char_number[i];
                    i++;
                }
                int tt = test / 2;
                tt--;
                while(tt--){
                    res += s_tmp;
                }
            }
            else{
                int ttt = 2;
                string s_tmp = "";
                while(ttt--){
                    res += char_number[i];
                    s_tmp += char_number[i];
                    i++;
                }
                int tt = test / 2;
                tt--;
                while(tt--){
                    res += s_tmp;
                }

                res += char_number[i++];
            }

            for (int i = 0; i < x; i++){
                res += char_lower[i];
            }

            for (int i = 0; i < y; i++){
                res += char_upper[i];
            }
        }
    }

    cout << res;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}