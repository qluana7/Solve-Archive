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
    vector<i64> v1(n), v2(n);
    for (auto& x : v1) cin >> x;
    for (auto& x : v2) cin >> x;
    
    // None, 1 Selected, 2 Selected
    vector<array<i64, 3>> table(n + 1);
    
    for (int i = 0; i < n; i++) {
        auto& cur = table[i + 1];
        const auto& prev = table[i];
        
        cur[0] = max({ prev[0], prev[1] + v1[i], prev[2] + v2[i] });
        cur[1] = max(prev[0], prev[2] + v2[i]);
        cur[2] = max(prev[0], prev[1] + v1[i]);
    }
    
    cout << ranges::max(table.back());
}

/*

연속되게 이어서 줄을 고르지 않는 상태에서 최대화 하기.

*/