#include <bits/stdc++.h>
using namespace std;
#define MAX 200005

void dijkstra(int numNode, int numEdge, int dist[], vector<pair<int, int>> edges[]) {
    // priority_queue<<Type>, <Container>, <Comparator>>
    // Auto sort element in container regarding to comparator

    // pair<w, v>
    // Auto sort by weight in ascending order
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;

    // Init all distance to infinity
    for (int i = 1; i <= numNode; i++) {
        dist[i] = 1e9;
    }

    // Dist from start to start is 0
    dist[0] = 0;

    // Push start node to queue
    queue.push({0, 0});

    // While there is node in queue
    while (queue.size()) {
        int curNode = queue.top().second;
        int weight = queue.top().first;
        queue.pop();

        if (dist[curNode] != weight) {
            continue;
        }

        for (auto edge : edges[curNode]) {
            int v = edge.second;
            weight = edge.first;
            if (dist[v] > dist[curNode] + weight) {
                dist[v] = dist[curNode] + weight;
                queue.push({dist[v], v});
            }
        }
    }
}

int32_t main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int numNode;
    int numEdge;
    int dist[MAX];
    vector<pair<int, int>> edges[MAX];

    cin >> numNode >> numEdge;
    for (int i = 1; i <= numEdge; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({w, v});
        edges[v].push_back({w, u});
    }
    dijkstra(numNode, numEdge, dist, edges);
    for (int i = 0; i <= numNode; i++) {
        cout << dist[i] << "\n";
    }
    return 0;
}
