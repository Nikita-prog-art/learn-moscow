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
    for (int i : arr)
        cout << i << "\n";
}