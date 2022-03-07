#include <iostream>
#include <string>

#define ull unsigned long long

using namespace std;

int main(){
    ull n;
    cin >> n;
    ull cnt = 0;
    for (ull i = 1; i <= n; ++i){
        string build;
        for (ull j = i; j > 0; j /= 3)
            build.push_back(char(j - (j / 3) * 3 + '0'));
        if (build.find("11") == string::npos || build.find("22") == string::npos)
            cnt++;
        else
            cout << build << " ";;
    }
    cout << "\n" << cnt;
}