#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long> cube;

long long binS(long long x){
    long long l = -1, r = cube.size();
    while(r - l > 1){
        long long mid = (r + l) / 2;
        if (cube[mid] >= x)
            r = mid;
        else
            l = mid;
    }
    if (cube[r] == x)
        return r;
    else
        return r - 1;
}

int main(){
    long long n;
    cin >> n;
    vector <long long> dp(1, n);
    for (long long i = 1; i * i * i <= n; ++i)
        cube.push_back(i*i*i);
    long long answ = -1;
    for (long long i = 1 ; i <= n; ++i){
        dp.push_back(dp[i - 1] - cube[binS(dp[i - 1])]);
        if (dp[i] == 0){
            answ = i;
            break;
        }
    }
    cout << answ;
}