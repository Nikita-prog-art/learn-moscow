#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> dp(n);
    vector <int> got(n);
    for (int i = 0; i < n; ++i)
        cin >> got[i];
    dp[0] = got[0];
    dp[1] = min(dp[0], 0) + got[1];
    for(int i = 2; i < n; ++i)
        dp[i] = min(dp[i - 1], dp[i - 2]) + got[i];
    cout << dp[n - 1];
}