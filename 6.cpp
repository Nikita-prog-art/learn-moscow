#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> dp(n);
    vector <int> a(n);
    vector <int> b(n);
    vector <int> c(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i] >> c[i];
    dp[0] = a[0];
    dp[1] = min(dp[0] + a[1], b[0]);
    dp[2] = min({dp[1] + a[2], dp[0] + b[1], c[0]});
    for(int i = 3; i < n; ++i)
        dp[i] = min({dp[i - 1] + a[i], dp[i - 2] + b[i - 1], dp[i - 3] + c[i - 2]});
    cout << dp[n - 1];
}