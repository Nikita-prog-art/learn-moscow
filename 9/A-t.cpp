#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge{
    int v, num;
    Edge *bck;
    Edge() {}
    Edge(int v, int num): v(v), num(num){}
};

const int INF = 1e9;

int n, m;

vector <vector <Edge*>> gr;
vector <bool> used;
vector <int> d, dp;
vector <int> ans;

void dfs(int v, int depth = 0, Edge *p = nullptr){
    used[v] = true;
    d[v] = depth;
    dp[v] = INF;
    for (auto &e : gr[v])
        if (!used[e->v]){
            dfs(e->v, depth + 1, e);
            dp[v] = min(dp[v], dp[e->v]);
        } else if (e->bck != p)
            dp[v] = min(dp[v], d[e->v]);
    if (p && dp[v] >= d[v])
        ans.push_back(p->num);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    gr.resize(n);
    for (int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        u--, v--;
        Edge *a = new Edge(u, i);
        Edge *b = new Edge(v, i);
        a->bck = b;
        b->bck = a;
        gr[v].push_back(a);
        gr[u].push_back(b);
    }
    used.resize(n);
    d.resize(n);
    dp.resize(n);
    for (int i = 0; i < n; ++i)
        if (!used[i])
            dfs(i);
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int x : ans)
        cout << x + 1 << ' ';
}