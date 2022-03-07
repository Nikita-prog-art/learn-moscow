#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Gangster{
    long long t, w, m;
};

bool cmp(Gangster a, Gangster b){
    return a.t < b.t;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n , k, t;
    cin >> n >> k >> t;
    vector <Gangster> a(n);
    for (long long i = 0; i < n; ++i)
        cin >> a[i].t;
    for (long long i = 0; i < n; ++i)
        cin >> a[i].m;
    for (long long i = 0; i < n; ++i)
        cin >> a[i].w;
    sort(a.begin(), a.end(), cmp);
    vector <long long> dp(n);
    vector <bool> can(n);
    for(long long i = 0; i < n; ++i){
        if (a[i].t > a[i].w){
            dp[i] = a[i].m;
            can[i] = true;
        }
        else
            can[i] = false;
        for (long long j = 0; j < i; ++j)
            if (can[j] && a[i].t - a[j].t >= abs(a[i].w - a[j].w))
                dp[i] = max(dp[i], dp[j] + a[i].m);
    }
    cout << *max_element(dp.begin(), dp.end());
}