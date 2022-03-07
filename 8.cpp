#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector <vector <unsigned long long>> dp(2, vector <unsigned long long>(n, 0));
    dp[0][0] = 1;
    dp[1][0] = 1;
    for (unsigned long long i = 1; i < n; ++i){
        dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
        dp[1][i] = dp[0][i - 1];
    }
    cout << dp[0][n - 1] + dp[1][n - 1];
}