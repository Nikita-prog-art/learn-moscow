#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> dp(n);
    vector <int> p(n);
    dp[0] = 1;
    for(int i = 1; i < n; ++i){
        int mn = dp[i - 1] + 1;
        int task = 0;
        if (i % 2 == 0){
            mn = min(mn, dp[i / 2] + 1);
            task = 1;
        }
        if (i % 3 == 0){
            mn = min(mn, dp[i / 3] + 1);
            task = 2;
        }
        dp[i] = mn;
        p.push_back(task);
    }
    for (auto x : p)
        cout << x << " ";
}