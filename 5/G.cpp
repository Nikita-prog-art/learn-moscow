#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack <int> stk;
    int x;
    cin >> x;
    while(x != 0){
        stk.push(x);
        cin >> x;
    }
    while (!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }
}