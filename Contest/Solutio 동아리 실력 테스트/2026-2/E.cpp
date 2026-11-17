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
    vector<i64> v(n);
    for (auto& x : v) cin >> x;
    
    i64 d; cin >> d;
    
    i64 l = 0, r = 100000;
    
    // Parametic Binary Search
    while (l <= r) {
        i64 mid = l + r >> 1;
        
        i64 k = 0;
        for (auto x : v)
            k += min(x, mid);
            
        if (k < d) l = mid + 1;
        else r = mid - 1;
    }
    
    cout << l - 1;
}