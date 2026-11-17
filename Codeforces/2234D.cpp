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
        int n, k; cin >> n >> k;
        
        string a, b; cin >> a >> b;
        
        i64 ax = 0, bx = 0, abx = 0;
        for (int i = 0; i < n; i++) {
            ax += a[i] == '1';
            bx += b[i] == '1';
            abx += a[i] != b[i];
        }
        
        i64 ac = ax * (n - ax), bc = bx * (n - bx), abc = abx * (n - abx);
        
        // x = A, B; y = AB;
        i64 x = 1, y = 1, pw = 2;
        
        while (k --> 1) {
            x += y;
            pw *= 2;
            y = pw + 1 - x * 2;
        }
        
        cout << ac * x + bc * x + abc * y << "\n";
    }
}