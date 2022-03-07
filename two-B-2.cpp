#include <iostream>
#include <vector>
using namespace std;


int rec(int prev_n, int n) {
    if (dp[prev_n][n] != -1)
        return dp[prev_n][n];
    if (0 == n)
        return 1;
    int cnt = 0;
    for (int level = 1; level < prev_n; ++level) {
        if ((n - level) < 0) 
            break;
        cnt += rec(level, n - level);
    }
    dp[prev_n][n] = cnt;
    return cnt;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, cnt = 0;
    cin >> n;
    vector <vector <int>> dp(n + 2, vector <int>(n + 1, - 1));
    
    cout << rec(n+1, n);
}