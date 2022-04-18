#include <iostream>
#include <vector>

using namespace std;

#define newl "\n"

vector <vector <int>> gr;
vector <int> colors;

void dfs(int v, int col = 1){
    colors[v] = col;
    for (int u : gr[v])
        if (colors[u] == 0)
            dfs(u, 3 - col);
        else if (colors[u] == col){
            cout << "NO";
            exit(0);
        }
}

int main(){
    int n, m;
    cin >> n >> m;
    gr.resize(n);
    colors.resize(n);
    for (int i = 0; i < m; ++i){
        int v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    dfs(0);
    cout << "YES" << newl;
    for (int i = 0; i < colors.size(); ++i)
        if (colors[i] == 1)
            cout << i + 1 << ' ';
}