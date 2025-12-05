#include <bits/stdc++.h>
using namespace std;

struct Elem {
    long long val;
    int pos;
};

struct Query {
    long long k;
    int id;
};

const int MAXN = 1000000 + 5;

int parentDSU[MAXN];
int szDSU[MAXN];
bool activePos[MAXN];

int Find(int x) {
    if (parentDSU[x] == x) return x;
    return parentDSU[x] = Find(parentDSU[x]);
}

void Unite(int a, int b, int &curMax) {
    a = Find(a);
    b = Find(b);
    if (a == b) return;
    if (szDSU[a] < szDSU[b]) swap(a, b);
    parentDSU[b] = a;
    szDSU[a] += szDSU[b];
    curMax = max(curMax, szDSU[a]);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("SEQ.INP","r", stdin);
    freopen("SEQ.OUT", "w", stdout);

    int n, Q;
    cin >> n >> Q;

    vector<long long> a(n + 1);
    vector<Elem> elems(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        elems[i - 1] = {a[i], i};
    }
    sort(elems.begin(), elems.end(),
         [](const Elem &x, const Elem &y) { return x.val < y.val; });

    vector<Query> queries(Q);
    for (int i = 0; i < Q; ++i) {
        long long k;
        cin >> k;
        queries[i] = {k, i};
    }
    sort(queries.begin(), queries.end(),
         [](const Query &x, const Query &y) { return x.k < y.k; });

    for (int i = 0; i <= n + 1; ++i) {
        parentDSU[i] = i;
        szDSU[i] = 1;
        activePos[i] = false;
    }

    vector<int> ans(Q);
    int ptr = 0;        
    int curMax = 0;  

    for (const auto &q : queries) {
        long long k = q.k;
        while (ptr < n && elems[ptr].val <= k) {
            int pos = elems[ptr].pos;
            activePos[pos] = true;
            parentDSU[pos] = pos;
            szDSU[pos] = 1;

            if (pos > 1 && activePos[pos - 1]) {
                Unite(pos, pos - 1, curMax);
            }

            if (pos < n && activePos[pos + 1]) {
                Unite(pos, pos + 1, curMax);
            }

            curMax = max(curMax, szDSU[Find(pos)]);
            ++ptr;
        }

        ans[q.id] = curMax;
    }

    for (int i = 0; i < Q; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}
