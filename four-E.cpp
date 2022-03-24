#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector <int> dp(n, 1);
    vector <int> p(n, -1);
    for (int i = 0 ; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (a[j] < a[i])
                if (dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    p[i] = j;
                }
    vector <int> ans;
    int cur = max_element(dp.begin(), dp.end()) - dp.begin();
    while(cur != -1){
        ans.push_back(a[cur]);
        cur = p[cur];
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x << " ";
}