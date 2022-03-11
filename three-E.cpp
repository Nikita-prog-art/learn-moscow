#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

vector <vector <ll>> dp;

ll rec(ll n, ll k){
    if (k == 0)
        return 0;
    if (n == 1)
        return 1;
    if (dp[n][k] != -1)
        return dp[n][k];
    return dp[n][k] = rec(n - 1, k - 1) + rec(n - 1, k) + rec(n - 1, k + 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;    
    cin >> n;
    dp = vector <vector <ll>> (n + 1, vector <ll>(11, -1));
    ll sum = 0;
    for (int i = 1; i <= 9; ++i)
        sum += rec(n, i);
    cout << sum << "\n";
}