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

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for (auto& [a, b] : v) cin >> a >> b;
    
    sort(v.begin(), v.end());
    
    for (auto [a, b] : v) cout << a << " " << b << "\n";
}