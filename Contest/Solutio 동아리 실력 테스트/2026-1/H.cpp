#include <iostream>
#include <vector>
#include <set>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#endif

using namespace std;

/*
풀이 1.
모든 인원에 대해 양방향 간선을 갖는 그래프 만들기

진실을 아는 사람에 대해 각각 dfs를 통해서 해당 인원이 참석하는 파티에 있는 인원들을 걸러냄

이후 다시 파티를 돌면서 걸러낸 인원이 한명이라도 포함되어있다면 continue;
그 외에 파티는 카운팅.
*/

bool known[51] = { false, };

void dfs(const vector<set<int>>& edge, bool* visit, int i) {
    visit[i] = true;
    known[i] = true;
    
    for (auto k : edge[i]) {
        if (visit[k]) continue;
        
        dfs(edge, visit, k);
    }
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n, m, k; cin >> n >> m >> k;
    
    // 진실을 아는 사람이 없다 = 모든 파티에 갈 수 있다.
    if (k == 0) return !(cout << m);
    
    vector<int> v(k);
    for (auto& x : v) cin >> x;
    
    vector<vector<int>> pts(m);
    vector<set<int>> edge(n + 1);
    
    for (auto& vx : pts) {
        int k; cin >> k;
        vx.resize(k);
        for (auto& x : vx) cin >> x;
        
        for (int i = 0; i < k; i++) {
            int p = vx[i];
            
            for (int j = 0; j < k; j++) {
                if (i == j) continue;
                edge[p].insert(vx[j]);
                edge[vx[j]].insert(p);
            }
        }
    }
    
    for (auto x : v) {
        bool visit[51] = { false, };
        
        dfs(edge, visit, x);
    }
    
    int cnt = 0;
    
    for (const auto& vx : pts) {
        bool flag = true;
        
        for (auto x : vx) {
            if (known[x]) {
                flag = false;
                break;
            }
        }
        
        cnt += flag;
    }
    
    cout << cnt;
}