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

struct edge {
    int a, b, cost;
};

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    
    while (t --> 0) {
        int n, m, k; cin >> n >> m >> k;
        disjoint_set dsu(n + 1);
        
        int l = 0, r = 2147483647;
        
        vector<edge> es(m);
        for (auto& [a, b, c] : es) {
            cin >> a >> b >> c;
            
            if (c <= k) l = max(l, c);
            if (k <= c) r = min(r, c);
        }
        
        if (k - l > r - k) swap(l, r);
        
        sort(es.begin(), es.end(), [] (const edge& a, const edge& b) {
            if (a.cost != b.cost) return a.cost < b.cost;
            else if (a.a != b.a) return a.a < b.a;
            else return a.b < b.b;
        });
        
        int ct = 0, mx = 0;
        auto cur = es.begin();
        
        while (true) {
            auto [a, b, c] = *cur;
            
            if (ct == n - 1) break;
            if (c > k) break;
            
            if (dsu.union_set(a, b)) {
                mx = max(mx, c);
                ct++;
            }
            
            cur++;
        }
        
        // If all paths are found
        if (ct == n - 1) {
            int mn = k - mx;
            for (; cur != es.end(); cur++)
                mn = min(mn, abs(cur->cost - k));
            
            cout << mn << "\n";
        } else {
            i64 sum = 0;
            
            while (ct < n - 1) {
                auto [a, b, c] = *cur;
                
                if (dsu.union_set(a, b)) {
                    sum += c - k;
                    ct++;
                }
                
                cur++;
            }
            
            cout << sum << "\n";
        }
    }
}

/*

입력으로 주어진 간선을 cost에 대해 오름차순 정렬한 뒤, k보다 작거나 같은 cost를 가진 간선을 모두 연결한다.
이때, union을 통해 이미 이어지지 않은 경우만 생각할 때, 간선이 n - 1에 도달했다면, 남은 간선 중 k와의 차이가 가장 적은 것이 답이다.
만약 간선이 부족하다면, 남은 간선에 대해 이어지지 않은 간선을 추가하며 cost - k의 합을 출력한다.

*/