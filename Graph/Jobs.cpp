#include <bits/stdc++.h>
using namespace std;
int n, m;
int vis[100005];
bool flag = true;
vector<int> a[100005];
stack<int> st;

void topoSort(int u) {
    // If u is the last node in the graph, push it to the stack and return
    if (a[u].size() == 0) {
        st.push(u);
        return;
    }

    // Visit each child of u
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        // If child[i] has not been visited, visit it
        if (vis[v] == 0) {
            vis[v] = 1;
            topoSort(v);
        }
    }

    // After visiting all children of u, push u to the stack
    st.push(u);
    return;
}

// 0: not visitted
// 1: visited
// 2: visited twice
// topoSort này để kiếm tra đồ thị có chu trình hay k
void checkCycle(int u) {
    // Visit node u
    vis[u] = 1;

    // If there is a cycle, return
    if (flag == false) return;

    // Visit all children of u
    for (int i = 0; i < a[u].size(); i++) {
        // If there is a cycle, return
        if (flag == false) return;

        int v = a[u][i];

        // If child[i] has not been visited, visit it
        if (vis[v] == 0)
            checkCycle(v);

        // If child[i] has been visited once, there is a cycle
        else if (vis[v] == 1)
            flag = false;
    }

    // Mark two for no cycle
    vis[u] = 2;
    return;
}

bool check() {
    for (int i = 1; i <= n; i++) {
        if (flag == false) return false;
        if (vis[i] == 0) checkCycle(i);
    }
    return true;
}

int main() {
    freopen("jobs.txt", "r", stdin);
    freopen("jobs.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            topoSort(i);
        }
    }

    memset(vis, 0, sizeof(vis));
    if (check() == false) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    while (st.size()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
