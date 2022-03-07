#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pow2(int n){
    int ret = 1;
    for (int i = 0; i < n; ++i)
        ret *= 2;
    return ret;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector <int> dp(n + 1, 0);
    for(int i = 0; i < k; ++i)
        dp[i] = pow2(i);
    for (int i = k; i <= n; ++i)
        for (int j = 1; j <= k; j++)
            dp[i] += dp[i - j];
    cout << dp[n];
}