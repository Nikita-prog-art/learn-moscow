#include <iostream>
#include <stack>

using namespace std;

struct node{
    int x, height;
};

int main(){
    int n;
    cin >> n;
    stack <node> stk;
    long long answ = 0;
    int height;
    node fir;
    fir.x = 0;
    fir.height = 0;
    stk.push(fir);
    for (int i = 0; i <= n + 1; ++i){
        if (i < n)
            cin >> height;
        else
            height = 0;
        int x = i;
        while (height < stk.top().height){
            x = stk.top().x;
            int stkHeight = stk.top().height;
            stk.pop();
            long long area = 1LL * stkHeight * (i - x);
            if (area > answ)
                answ = area;
        }
        if (height > stk.top().height){
            node tmp;
            tmp.x = x;
            tmp.height = height;
            stk.push(tmp);
        }
    }
    cout << answ;
}