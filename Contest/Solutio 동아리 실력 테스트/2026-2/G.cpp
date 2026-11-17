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
    
    vector<vector<int>> v(n, vector<int>(n));
    
    for (auto& vs : v) for (auto& x : vs) cin >> x;
    
    int k = 0, total = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(n);
    while (n --> 1) {
        for (int i = 0; i < v.size(); i++) {
            if (i == k) continue;
            
            pq.push({ v[k][i], i });
        }
        
        while (!pq.empty()) {
            auto [cost, vertex] = pq.top(); pq.pop();
            
            if (visited[vertex]) continue;
            
            total += cost;
            visited[vertex] = true;
            k = vertex;
            break;
        }
    }
    
    cout << total;
}