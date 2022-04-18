#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    vector <vector <int>> gr(n);
    for (int i = 0; i < n; ++i){
        stringstream ss;
        getline(cin, s);
        ss << s;
        int x;
        while(ss >> x)
            gr[x - 1].push_back(i);
    }
    cout << n << "\n";
    for(auto x : gr){
        for (auto y : x)
            cout << y + 1 << ' ';
        cout << "\n";
    }
}