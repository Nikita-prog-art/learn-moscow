#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> e(n), t(n), c(n);
    for (int i = 1; i < n; ++i)
        cin >> e[i];
    
    vector<vector<int>> dp(n, vector<int> (n + 1));

}