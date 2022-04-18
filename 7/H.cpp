#include <iostream>
#include <vector>

using namespace std;

vector <vector <char>> gr;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int n, m;

inline bool good(int x, int y){
    return x >= 0 &&  x < n && y >= 0 && y < m;
}

int cnt = 0;

void dfs(int x, int y){
    gr[x][y] = 'u';
    for (int i = 0; i < 4; ++i){
        int nx = x + dx[i], ny = y + dy[i];
        if(good(nx, ny) && gr[nx][ny] == '#')
            dfs(nx, ny);
    }
}

int main(){
    cin >> n >> m;
    gr = vector <vector <char>>(n, vector <char>(m));
    for (auto &x : gr)
        for (char &y : x)
            cin >> y;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (gr[i][j] == '#'){
                dfs(i, j);
                cnt++;
            }
    cout << cnt;
}