#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector <int> cube;

struct retVal{
    int i;
    int ost;
};

retVal rec(retVal got){
    retVal now;
    if (cube[cube.size() - got.i] - n == got.ost){
        now.i = got.i;
        now.ost = 0;
        return now;
    }
    int l = -1, r = cube.size();
    while(r - l > 1){
        int mid = (r + l) / 2;
        if (cube[mid] >= got.ost)
            l = mid;
        else
         r = mid;
    }
    if (abs(got.ost - cube[r]) > abs(got.ost - cube[l])){
        retVal temp;
        temp.i = got.i + 1;
        temp.ost = 
        temp = rec(temp);
    }
    else
        now = rec(r);
}

int main(){
    cin >> n;
    for (int i = 1; i * i * i <= n; ++i)
        cube.push_back(i);
    retVal a;
    a.i = 1;
    a.ost = 0;
    a = rec(a);
    cout << a.i;
}