#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 5;
long long a[MAXN];
map<long long, long long> cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Đọc file nếu có
    if (fopen("khieuvu.inp", "r")) {
        freopen("khieuvu.inp", "r", stdin);
        freopen("khieuvu.out", "w", stdout);
    }

    int N;
    long long K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    long long result = 0;

    if (K == 0) {
        // Đếm các cặp có chiều cao bằng nhau
        for (auto &p : cnt) {
            long long x = p.second;
            result += x * (x - 1) / 2;
        }
    } else {
        // Đếm các cặp có chênh lệch chính xác bằng K
        for (auto &p : cnt) {
            long long h = p.first;
            if (cnt.count(h + K)) {
                result += p.second * cnt[h + K];
            }
        }
    }

    cout << result;
    return 0;
}
