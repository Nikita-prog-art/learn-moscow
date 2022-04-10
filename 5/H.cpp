#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;


int main() {
  stack <int> stk;
  string s;
  getline(cin, s);
  for (char c : s){
    if(isdigit(c))
      stk.push(c - '0');
    else if (c == '+'){
      int a = stk.top();
      stk.pop();
      int b = stk.top();
      stk.pop();
      stk.push(a + b);
    }
    else if (c == '-'){
      int a = stk.top();
      stk.pop();
      int b = stk.top();
      stk.pop();
      stk.push(b - a);
    }
    else if (c == '*'){
      int a = stk.top();
      stk.pop();
      int b = stk.top();
      stk.pop();
      stk.push(a * b);
    }
  }
  cout << stk.top();
}