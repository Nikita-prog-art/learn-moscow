#include <iostream>
#include <vector>
#include <algorithm>

#define n 5

using namespace std;

int main(){
    vector <int> l(5), r(5);
    for (int i = 0; i < n; ++i)
        cin >> l[i];
    for (int i = 0; i < n; ++i)
        cin >> r[i];
    int cnt = 0;
    while(!l.empty() && !r.empty() && cnt < 1e6){
        if(l.back() == 0 && r.back() == 9){
            l.insert(l.begin(), l.back());
            l.insert(l.begin(), r.back());
            l.pop_back();
            r.pop_back();
        }
        else if(l.back() == 9 && r.back() == 0){
            r.insert(r.begin(), l.back());
            r.insert(r.begin(), r.back());
            l.pop_back();
            r.pop_back();
        }
        else if(l.back() > r.back()){
            l.insert(l.begin(), l.back());
            l.insert(l.begin(), r.back());
            l.pop_back();
            r.pop_back();
        }
        else if(r.back() > l.back()){
            r.insert(r.begin(), l.back());
            r.insert(r.begin(), r.back());
            l.pop_back();
            r.pop_back();
        }
        cnt++;
    }
    if (cnt == 1e6){
        cout << "botva" << " " << cnt;
        return 0;
    }
    if (l.empty()){
        cout << "second" << " " << cnt;
        return 0;
    }
    if (r.empty()){
        cout << "first" << " " << cnt;
        return 0;
    }
}