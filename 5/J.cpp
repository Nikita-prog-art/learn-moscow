#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector <int> arr(n);
    for (int &x : arr)
        cin >> x;
    int l = 0, r = k - 1;
    while(r < n){
        cout << *min_element(arr.begin() + l, arr.begin() + r + 1) << "\n";
        l++, r++;
    }
}