#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline int get(int i, int j, const vector <vector <int>> &dp){
    if (i < 0 || j < 0)
        return 0;
    return dp[i][j];
}

inline int chck(int x){
    if (x < 0)
        return -1;
    return x;
}

struct answ{
    int i = -1, j = -1;
};

int main(){
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int m;
    cin >> m;
    vector <int> b(m);
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    vector <vector <int>> dp(n, vector <int>(m, 0));
    vector <vector <answ>> p(n, vector <answ>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i] == b[j]){
                dp[i][j] = get(i - 1, j - 1, dp) + 1;
                p[i][j].i = chck(i - 1);
                p[i][j].j = chck(j - 1);
            }
            else if (get(i - 1, j, dp) > get(i, j - 1, dp)){
                dp[i][j] = get(i - 1, j, dp);
                p[i][j].i = chck(i - 1);
                p[i][j].j = chck(j);
            }
            else{
                dp[i][j] = get(i, j - 1, dp);
                p[i][j].i = chck(i);
                p[i][j].j = chck(j - 1);
            }
    answ ans = p[n - 1][m - 1];
    vector <int> out;
    while (ans.i >= 0 && ans.j >= 0){
        out.push_back(dp[ans.i][ans.j]);
        ans = p[ans.i][ans.j];
    }
    reverse(out.begin(), out.end());
    for(auto x : out)
        cout << x << " ";
}