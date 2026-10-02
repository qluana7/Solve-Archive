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

template <typename T = int>
struct disjoint_set {
    vector<T> table, rank;
    
    disjoint_set() = default;
    disjoint_set(const disjoint_set&) = default;
    disjoint_set(disjoint_set&&) = default;
    disjoint_set(T size) {
        table = vector<T>(size);
        rank = vector<T>(size);
        
        for (T i = 0; i < size; i++)
            table[i] = i;
    }
    
    bool union_set(T a, T b) {
        int ga = find(a), gb = find(b);
        
        if (ga == gb) return false;
        
        if (rank[ga] > rank[gb]) swap(ga, gb);
        table[ga] = gb;
        if (rank[ga] == rank[gb]) rank[gb]++;
        
        return true;
    }
    
    T find(T n) {
        if (table[n] == n) return n;
        
        return table[n] = find(table[n]);
    }
};

struct vertex {
    int x, y;
    i64 cost;
};

struct edge {
    int a, b;
    i64 cost;
};

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<vertex> vts(n);
    vector<i64> ks(n);
    
    for (auto& [x, y, c] : vts) cin >> x >> y;
    for (auto& [x, y, c] : vts) cin >> c;
    for (auto& x : ks) cin >> x;
    
    priority_queue<pair<i64, pair<int, int>>> pq;
    for (int i = 0; i < n; i++)
        pq.push({ -vts[i].cost, { i + 1, -1 } });
    
    vector<int> r_vt; vector<pair<int, int>> r_eg;
    i64 cost = 0;
    disjoint_set dsu(n + 1);
    
    for (int i = 0; i < n;) {
        auto [c, p] = pq.top(); pq.pop();
        auto [a, b] = p;
        
        if (b == -1) {
            if (dsu.find(a) == dsu.find(0)) continue;
            
            dsu.union_set(a, 0);
            cost += c;
            r_vt.push_back(a);
        } else {
            if (
                dsu.find(a) == dsu.find(0) &&
                dsu.find(b) == dsu.find(0)
            ) continue;
            
            dsu.union_set(a, b);
            cost += c;
            r_eg.push_back({ a, b });
            
            swap(a, b);
        }
        
        for (int j = 1; j <= n; j++) {
            if (a == j || dsu.find(a) == dsu.find(j)) continue;

            auto [x1, y1, c1] = vts[a - 1];
            auto [x2, y2, c2] = vts[j - 1];

            pq.push({ -(abs(x1 - x2) + abs(y1 - y2)) * (ks[a - 1] + ks[j - 1]), { a, j } });
        }
        
        i++;
    }
    
    cout << -cost << "\n" << r_vt.size() << "\n";
    for (auto x : r_vt) cout << x << " ";
    cout << "\n" << r_eg.size() << "\n";
    for (auto [a, b] : r_eg) cout << a << " " << b << "\n";
}

/*

MST의 Prim’s Algorithm을 응용하여, 간선 뿐만 아니라 vertex도 우선순위에 추가.
이때, 전기가 공급된 도시는 가상의 노드인 0번 노드와 연결하여, 간선을 잇거나 노드를 고를때, DSU를 통해 전기가 공급되었는지 판단.
간선과 vertex의 개수는 총 N개가 되어야 하기 때문에, continue하는 경우를 제외하고 총 N개가 될때까지 반복.

*/