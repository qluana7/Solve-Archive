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

using pii = pair<int, int>;

struct tup {
    int first, second;
    
    int value;
};

constexpr int INF = 2147483647;

vector<vector<pii>> edges;
int max_node;

struct pq_cmp {
    bool operator() (const tup& a, const tup& b) {
        return a.second > b.second;
    }
};

pair<int, int> dijkstra(int start, int end) {
    vector<pair<int, int>> v(max_node, { INF, 0 });
    
    priority_queue<tup, vector<tup>, pq_cmp> pq;
    pq.emplace(start, 0, 0);
    v[start - 1] = { 0, 0 };
    
    while (!pq.empty()) {
        auto x = pq.top(); pq.pop();
        
        if (v[x.first - 1].first < x.second) continue;
        
        for (const pii& p : edges[x.first - 1]) {
            int d = x.second + p.second;
            if (d < v[p.first - 1].first) {
                v[p.first - 1].first = d;
                v[p.first - 1].second = max({
                    v[p.first - 1].second, x.value, p.second
                });
                pq.emplace(p.first, d, max(x.value, p.second));
            }
        }
    }
    
    
    return v[end - 1];
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n, a, b; cin >> n >> a >> b;
    max_node = n;
    
    edges = vector<vector<pii>>(n);
    
    while (n --> 1) {
        int p, q, d; cin >> p >> q >> d;
        
        edges[p - 1].push_back({ q, d });
        edges[q - 1].push_back({ p, d });
    }
    
    for (auto& egs : edges)
        sort(egs.begin(), egs.end());
    
    auto [cost, mx] = dijkstra(a, b);
    
    cout << cost - mx;
}