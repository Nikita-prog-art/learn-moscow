#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ull n;    
    cin >> n;
    vector <vector <ull>> dp(n, vector <ull>(3, 0));
    dp[0][0] = dp[0][1] = dp[0][2] = 1;
    for (int i = 1; i < n; ++ i){
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
        dp[i][2] = dp[i - 1][0] + dp[i - 1][1]; 
    }
    cout << dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2]; 
}