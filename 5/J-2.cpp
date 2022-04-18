#include <iostream>
#include <deque>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    deque <pair<int, int>> deck;
    for (int i = 0; i < k; ++i){
        int x;
        cin >> x;
        while(!deck.empty() && x < deck.back().first)
            deck.pop_back();
        deck.emplace_back(x, i);
    }
    cout << deck.front().first << "\n";
    for (int i = k; i < n; ++i){
        if (deck.front().second == i - k)
            deck.pop_front();
        int x;
        cin >> x;
        while(!deck.empty() && x < deck.back().first)
            deck.pop_back();
        deck.emplace_back(x, i);
        cout << deck.front().first << "\n";
    }
}