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

string ev(string&& str, int m) {
    for (int idx = 0; m; idx++) {
        int k = min(m, 9 - (str[idx] - '0'));
        
        str[idx] += k;
        
        m -= k;
    }
    
    return str;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    
    if (n * 9 < m) return !(cout << "-1 -1");
    if (n == 1) return !(cout << m << " " << m);
    if (m == 0) return !(cout << "-1 -1");
    
    string s(n, '0'); s.back() = '1';
    s = ev(move(s), m - 1);
    reverse(s.begin(), s.end());
    cout << s << " " << ev(string(n, '0'), m);
}

/*

불가능한 조건 : n * 9 < m인 경우, n이 1이 아닐 때, m이 0인 경우.
최대값은 '0'으로 채운 문자열에서 앞 인덱스부터 가능한한 최대로 만들어가며 만들 수 있으며,
최소값은 1의 자리를 1로 설정한 뒤 m - 1만큼에 대해 최대값 만들기를 수행 후, 뒤집으면 된다.

*/