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

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    
    map<i64, i64> m;
    while (n --> 0) {
        int k; cin >> k;
        
        m[k]++;
    }
    
    // 0 : not chosen, 1 : chosen
    vector<pair<i64, i64>> table(m.size() + 1);
    
    int i = 0, p = -1;
    for (const auto [k, c] : m) {
        const auto& prev = table[i];
        auto& cur = table[i + 1];
        
        cur.first = max(prev.first, prev.second);
        cur.second = prev.first + k * c;
        
        if (p + 1 != k)
            cur.second = max(cur.second, prev.second + k * c);
        
        p = k;
        i++;
    }
    
    auto [p1, p2] = table.back();
    cout << max(p1, p2);
}

/*

순서 중요 X. 따라서 x에 대한 개수를 기록하고, x를 고를때 인접하지 않으면서 합이 최대화되게 고르기. -> DP를 이용해 최대화.

*/