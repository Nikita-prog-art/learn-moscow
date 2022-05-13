#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge{
    int v, num, id, parid;
    bool not_first;
    Edge() {}
    Edge(bool not_first): not_first(not_first){}
    Edge(int v, int num, int parid, int id): v(v), num(num), parid(parid), id(id), not_first(true){}
};

const int INF = 1e9;

int n, m;

vector <vector <Edge>> gr;
vector <bool> used;
vector <int> d, dp;
vector <int> ans;

void dfs(int v, int depth = 0, Edge p = Edge(false)){
    used[v] = true;
    d[v] = depth;
    dp[v] = INF;
    for (auto &e : gr[v])
        if (!used[e.v]){
            dfs(e.v, depth + 1, e);
            dp[v] = min(dp[v], dp[e.v]);
        } else if (e.parid != p.id)
            dp[v] = min(dp[v], d[e.v]);
    if (p.not_first && dp[v] >= d[v])
        ans.push_back(p.num);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    gr.resize(n);
    int id = 0;
    for (int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        u--, v--;
        id++;
        gr[v].push_back(Edge(u, i, id + 1, id));
        id++;
        gr[u].push_back(Edge(v, i, id - 1, id));
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