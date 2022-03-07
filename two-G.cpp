#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector <unsigned long long> dp(max(n, k) + 1);
    dp[1] = 1;
    for (unsigned long long i = 2; i <= max(n, k); ++i)
        dp[i] = i * dp[i - 1];
    cout << dp[n] / (dp[n - k] * dp[k]);
}