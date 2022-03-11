#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;    
    cin >> n >> k;
    vector <int> clients(n);
    for (int i = 0; i < n; ++i)
        cin >> clients[i];
    sort(clients.begin(), clients.end());
    vector <vector <int>> dp(n, vector <int> (k + 1));
    for (int i = 0; i < n; ++i){
        dp[i][1] = clients[i] * (n - i);
        for (int j = 2; j <= k; ++j)
            for (int q = 0; q < i; ++q)
                dp[i][j] = max(dp[i][j], dp[q][j - 1] + (n - i) * (clients[i] - clients[q]));
    }
    for (int i = 1; i <= k; ++i)
        cout << dp[n - 1][i] << " ";
}