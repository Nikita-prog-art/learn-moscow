#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int rec(vector <vector <int>> &got, int i, int j, int cost){
    if (i >= n && j >= m)
        return 0;
    if (i >= n || j >= m)
        return 1e9;
    return min(rec(got, i + 1, j, cost + got[i][j]), rec(got, i, j + 1, cost + got[i][j]));
}

int main(){
    cin >> n >> m;
    vector <vector <int>> got(n, vector <int>(m, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> got[i][j];
    cout << rec(got, 0, 0, 0);
}