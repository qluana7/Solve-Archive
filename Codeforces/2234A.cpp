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
    
    int t; cin >> t;
    
    while (t --> 0) {
        int n; cin >> n;
        
        vector<int> v(n);
        for (auto& x : v) cin >> x;
        sort(v.begin(), v.end(), greater<int>{});
        
        bool flag = [&v, n] {
            for (int i = 2; i < n; i++) {
                if (v[i - 2] % v[i - 1] != v[i]) return false;
            }
            
            return true;
        }();
        
        if (flag)
            cout << v[0] << " " << v[1] << "\n";
        else
            cout << "-1\n";
    }
}