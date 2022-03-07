#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define ull unsigned long long

using namespace std;

int main(){
    ull n;
    cin >> n;
    ull cnt = 0;
    for (ull i = 1; i <= n; ++i){
        vector <int> build;
        for (ull j = i; j > 0; j /= 3){
            build.push_back(char(j - (j / 3) * 3));
        }
        if (find(build.begin(), build.end()))
            cnt++;
    }
    cout << cnt;
}