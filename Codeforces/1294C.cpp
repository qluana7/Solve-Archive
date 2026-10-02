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
        int k; cin >> k;
        
        [k] {
            for (int i = 2; i * i < k; i++) {
                if (k % i) continue;
                
                int k2 = k / i;
                for (int j = i + 1; j * j < k2; j++) {
                    if (k2 % j || i == k2 / j) continue;
                    
                    cout << "YES\n" << i << " " << j << " " << k2 / j << "\n";
                    return;
                }
            }
            
            cout << "NO\n";
        }();
    }
}

/*

a와 b를 결정하면 c는 자동적으로 결정된다. 따라서, a와 b를 탐색하면 된다. 이때, a는 최대 sqrt(n)까지 보면 되며, b는 sqrt(n / a)까지만 보면 되며, distinct하지 않은 경우 스킵한다.

*/