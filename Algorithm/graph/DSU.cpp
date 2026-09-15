/*
 * Algorithm Name : Disjoint Set | Union Find
 *
 * Description
 * 
 * Disjoint Set, Union Find란?
 *   - 서로소 집합을 관리하는 자료구조.
 *   - Union을 통해서 두 서로소 집합을 묶어주며, Find를 통해 어떠한 두 원소에 대해 같은 집합에 속하였는지를 판별.
 * 
 * 구현?
 *   - 각 원소가 어떠한 집합에 속하는 원소를 가리키게 함으로서 해당 집합에 속함을 나타냄.
 *   - 두 원소가 같은 집합에 있는지 확인할 땐, 해당 원소가 가리키는 번호를 통해 같은 곳을 가리키는지 확인.
 * 
 * 최적화?
 *   - 단순히 원소를 이어붙이게 되면, 편향된 트리가 생기며, 이 경우 재귀를 사용하기 때문에 최악의 경우 O(n)이 걸린다.
 *   - 따라서 다음과 같은 최적화를 적용한다.
 * 
 * 1. 경로 압축 최적화
 *   - 어떠한 원소가 해당 집합을 찾을 때, 해당 원소를 해당 집합의 root에 다시 배치해주는 방식.
 *   - 이를 통해 편향 트리를 spread 시켜 트리의 높이가 낮아짐. 따라서 find 연산이 거의 O(1) 수준에 달하게 됨.
 * 
 * 2. Union-by-size
 *   - 어떠한 두 집합을 합칠 때, 더 많은 depth를 가진 집합에 더 적은 depth를 가진 집합을 합치는 방식.
 *   - DSU는 기본적으로 tree의 최대 depth가 시간복잡도에 관여하게 되는데, 이때, 두 집합을 합치는 과정에서
 *     작은 집합에 큰 집합을 결합하면 root 노드 밑에 이전 root를 붙이는 꼴이 되기 때문에, 최대 높이가 항상 1씩 증가하는 문제가 발생
 *   - 이를 해결하기 위해, 항상 큰 집합에 작은 집합을 결합함으로서, 두 집합의 depth가 같을때만 depth가 증가하므로, 이를 최적화 할 수 있음.
 * 
 * 어디에 쓰는가?
 *   - 두 원소가 다른 집합에 속하는지를 판단하는 것을 이용하여, 다음과 같은 것들을 할 수 있다.
 * 
 * 1. 그래프 사이클 판별 : 원소가 속하는 집합을 업데이트 하면서, 탐색시에 이미 같은 집합에 속함이 확인된다면 사이클이 존재함을 알 수 있음.
 * 2. MST(Minimal Spanning Tree) : Kruskal 알고리즘을 사용시, 사이클 판별에 이용할 수 있음.
 * 3. 서로소 집합 관리 : 두 기기가 같은 네트워크에 속하는가?, 두 사람이 같은 조직에 속하는가? 와 같은 문제를 해결하는데 사용할 수 있음.
 * 
 * Reference
 *   - https://devkuk.tistory.com/27
 *   - https://nologic-07.tistory.com/entry/Union-Find-%EA%B0%9C%EC%84%A0%EB%B2%95-union-by-size-%EA%B2%BD%EB%A1%9C-%EC%95%95%EC%B6%95
 * 
 */

#include <vector>
 
using namespace std;

template <typename T = int>
struct disjoint_set {
    vector<T> table, rank;
    
    disjoint_set() = default;
    disjoint_set(const disjoint_set&) = default;
    disjoint_set(disjoint_set&&) = default;
    disjoint_set(T size) {
        table = vector<T>(size);
        rank = vector<T>(size);
        
        for (T i = 0; i < size; i++)
            table[i] = i;
    }
    
    bool union_set(T a, T b) {
        int ga = find(a), gb = find(b);
        
        if (ga == gb) return false;
        
        if (rank[ga] > rank[gb]) swap(ga, gb);
        table[ga] = gb;
        if (rank[ga] == rank[gb]) rank[gb]++;
        
        return true;
    }
    
    T find(T n) {
        if (table[n] == n) return n;
        
        return table[n] = find(table[n]);
    }
};