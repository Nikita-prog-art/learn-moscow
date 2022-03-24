#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll rec(ll n, ll k){
    if (n == 0)
        return 1;
    if (k == 0)
        return 0;
    ll sum = 0;
    for (int i = 0; i <= n - 2; ++i)
        sum += rec(i, k - 1);
    return sum;
}

int main(){
    ll n, k;
    cin >> n >> k;
    cout << rec(n, k);
}