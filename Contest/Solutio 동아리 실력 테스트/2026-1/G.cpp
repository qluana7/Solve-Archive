#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#endif

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    while (n --> 0) {
        int m; cin >> m;
        vector<int> v(m);
        for (auto& x : v) cin >> x;
        
        sort(v.begin(), v.end(), greater<int>{});
        
        deque<int> dq;
        
        bool flag = false;
        for (int i = 0; i < m; i++) {
            if (flag) dq.push_back(v[i]);
            else dq.push_front(v[i]);
            
            flag ^= true;
        }
        
        int mx = 0;
        auto b = dq.begin();
        for (int i = 0; i < m; i++) {
            auto e = next(b);
            if (e == dq.end()) e = dq.begin();
            
            mx = max(mx, abs(*b - *e));
            b = e;
        }
        
        cout << mx << "\n";
    }
}