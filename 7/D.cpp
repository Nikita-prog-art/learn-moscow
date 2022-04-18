#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> gr;
vector <int> used;

void dfs(int v){
    used[v] = 1;
    for (int u : gr[v]){
        if (used[u] == 0)
            dfs(u);
        else if (used[u] == 1){
            cout << '1';
            exit(0);
        }
    }
    used[v] = 2;
}

int main(){
    int n;
    cin >> n;
    vector <vector <bool>> matGr(n, vector <bool>(n));
    gr.resize(n);
    used.resize(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j){
            int x;
            cin >> x;
            matGr[i][j] = bool(x);
        }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (matGr[i][j]){
                gr[i].push_back(j);
            }
    dfs(0);
    cout << 0;
}