#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> gr;
vector <bool> used;

void dfs(int v){
    used[v] = true;
    for (int u : gr[v])
        if (!used[u])
            dfs(u);
}

int main(){
    int n, k;
    cin >> n >> k;
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
        for (int j = i; j < n; ++j)
            if (matGr[i][j]){
                gr[i].push_back(j);
                gr[j].push_back(i);
            }
    dfs(k - 1);
    int sum = 0;
    for (bool x : used)
        sum += x;
    cout << sum;
}