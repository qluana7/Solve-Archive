#include <iostream>
#include <vector>

#include <cmath>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#endif

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    
    vector<int> v { 1 };
    
    for (int i = 2; i < n; i++) {
        if (n % i == 0) v.push_back(i);
    }
    
    v.push_back(n);
    
    // 정답 코드
    cout << (m <= v.size() ? v[m - 1] : 0);
    
    // 테스트 당시 제출 코드
    // cout << v[m - 1];
}