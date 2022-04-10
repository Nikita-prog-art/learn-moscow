#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector <int> arr(n);
    for (int i = 0; i < m; ++i){
        int sg, eg;
        cin >> sg >> eg;
        sg--, eg--;
        arr[sg]++;
        arr[eg]++;
    }
    int degree = arr[0];
    for (int x : arr)
        if (degree != x){
            cout << "NO";
            return 0;
        }
    cout << "YES";
}