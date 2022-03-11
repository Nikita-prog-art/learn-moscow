#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ull t, n, m;    
    cin >> t >> n >> m;
    vector <ull> leftCars(n + 1), rightCars(n + 1);
    for (ull i = 1; i <= n; ++i)
        cin >> leftCars[i];
    for (ull i = 1; i <= m; ++i)
        cin >> leftCars[i];
    vector <vector <vector <ull>>> dp(n + 1, vector <vector <ull>>(m + 1, vector <ull>(2)));
    dp[0][0][0] = 1;
    dp[0][0][1] = t;
    for (ull i = 1; i <= n; ++i){
        for (ull j = 1; j <= m; ++j){
            const ull priority = n - i + m - j + 1;
            dp[i][j][0] = min(
                dp[i - 1][j][0] + leftCars[i] * priority,
                dp[i - 1][j][1] + (leftCars[i] + t) * priority
            );
            dp[i][j][1] = min(
                dp[i][j - 1][1] + rightCars[j] * priority,
                dp[i][j - 1][0] + (rightCars[j] + t) * priority
            );
        }
    }
    cout << min(dp[n][m][0], dp[n][m][1]);
}