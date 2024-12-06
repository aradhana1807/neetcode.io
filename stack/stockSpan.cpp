#include <bits/stdc++.h>
using namespace std;

vector<int> stockSpan(vector<int> &price) {
  int n = price.size();
  stack<int> st;
  vector<int> v;

  for (int i = 0; i < n; i++) {
    if (st.size() == 0) {
      v.push_back(-1);
    }

    else if (st.size() > 0 && price[st.top()] > price[i]) {
      v.push_back(st.top());
    }

    else if (st.size() > 0 && price[st.top()] <= price[i]) {
      while (st.size() > 0 && price[st.top()] <= price[i]) {
        st.pop();
      }

      if (st.size() == 0) {
        v.push_back(-1);
      }

      else {
        v.push_back(st.top());
      }
    }
    st.push(i);
  }

  for (int i = 0; i < v.size(); i++) {
    v[i] = i - v[i];
  }
  return v;
}

int main() {
  vector<int> v = {100, 80, 60, 70, 60, 75, 85};
  vector<int> ans = stockSpan(v);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}