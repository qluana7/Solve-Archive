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
    
    bitset<100> bs;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        bs[i] = x;
    }
    
    if (bs.count() == n) return !(cout << n - 1);
    
    int mx = 0;
    
    for (int i = 0; i < n; i++) {
        if (bs[i] == 1) continue;
        
        bitset<100> tmp = bs;
        
        for (int j = i; j < n; j++) {
            tmp[j].flip();
            
            mx = max<int>(mx, tmp.count());
        }
    }
    
    cout << mx;
}

/*

N <= 100이므로, 브루트포스로 실제로 뒤집고 개수를 세는 방식으로 해결. bitset을 이용하여 개수 세는 것을 일부 최적화.

*/