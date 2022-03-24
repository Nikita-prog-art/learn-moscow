#include <iostream>
#include <stdint.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> a(n);
    cin >> a[0];
    int k, b, m;
    cin >> k >> b >> m;
    for (int i = 1; i < n; ++i)
        a[i] = (k * a[i - 1] + b) % m;
    vector <int> dp(n + 1, INT32_MAX);
    dp[0] = -1 * dp[0];
    for (int i = 0; i < n; ++i)
        dp[lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin()] = a[i];
    int ans;
    for (int i = n; i >= 0; --i)
        if (dp[i] != INT32_MAX){
            ans = i;
            break;
        }
    cout << ans;
}