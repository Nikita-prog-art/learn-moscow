#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct node{
    int x, height;
};

int main(){
    int n, m;
    cin >> n >> m;
    vector <vector <bool>> get(n, vector <bool>(m));
    vector <vector <int>> arr(n, vector <int>(m));
    for (auto &x : get)
        for (int i = 0; i < m; ++i){
            int buff;
            cin >> buff;
            x[i] = !bool(buff);
        }
    for (int j = 0; j < m; ++j)
        arr[0][j] = get[0][j];
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < m; ++j){
            if (get[i][j])
                arr[i][j] = 1 + arr[i - 1][j];
        }
    unsigned long long answ = 0;
    node zero;
    zero.x = 0, zero.height = 0;
    for (int i = 1; i < n; ++i){
        stack <node> stk;
        stk.push(zero);
        for (int j = 0; j <= m + 1; ++j){
            int height = 0;
            if (j < m)
                height = arr[i][j];
            int x = j;
            while (height < stk.top().height){
                x = stk.top().x;
                unsigned long long area = 1ULL * stk.top().height * (j - x);
                if (area > answ)
                    answ = area;
                stk.pop();
            }
            if (height > stk.top().height){
                node tmp;
                tmp.x = x;
                tmp.height = height;
                stk.push(tmp);
            }
        }
    }
    cout << answ;
}