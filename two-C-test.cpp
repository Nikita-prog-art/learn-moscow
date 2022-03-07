#include <iostream>
#include <string>

#define ull unsigned long long

using namespace std;

int main(){
    ull n;
    cin >> n;
    ull cnt = 0;
    char dj[] = {'0', '1', '2'};
    for (ull i = 1; i <= n; ++i){
        string build;
        for (ull j = i; j > 0; j /= 3)
            build.push_back(dj[j - (j / 3) * 3]);
        cout << build.find("11") << " " << build.find("22");
    }
}