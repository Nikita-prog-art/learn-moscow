#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

struct query_min{
    deque <pair<int, int>> deck;
    int l = 0, r = 0;

    void push_back(int x){
        while(!deck.empty() && deck.back().first >= x)
            deck.pop_back();
        deck.emplace_back(x, r);
        r++;
    }

    void pop_front(){
        if (deck.front().second == l)
            deck.pop_front();
        l++;
    }

    int get_min(){
        return deck.front().first;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    query_min que;
    for (int i = 0; i < k; ++ i){
        int x;
        cin >> x;
        que.push_back(x);
    }
    cout << que.get_min() << "\n";
    for (int i = k; i < n; i++){
        que.pop_front();
        int x;
        cin >> x;
        que.push_back(x);
        cout << que.get_min() << "\n";
    }
}