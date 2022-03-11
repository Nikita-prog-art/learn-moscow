#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Gangster{
    long long t, p, s;
};

bool cmp(const Gangster a, const Gangster b){
    return a.t < b.t;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n , k, t;
    cin >> n >> k >> t;
    vector <Gangster> g(n);
    for (long long i = 0; i < n; ++i)
        cin >> g[i].t;
    for (long long i = 0; i < n; ++i)
        cin >> g[i].p;
    for (long long i = 0; i < n; ++i)
        cin >> g[i].s;
    sort(g.begin(), g.end(), cmp);
    vector <long long> dp(n);
    vector <bool> can(n);
    for(long long i = 0; i < n; ++i){
        if (g[i].t >= g[i].s){
            dp[i] = g[i].p;
            can[i] = true;
        }
        else{
            can[i] = false;
            continue;
        }
        for (long long j = 0; j < i; ++j)
            if (can[j] && g[i].t - g[j].t >= abs(g[i].s - g[j].s))
                dp[i] = max(dp[i], dp[j] + g[i].p);
    }
    cout << *max_element(dp.begin(), dp.end());
}