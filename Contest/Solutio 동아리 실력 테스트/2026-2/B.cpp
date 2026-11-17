#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <bitset>

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
    
    vector<tuple<int, int, int>> v(n);
    
    for (int i = 0; i < n; i++) {
        auto& [idx, a, b] = v[i];
        
        idx = i;
        cin >> a >> b;
    }
    
    sort(v.begin(), v.end(), [] (const auto& a, const auto& b) {
        const auto& [a1, a2, a3] = a;
        const auto& [b1, b2, b3] = b;
        
        int df1 = a3 - a2, df2 = b3 - b2;
        
        
        if (df1 != df2)
            return df1 < df2;
        else
            return a2 < b2;
    });
    
    for (auto [idx, _1, _2] : v)
        cout << idx + 1 << "\n";
}