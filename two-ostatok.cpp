#include <iostream>
#include <vector>
#include <algorithm>

#define ull unsigned long long

using namespace std;

int main(){
    ull n;
    cin >> n;
    vector <int> arr;
    for (ull i = n; i > 0; i /= 3)
        arr.push_back(int(i - (i / 3) * 3));
    reverse(arr.begin(), arr.end());
    for (auto x : arr){
        cout << x;
    }
}