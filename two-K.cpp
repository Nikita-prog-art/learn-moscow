#include <iostream>
#include <vector>
using namespace std;

vector<vector <int>> dp;

int rec(int prev_level, int n) {
    if (dp[prev_level][n] != -1)
        return dp[prev_level][n];
    if (0 == n)
        return 1;
    int cnt = 0;
    for (int level = 1; level < prev_level; ++level) {
        if ((n - level) < 0) 
            break;
        cnt += rec(level, n - level);
    }
    dp[prev_level][n] = cnt;
    return cnt;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    dp = vector<vector <int>>(n + 2, vector <int>(n + 1, - 1));
    cout << rec(n + 1, k);
}