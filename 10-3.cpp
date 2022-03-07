#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> dp(n + 1);
    dp[1] = 1;
    for (int i = 2; i <= n; ++i){
        dp[i] = 1e9;
        for (int j = 1; j * j * j <= i; ++j){
            dp[i] = min(dp[i], dp[i - j * j * j] + 1);
        }
    }
    cout << dp[n];
}