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
    vector <vector <ull>> dp(n + 1, vector <ull>(n + 1, 0)); 
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= i; ++j){
            for (int q = 0; q < j; ++q)
                dp[i][j] += dp[i - j][q];
        }
    }
    cout << accumulate(dp[n].begin(), dp[n].end(), 0);
}