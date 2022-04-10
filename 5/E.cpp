#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue <int> first, second;
    for (int i = 0; i < 5; ++i){
        int x;
        cin >> x;
        first.push(x);
    }
    for (int i = 0; i < 5; ++i){
        int x;
        cin >> x;
        second.push(x);
    }
    int cnt = 0;
    while(!first.empty() && !second.empty() && cnt <= 1e6){
        if (first.front() == 0 && second.back() == 9){
            int x = first.front();
            first.pop();
            first.push(x);
            x = second.front();
            second.pop();
            first.push(x);
        }
        else if (first.front() == 9 && second.back() == 0){
            int x = first.front();
            first.pop();
            second.push(x);
            x = second.front();
            second.pop();
            second.push(x);
        }
        else if (first.front() > second.back()){
            int x = first.front();
            first.pop();
            first.push(x);
            x = second.front();
            second.pop();
            first.push(x);
        }
        else if (first.front() < second.back()){
            int x = first.front();
            first.pop();
            second.push(x);
            x = second.front();
            second.pop();
            second.push(x);
        }
        cnt++;
    }
    if (cnt > 1e6)
        cout << "botva";
    else if (first.empty())
        cout << "second " << cnt;
    else if (second.empty())
        cout << "first " << cnt;
    else
        return -1;
}