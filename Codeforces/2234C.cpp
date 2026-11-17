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
    
    while (n --> 0) {
        int k; cin >> k;
        
        vector<i64> h(k);
        for (auto& x : h) cin >> x;
        
        vector<vector<i64>> v(k, vector<i64>(k));
        
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k - 1; j++) {
                int idx = (i + j) % k;
                
                v[i][(i + j + 1) % k] =
                    max(v[i][idx], h[idx]);
            }
        }
        
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                v[i][j] = v[j][i] = min(v[i][j], v[j][i]);
            }
        }
        
        for (const auto& vx : v) {
            i64 p = 0;
            for (auto x : vx) p += x;
            
            cout << p << " ";
        }
        
        cout << "\n";
    }
}