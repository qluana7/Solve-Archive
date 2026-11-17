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
    
    int k;
    while (cin >> k, k) {
        int s = 0; bool flag = true;
        
        while (k) {
            s += k % 10;
            
            if (!(k % 10 == 0 && flag)) {
                cout << k % 10;
                flag = false;
            }
            
            k /= 10;
        }
        
        cout << " " << s << "\n";
    }
}