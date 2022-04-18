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
        for (int j = 0; j < n; ++j)
            if (gr[i][j])
                for (int z = 0; z < n; ++z)
                    if (gr[j][z] && ! gr[i][z]){
                        cout << "NO";
                        return 0;
                    }
    cout << "YES";
}