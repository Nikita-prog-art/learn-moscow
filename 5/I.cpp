#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    int buff;
    cin >> buff;
    string s;
    cin >> s;
    stack <char> stk;
    bool good = true;
    for (const char &c : s){
        if (c == '(' || c == '{' || c == '[')
            stk.push(c);
        else if(!stk.empty()){
            if (c == ')')
                if (stk.top() == '(')
                    stk.pop();
                else{
                    good = false;
                    break;
                }
            else if(c == '}')
                if (stk.top() == '{')
                    stk.pop();
                else{
                    good = false;
                    break;
                }
            else if(c == ']')
                if (stk.top() == '[')
                    stk.pop();
                else{
                    good = false;
                    break;
                }
        }
        else
            good = false;
    }
    if (stk.empty() && good)
        cout << "Yes";
    else
        cout << "No";
}