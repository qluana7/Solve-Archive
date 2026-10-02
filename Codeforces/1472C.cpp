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

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    
    while (t --> 0) {
        int n; cin >> n;
        vector<int> v(n);
        for (auto& x : v) cin >> x;
        
        vector<bool> visited(n);
        vector<int> values(n);
        
        for (int i = 0; i < n; i++) {
            int nxt = i;
            
            while (nxt < n) {
                if (visited[nxt]) break;
                
                visited[nxt] = true;
                values[i] += v[nxt];
                nxt += v[nxt];
            }
        }
        
        cout << *max_element(values.begin(), values.end()) << "\n";
    }
}

/*

앞에서부터 탐색하되, 이미 앞에서 탐색했다면, 앞선 결과가 항상 더 높기 때문에, 더 탐색하지 않음. 이후 가장 큰 값을 선택.

*/