#include <bits/stdc++.h>
#define int long long
using namespace std;

int path[1000005];

void dijkstra(int n, int m, vector<pair<int, int>> edges[]) {
    vector<int> dist(n + 1, 1e18);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;

    dist[1] = 0;
    queue.push({0, 1});

    while (queue.size()) {
        int u = queue.top().second;
        int weight = queue.top().first;
        queue.pop();

        if (dist[u] != weight) {
            continue;
        }

        for (auto edge : edges[u]) {
            int v = edge.second;
            weight = edge.first;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                queue.push({dist[v], v});
                path[v] = u;
            }
        }
    }

    if (dist[n] == 1e18) {
        cout << "-1\n";
        return;
    }

    int cur = n;
    stack<int> st;
    while (cur != 0) {
        st.push(cur);
        cur = path[cur];
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
}

int32_t main() {
    // freopen("temp.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges[n + 1];
    for (int i = 0; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({w, v});
        edges[v].push_back({w, u});
    }

    dijkstra(n, m, edges);

    return 0;
}