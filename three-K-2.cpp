#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int main(){
    ull n, k;
    cin >> n >> k;
    vector <vector <ull>> dp(100, vector <ull>(n));
    dp[0] = vector <ull>(n, 1);
    for (int i = 1; i < k; ++i)
        for (int j = 0; j < n; ++j)
            if (dp[i - 1][j] != 0)
                for (int q = j + 2; q < n; ++q)
                    dp[i][q] = dp[i][q] + (q - j - 1) * dp[i - 1][j];
    cout << dp[k - 1][n - 1];
}