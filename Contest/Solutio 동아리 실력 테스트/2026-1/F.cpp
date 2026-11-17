#include <iostream>
#include <vector>
#include <algorithm>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#endif

using namespace std;

int dnq(const vector<vector<int>>& vx, int s, int e, int idx, int dep) {
    if (e - s == 1) return dep - 1;
    
    vector<pair<int, int>> v;
    
    int st = s;
    int k = vx[st][idx];
    
    for (int i = s + 1; i < e; i++) {
        if (k == vx[i][idx]) continue;
        
        v.push_back({ st, i });
        st = i;
        k = vx[st][idx];
    } v.push_back({ st, e });
    
    if (v.size() == e - s) return dep;
    if (v.size() == 0) return dnq(vx, s, e, idx + 1, dep + 1);
    
    int mx = 0;
    
    for (auto [a, b] : v)
        mx = max(mx, dnq(vx, a, b, idx + 1, dep + 1));
    
    return mx;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n, mx = 0; cin >> n;
    vector<vector<int>> v(n);
    
    for (auto& vx : v) {
        int x;
        while (cin >> x, x != -1)
            vx.push_back(x);
            
        mx = max<int>(mx, vx.size());
    }
    
    for (auto& vx : v)
        vx.resize(mx, 0);
    
    sort(v.begin(), v.end(), [] (const vector<int>& v1, const vector<int>& v2) {
        for (int i = 0; i < v1.size(); i++)
            if (v1[i] != v2[i]) return v1[i] < v2[i];
        
        return v1.back() < v2.back();
    });
    
    cout << dnq(v, 0, v.size(), 0, 1);
}