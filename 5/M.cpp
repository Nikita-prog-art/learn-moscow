#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector <int> gobq;
    for (int i = 0; i < n; ++i){
        char task;
        cin >> task;
        if (task == '+'){
            int x;
            cin >> x;
            gobq.insert(gobq.begin(), x);
        }
        else if (task == '-'){
            cout << gobq.back() << "\n";
            gobq.pop_back();
        }
        else if (task == '*'){
            int x;
            cin >> x;
            gobq.insert(gobq.begin() + gobq.size() / 2, x);
        }
    }
}