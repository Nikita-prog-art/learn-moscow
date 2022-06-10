#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned long long ull;

struct Edge{
    ull v, num, id, parid;
    bool not_first, is_bridge;
    Edge() {}
    Edge(bool not_first): not_first(not_first){}
    Edge(ull v, ull num, ull parid, ull id): v(v), num(num), parid(parid), id(id), not_first(true), is_bridge(false){}
};

const ull INF = 1e9;

ull n, m;

vector <vector <Edge>> gr;
vector <bool> used;
vector <ull> d, dp;
ull bridges_cnt = 0;

void dfs(ull v, ull depth, Edge &p){
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
        bridges_cnt++;
}

ull dfs2(ull v, ull depth = 0){
    used[v] = true;
    for (auto &e : gr[v])
        if (!used[e.v] && !e.is_bridge)
            depth = max(dfs2(e.v, depth + 1), depth);
    return depth;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    gr.resize(n);
    ull id = 0;
    for (ull i = 0; i < m; ++i){
        ull u, v;
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
    for (ull i = 0; i < n; ++i)
        if (!used[i]){
            Edge tmp(false);
            dfs(i, 0, tmp);
        }
    cout << bridges_cnt << ' ';
    used = vector <bool>(n, false);
    ull methods = 1;
    for (ull i = 0; i < n; ++i)
        if (!used[i]){
            methods *= dfs2(i);
        }
    cout << methods - 1;
}