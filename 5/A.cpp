#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, K;
    cin >> n >> K;
    vector <int> w(n);
    for (int &x : w)
        cin >> x;
    vector <vector <bool>> dp(n + 1, vector <bool>(K + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= K; ++j){
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i - 1] && dp[i - 1][j - w[i - 1]])
                dp[i][j] = true;
        }
    for (int i = K; i >= 0; --i)
        if (dp[n][i]){
            cout << i;
            break;
        }
}