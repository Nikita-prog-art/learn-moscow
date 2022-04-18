#include <iostream>
#include <vector>

using namespace std;

#define newl "\n"

vector <vector <int>> gr;
vector <bool> used;
vector <vector <int>> gr_comps;

int id = 0;

void dfs(int v){
    used[v] = true;
    gr_comps[id].push_back(v);
    for (int u : gr[v])
        if (!used[u])
            dfs(u);
}

int main(){
    int n, m;
    cin >> n >> m;
    gr.resize(n);
    used.resize(n);
    for (int i = 0; i < m; ++i){
        int v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    for (int i = 0; i < n; ++i){
        if (!used[i]){
            gr_comps.push_back(vector <int>());
            dfs(i);
            id++;
        }
    }
    cout << id << newl;
    for (auto comp : gr_comps){
        cout << comp.size() << newl;
        for (auto x : comp)
            cout << x + 1 << ' ';
        cout << newl;
    }
}