#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

void rec(vector <vector <int>> &dp, int i, int j){
    if (i >= n || j >= m)
        return;
    dp[i][j]++;
    rec(dp, i + 1, j + 2);
    rec(dp, i + 2, j + 1);
}

int main(){
    cin >> n >> m;
    vector <vector <int>> dp(n + 4, vector <int>(m + 4, 0));
    rec(dp, 1, 2);
    rec(dp, 2, 1);
    cout << dp[n - 1][m - 1];
}