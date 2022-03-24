#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, K;
    cin >> n >> K;
    vector <int> w(n), c(n);
    for (int &x : w)
        cin >> x;
    for (int &x : c)
        cin >> x;
    vector <vector <int>> dp(n + 1, vector <int>(K + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= K; ++j){
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i - 1] && dp[i - 1][j - w[i - 1]] + c[i - 1] > dp[i][j])
                dp[i][j] = dp[i - 1][j - w[i - 1]] + c[i - 1];
        }
    cout << dp[n][K];
}