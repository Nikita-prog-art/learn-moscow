#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct answ{
    int i = 0, j = 0;
};

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
    vector <vector <answ>> p(n, vector <answ> (k + 1));
    for (int i = 0; i < n; ++i){
        dp[i][1] = clients[i] * (n - i);
        for (int j = 2; j <= k; ++j)
            for (int q = 0; q < i; ++q)
                if (dp[q][j - 1] + (n - i) * (clients[i] - clients[q]) > dp[i][j]){
                    dp[i][j] = dp[q][j - 1] + (n - i) * (clients[i] - clients[q]);
                    p[i][j].i = q;
                    p[i][j].j = j - 1;
                }
    }
    int ans = 0;
    answ nowp;
    for (int i = 0; i < n; ++i)
        if (dp[i][k] > ans){
            ans = dp[i][k];
            nowp = p[i][k];
        }
    vector <int> endout;
    do {
        endout.push_back(dp[nowp.i][nowp.j]);
        nowp = p[nowp.i][nowp.j];
    } while(nowp.i != -1 && nowp.j != -1);
}