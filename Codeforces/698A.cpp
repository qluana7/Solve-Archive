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
    
    int n; cin >> n;
    vector<int> v(n);
    for (auto& x : v) cin >> x;
    
    // 0 = none, 1 = gym, 2 = contest
    vector<array<int, 3>> table(n + 1);
    
    for (int i = 0; i < n; i++) {
        const auto& prev = table[i];
        auto& cur = table[i + 1];
        
        cur[0] = max({ prev[0], prev[1], prev[2] });
        
        switch (v[i]) {
            case 0: break;
            case 1:
                cur[2] = max({ prev[0], prev[1] }) + 1;
                break;
            case 2:
                cur[1] = max({ prev[0], prev[2] }) + 1;
                break;
            case 3:
                cur[1] = max({ prev[0], prev[2] }) + 1;
                cur[2] = max({ prev[0], prev[1] }) + 1;
                break;
        }
    }
    
    const auto& f = table.back();
    cout << n - max({ f[0], f[1], f[2] });
}

/*

쉬는 날을 최소화 = 쉬지 않는 날을 최대화. { rest, gym, contest }로 table을 정의하고, 이전 상태와 현재 가능한 것에 따라 table을 갱신. 최종 테이블에서 총 일 수에서 최대 쉬지 않은 날을 빼기.

*/