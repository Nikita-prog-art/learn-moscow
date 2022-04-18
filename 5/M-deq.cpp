#include <iostream>
#include <deque>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    deque <int> first, second;
    for (int i = 0; i < n; ++i){
        char task;
        cin >> task;
        if (task == '+'){
            int x;
            cin >> x;
            second.push_back(x);
        }
        else if (task == '-'){
            cout << first.front() << "\n";
            first.pop_front();
        }
        else if (task == '*'){
            int x;
            cin >> x;
            second.push_front(x);
        }
        if(second.size() > first.size()){
            first.push_back(second.front());
            second.pop_front();
        }
    }
}