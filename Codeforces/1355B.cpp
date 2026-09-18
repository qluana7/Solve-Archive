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
        
        sort(v.begin(), v.end(), greater<int>{});
        
        int g = 0;
        
        vector<int> table(n + 1);
        
        for (int i = 0; i < n; i++) {
            int next = i + v[i];
            
            if (next > n) continue;
            
            table[next] = max(table[next], table[i] + 1);
            
            g = max(g, table[next]);
        }
        
        cout << g << "\n";
    }
}

/*

그룹의 수를 최대화하기 위해서 가장 많은 인원을 필요로 하는 인원을 기준으로 많이 요구하는 순서대로 채워가며 그룹을 구성.
이때, 내림 차순으로 정렬 이후에, DP를 통해 최대 그룹을 구하기.

*/