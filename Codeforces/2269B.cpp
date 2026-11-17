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

constexpr unsigned sumation(unsigned k) {
    unsigned r = 0;
    
    while (k) {
        unsigned tmp = k % 10;
        r += tmp * tmp;
        k /= 10;
    }
    
    return r;
}

array<int, 730> arr = [] consteval {
    array<int, 730> arr { 0, };
    
    for (unsigned i = 1; i < 730; i++) {
        unsigned cp = i, count = 0;
        
        while (true) {
            cp = sumation(cp);
            
            count++;
            if (cp == 1 || cp == 4) break;
        }
        
        if (cp == 1)
            arr[i] = -1;
        else if (cp == 4)
            arr[i] = count % 8;
    }
    
    return arr;
}();

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    
    while (t --> 0) {
        int n; cin >> n;
        vector<int> v(n);
        for (auto& x : v) {
            cin >> x;
            x = sumation(x);
        }
        
        int count = 0;
        
        for (int i = 0; i < v.size() - 1; i++) {
            for (int j = i + 1; j < v.size(); j++) {
                count += (arr[v[i]] == arr[v[j]]);
            }
        }
        
        cout << count << "\n";
    }
}