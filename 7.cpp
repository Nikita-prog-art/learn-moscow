#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> dp(n, 0);
    vector <int> got(n);
    for (int i = 0; i < n; ++i)
        cin >> got[i];
    sort(got.begin(), got.end());
    dp[1] = got[1] - got[0];
    dp[2] = got[2] - got[0];
    for(int i = 3; i < n; ++i)
        dp[i] = min(dp[i - 1], dp[i - 2]) + got[i] - got[i - 1];
    cout << dp[n - 1];
}