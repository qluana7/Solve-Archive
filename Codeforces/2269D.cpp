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

constexpr bool cond(int k) {
    switch (k) {
        case 0: case 3: case 5: case 6: case 9: case 10: case 12: case 15: return true;
        default: return false;
    }
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    while (t --> 0) {
        int n, m; cin >> n >> m;
        
        int count = 0;
        
        vector<int> v(n);
        for (auto& x : v) cin >> x, count += cond(x);
        
        cout << count;
        
        while (m --> 0) {
            int a, b; cin >> a >> b; a--;
            
            count -= cond(v[a]); count += cond(b);
            v[a] = b;
            
            cout << " " << count;
        }
        
        cout << "\n";
    }
}
