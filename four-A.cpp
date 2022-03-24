#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline int get(int i, int j, const vector <vector <int>> &dp){
    if (i < 0 || j < 0)
        return 0;
    return dp[i][j];
}

int main(){
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int m;
    cin >> m;
    vector <int> b(m);
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    vector <vector <int>> dp(n, vector <int>(m, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i] == b[j])
                dp[i][j] = get(i - 1, j - 1, dp) + 1;
            else
                dp[i][j] = max(get(i - 1, j, dp), get(i, j - 1, dp));
    cout << dp[n - 1][m - 1];
}