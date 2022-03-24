#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;
    stack <int> r;
    int lsum, rsum = 0;
    cin >> lsum;
    for (int i = 1; i < n; ++i){
        int x;
        cin >> x;
        rsum += x;
        r.push(x);
    }
    while (lsum != rsum && r.size() != 0){
        lsum += r.top();
        rsum -= r.top();
        r.pop();
    }
    if (lsum == rsum)
        cout << "YES";
    else
        cout << "NO";
}