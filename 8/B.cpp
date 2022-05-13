#include <iostream>
#include <vector>

using namespace std;

struct Electro{
    int start, end, startTime, speed, id;
};

int n;

vector <vector <int>> gr;
vector <bool> used;
vector <int> ts;

void dfs(int v){
    used[v] = true;
    for (int u : gr[v])
        if (!used[u])
            dfs(u);
    ts.push_back(v);
}

int main(){
    cin >> n;
    gr.resize(n);
    used.resize(n);
    vector <Electro> electro(n);
    int id = 0;
    for (auto &x : electro){
        cin >> x.start >> x.end >> x.startTime >> x.speed;
        x.id = id++;
    }
    for (auto &fir : electro){
        for (auto &sec : electro){
            if (fir.id == sec.id)
                continue;
            if (fir.start <= sec.start && sec.start <= fir.end){
                if (fir.startTime + fir.speed * (sec.start - fir.start) < sec.startTime)
                    gr[fir.id].push_back(sec.id);
                else
                    gr[sec.id].push_back(fir.id);
            }
        }
    }
    for (int i = 0; i < n; ++i)
        if (!used[i])
            dfs(i);
    for (int i = n - 1; i >= 0; --i)
        cout << ts[i] + 1 << ' ';
}