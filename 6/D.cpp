#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector <vector <bool>> gr(n, vector <bool>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j){
            int x;
            cin >> x;
            gr[i][j] = bool(x);
        }
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            if (gr[i][j])
                cout << i + 1 << ' ' << j + 1 << "\n";
}