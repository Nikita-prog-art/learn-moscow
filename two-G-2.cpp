#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector <unsigned long long> up(n), down(n);
    for (unsigned long long i = 0; i < n; ++i)
        up[i] = i + 1;
    for (unsigned long long i = 0; i < n - k; ++i)
        down[i] = i + 1;
    for (unsigned long long i = 0; i < k; ++i)
        down[i + n - k] = i + 1;
    for (unsigned long long i = 1; i < up.size(); ++i)
        for (unsigned long long j = 1; j < down.size(); ++j)
            if (up[i] == down[j]){
                up.erase(up.begin() + i);
                down.erase(down.begin() + j);
                i--;
                j--;
            }
    unsigned long long upRes = 1, downRes = 1;
    for (unsigned long long i = 0; i < up.size(); ++i)
        upRes *= up[i];
    for (unsigned long long i = 0; i < down.size(); ++i)
        downRes *= down[i];
    cout << upRes / downRes;
}