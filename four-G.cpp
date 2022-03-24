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
    vector <int> index(n + 1, - 1);
    vector <int> p(n, - 1);
    dp[0] = -1 * dp[0];
    for (int i = 0; i < n; ++i){
        int pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        dp[pos] = a[i];
        index[pos] = i;
        p[i] = index[pos - 1];
    }
    int cur;
    for (int i = n; i >= 0; --i)
        if (dp[i] != INT32_MAX){
            cur = index[i];
            break;
        }
    vector <int> ans;
    while(cur != -1){
        ans.push_back(a[cur]);
        cur = p[cur];
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x << " ";
}