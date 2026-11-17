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
    
    vector<string> v(n);
    vector<vector<int>> table(n, vector<int>(n));
    vector<int> result;
    int total = 0;
    
    for (auto& s : v) cin >> s;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == '0' || table[i][j] != 0) continue;
            
            // Found new one.
            total++;
            
            int size = 0;
            queue<pair<int, int>> q;
            q.push({ i, j });
            
            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                
                if (table[x][y]) continue;
                
                table[x][y] = total;
                size++;
                
                if (x < n - 1 && v[x + 1][y] == '1') q.push({ x + 1, y });
                if (y > 0 && v[x][y - 1] == '1') q.push({ x, y - 1 });
                if (y < n - 1 && v[x][y + 1] == '1') q.push({ x, y + 1 });
                if (x > 0 && v[x - 1][y] == '1') q.push({ x - 1, y });
            }
            
            result.push_back(size);
        }
    }
    
    cout << result.size() << "\n";
    for (auto x : result) cout << x << "\n";
}