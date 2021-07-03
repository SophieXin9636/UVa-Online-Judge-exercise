#include <algorithm>
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int t, c = 0;
  bool input = true;

  while (cin >> t) {
    if (t == 0)
      break;
    else if (c != 0)
      printf("\n");
    input = true;
    while (input) {
      bool output = false;
      int cnt = t, num;
      std::vector<int> v(t);
      std::stack<int> s;

      for (int i = 0; i < t; i++) {
        cin >> v[i];
        if (i == 0 && v[i] == 0) {
          input = false;
          break;
        }
      }
      if (input == false)
        break;
      reverse(v.begin(), v.end());

      while (!v.empty()) {
        s.push(v[0]);
        v.erase(v.begin());
        if (s.top() == cnt) {
          s.pop();
          cnt--;
        }
      }
      while (!s.empty()) {
        if (s.top() == cnt) {
          s.pop();
          cnt--;
        } else {
          printf("No\n");
          output = true;
          break;
        }
      }
      cout << (s.empty() ? "Yes\n" : "No\n");
      // if(s.empty()) printf("Yes\n");
      // else if(!output) printf("No\n");
    }
    c++;
  }
  return 0;
}