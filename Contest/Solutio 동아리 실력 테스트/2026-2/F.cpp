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

vector<int> table;
int ed;

int rec(int st) {
    // Invalid
    if (st + 1 > ed) return 0;
    
    // 정할 자리가 2개라면? => 2 (바꾼다/안바꾼다)
    if (st + 1 == ed) return 1;
    
    // 이미 캐시된게 있다면?
    if (table[st] != 0) return table[st];
    
    // st와 st + 1을 바꾼다면?
    int k1 = rec(st + 2);
    
    // st와 st + 1을 바꾸지 않는다면?
    int k2 = rec(st + 1);
    
    return table[st] = k1 + k2;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    
    int s = 0, total = 1;
    
    vector<int> ps(m);
    for (auto& x : ps) cin >> x;
    ps.push_back(n + 1);
    
    // 고정석을 기준으로 각각 계산.
    // 이후 곱하여 최종 계산.
    for (auto e : ps) {
        int k = e - s - 1;
        
        ed = k + 1;
        table = vector<int>(k);
        total *= rec(1) + 1;
        
        s = e;
    }
    
    cout << total;
}