#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#endif

using namespace std;

using u64 = unsigned long long;
using i64 = long long;

constexpr int INF = 2147483647;

int bt(const vector<pair<int, unsigned char>>& tb, int idx, int total, unsigned char cur) {
    auto [p, b] = tb[idx];
    
    total += p;
    cur |= b;
    
    if (cur == 7) return total;
    
    int mnt = INF;
    for (int i = idx + 1; i < tb.size(); i++) {
        if ((cur | tb[i].second) == cur) continue;
        
        mnt = min(mnt, bt(tb, i, total, cur));
    }
    
    return mnt;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    
    vector<pair<int, unsigned char>> v(n);
    for (auto& [p, b] : v) {
        string s; cin >> p >> s;
        
        for (auto x : s) b |= 1 << (x - 'A');
    }
    
    int mnt = INF;
    for (int i = 0; i < n; i++)
        mnt = min(mnt, bt(v, i, 0, 0));
    
    cout << (mnt == INF ? -1 : mnt);
}

/*

모든 비타민을 브루트하게 고르되, 고르는 비타민에 대해서 현재까지 고른 비타민을 모두 이미 가지고 있다면 스킵.

*/