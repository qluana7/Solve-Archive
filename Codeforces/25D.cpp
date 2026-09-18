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

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    disjoint_set dsu(n);
    
    vector<pair<int, int>> v;
    
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        
        if (!dsu.union_set(a - 1, b - 1))
            v.push_back({ a, b });
    }
    
    set<int> s;
    
    for (int i = 0; i < n; i++)
        s.insert(dsu.find(i) + 1);
        
    cout << s.size() - 1 << "\n";
    
    auto cur = s.begin();
    for (int i = 0; i < s.size() - 1; i++) {
        cout << v[i].first << " " << v[i].second << " " << *cur << " " << *next(cur) << "\n";
        cur++;
    }
}

/*

DSU를 통해서 도로를 건설할 때 두 도시를 union해준다. 이때, 이미 두 도시가 같은 그룹에 속해 있다면, 해당 도로를 따로 기록해둔다.
이후 DSU에서 distinct되는 그룹 목록을 가져와 기존에 중복되는 도로와 각 그룹과 그 다음 그룹을 차례대로 출력하여 두 도시를 이어준다.

*/