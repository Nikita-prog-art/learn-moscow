#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <vector <int>> gr, rgr, cgr;
vector <bool> used;
vector <int> ts, comp;


void dfs(int v){
    used[v] = true;
    for (int u : gr[v])
        if (!used[u])
            dfs(u);
    ts.push_back(v);
}

void dfs2(int v, int cur_comp){
    used[v] = true;
    comp[v] = cur_comp;
    for (int u : rgr[v])
        if (!used[u])
            dfs2(u, cur_comp);
        else if(comp[u] != cur_comp)
            cgr[comp[u]].push_back(cur_comp);
}

int main(){
    int n, m;
    cin >> n >> m;
    gr.resize(n);
    rgr.resize(n);
    used.resize(n);
    for (int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        u--, v--;
        gr[u].push_back(v);
        rgr[v].push_back(u);
    }
	for (int i = 0; i < n; ++i)
		if (used[i] == 0)
			dfs(i);
    reverse(ts.begin(), ts.end());
    used.assign(n, false);
    comp.resize(n);
    int cur_comp = 0;
    for (int i : ts){
        if (!used[i]){
            cgr.push_back(vector <int>());
            dfs2(i, cur_comp);
            cur_comp++;
        }
    }
    cout << cur_comp << "\n";
    for (int x : comp)
        cout << x + 1 << ' ';
}