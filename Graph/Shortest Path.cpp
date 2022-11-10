#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>

const int maxn = 705;
int n, m, q, a[maxn][maxn], u, v, pre[maxn], d[maxn];
vector<pii> adj[maxn];

void dijkstra(int u) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for (int i = 1; i <= n; i++) d[i] = 1e18;
    d[u] = 0;
    pq.push({0, u});
    while (pq.size()) {
        u = pq.top().se;
        int c = pq.top().fi;
        pq.pop();
        if (d[u] != c) continue;
        for (auto p : adj[u]) {
            int v = p.se;
            c = p.fi;
            if (d[v] > d[u] + c) {
                // cout<<u<<" "<<v<<endl;
                d[v] = d[u] + c;
                pre[v] = u;
                pq.push({d[v], v});
            }
        }
    }
}

int32_t main() {
    if (ifstream("dirty.txt")) {
        freopen("dirty.txt", "r", stdin);
        freopen("dirty.out", "w", stdout);
    }
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cout.tie(0);
    cin >> n >> m >> u >> v;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = 1e18;
            if (i == j) a[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        a[u][v] = min(a[u][v], w);
        // a[v][u]=min(a[v][u],w);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    cout << a[u][v] << endl;
    dijkstra(u);
    stack<int> s;
    int dich = v;
    while (1) {
        if (dich == 0) break;
        s.push(dich);
        dich = pre[dich];
    }
    while (s.size()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1e18)
                cout << "INF ";
            else
                cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
