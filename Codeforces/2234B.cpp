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
        i64 k; cin >> k;
        
        i64 x = k / 12, y = k % 12;
        
        if (y == 10) {
            if (x != 0) cout << "22 " << (x - 1) * 12 << "\n";
            else cout << "-1\n";
        } else
            cout << y << " " << x * 12 << "\n";
    }
}