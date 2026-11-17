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
    
    map<i64, i64> xc, yc;
    
    while (n --> 0) {
        i64 a, b; cin >> a >> b;
        
        xc[a]++; yc[b]++;
    }
    
    i64 s = 0;
    
    for (auto [a, b] : xc) {
        if (b < 2) continue;
        
        i64 sum = 0;
        for (int i = 1; i < b; i++)
            sum += i;
        
        s += sum;
    }
    
    for (auto [a, b] : yc) {
        if (b < 2) continue;
        
        i64 sum = 0;
        for (int i = 1; i < b; i++)
            sum += i;
        
        s += sum;
    }
    
    cout << s;
}