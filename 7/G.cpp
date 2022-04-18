#include <iostream>
#include <vector>

using namespace std;

vector <vector <char>> gr;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int n;

inline bool good(int x, int y){
    return x >= 0 &&  x < n && y >= 0 && y < n;
}

int cnt = 0;

void dfs(int x, int y){
    gr[x][y] = 'u';
    cnt++;
    for (int i = 0; i < 4; ++i){
        int nx = x + dx[i], ny = y + dy[i];
        if(good(nx, ny) && gr[nx][ny] == '.')
            dfs(nx, ny);
    }
}

int main(){
    cin >> n;
    gr = vector <vector <char>>(n, vector <char>(n));
    for (auto &x : gr)
        for (char &y : x)
            cin >> y;
    int x, y;
    cin >> x >> y;
    x--, y--;
    dfs(x, y);
    cout << cnt;
}