/*
 * Algorithm Name : MST (Minimum Spanning Tree) | Kruskal's Algorithm
 *
 * Description
 *    - MST (Minimum Spanning Tree) 구현
 *    - Kruskal's Algorithm을 이용한 구현
 * 
 *    - 각 가중치를 정렬하고 그리디 알고리즘으로
 *    - 간선을 선택해 나가며 트리를 구성하는 구조
 * 
 *    - 사이클 판단에는 Union Find 가 사용됨
 * 
 * How to do
 * 1. 간선을 오름차순 정렬
 * 2. 정렬된 간선을 차례대로 선택.
 *    이 때, 사이클을 이루는 간선을 선택해서는 안됨.
 *    가중치가 같은 간선이 여러개라면, 아무거나 선택
 * 3. 간선의 갯수가 정점 - 1개가 되면 종료
 * 
 * Reference
 *    - https://chanhuiseok.github.io/posts/algo-33/
 */

#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    int start, end;
    
    int cost;
};

int head(vector<int>& v, int idx) {
    if (v[idx] == idx) return idx;
    
    return v[idx] = head(v, v[idx]);
}

vector<edge> mst(const vector<edge>& graph, int vertex_count) {
    vector<edge> out, tree = graph;
    vector<int> vertex(vertex_count + 1);
    for (int i = 0; i < vertex_count + 1; i++) vertex[i] = i;
    
    sort(tree.begin(), tree.end(), [](const edge& v1, const edge& v2){ return v1.cost < v2.cost; });
    
    for (auto& e : tree) {
        if (head(vertex, e.start) == head(vertex, e.end)) continue;
        
        vertex[head(vertex, e.end)] = head(vertex, e.start);
        out.push_back(e);
        
        if (out.size() == vertex_count - 1) break;
    }
    
    return out;
}