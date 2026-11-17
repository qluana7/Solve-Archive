#include <iostream>
#include <set>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#endif

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    
    set<int> s;
    
    while (n --> 0) {
        int x; cin >> x;
        s.insert(x);
    }
    
    cin >> n;
    
    while (n --> 0) {
        int x; cin >> x;
        cout << s.count(x) << "\n";
    }
}