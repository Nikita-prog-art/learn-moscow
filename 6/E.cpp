#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector <vector <bool>> gr(n, vector <bool>(n));
    for (int i = 0; i < m; ++i){
        int sg, eg;
        cin >> sg >> eg;
        sg--, eg--;
        gr[sg][eg] = true;
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j)
            cout << gr[i][j] << ' ';
        cout << "\n";
    }
}