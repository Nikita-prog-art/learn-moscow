#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> gr;
vector <bool> used;

void dfs(int v, int p = -1){
    used[v] = true;
    for (int u : gr[v]){
        if (!used[u])
            dfs(u, v);
        else if (u != p){
            cout << "NO";
            exit(0);
        }
    }
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
    dfs(0);
    if (used == vector <bool>(n, true))
        cout << "YES";
    else
        cout << "NO";
}