#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define piii pair<int, pii>
const int maxn = 2e5 + 5;

// par -> parrent, đại diện 
int n, t, m, par[maxn], res;
vector<piii> a, ans;

// 1->4
// 5->6
// 3->2
// 8->7->9
// par[1] = -4
// par[3] = -2
// par[4] = 1
// par[5] = -2
// par[6] = 5
int findPar(int u) {
    // par[u] = u là đại diện của các đỉnh chứa trong par[u]
    if (par[u] < 0) return u;

    par[u] = findPar(par[u]);
    return par[u];
}

void ghep(int u, int v) {
    if (u > v) swap(u, v);
    par[u] += par[v];
    par[v] = u;
}

int32_t main() {
    freopen("connection.txt", "r", stdin);
    freopen("connection.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    // set par full -1
    memset(par, 255, sizeof(par));

    // par[u] < 0 -> u thuộc tập hợp nào đấy
    // Tâp hợp này sẽ có abs(par[u]) phần tử

    // par[u] > 0 -> par[u] là đại diện của tập hợp chứa u

    for (int i = 1; i <= m; i++) {
        int u, v, k;
        cin >> u >> v >> k;
        a.push_back({k, {u, v}});
    }

    sort(a.begin(), a.end());
    for (auto p : a) {
        if (findPar(p.se.fi) != findPar(p.se.se)) {
            ghep(findPar(p.se.fi), findPar(p.se.se));
            res += p.fi;
            ans.push_back({p.se.fi, {p.se.se, p.fi}});
        }
    }
    cout << res << "\n";
    for (auto p : ans) cout << p.fi << " " << p.se.fi << " " << p.se.se << "\n";
    return 0;
}
