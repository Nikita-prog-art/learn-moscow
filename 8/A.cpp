#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> gr;
vector <int> used;
vector <int> ts;

bool good = true;

void dfs(int v){
    used[v] = 1;
    for (int u : gr[v]){
        if (used[u] == 0)
            dfs(u);
        else if (used[u] == 1)
            good = false;
    }
    used[v] = 2;
    ts.push_back(v);
}

int main(){
    int n, m;
    cin >> n >> m;
    gr.resize(n);
    used.resize(n);
    for (int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        u--, v--;
        gr[u].push_back(v);
    }
	for (int i = 0; i < n; ++i)
		if (used[i] == 0)
			dfs(i);
    if (!good)
        cout << "No";
    else{
        cout << "Yes\n";
        for (int i = ts.size() - 1; i >= 0; i--)
            cout << ts[i] + 1 << ' ';
    }
}