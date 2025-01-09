#include <bits/stdc++.h>

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  unordered_map<string, int> umap;
  umap["st"] = 44;
  umap["helloworld"] = 90;
  umap["helooo"] = 80;

  // for (auto x : umap) {
  //   cout << x.first << " " << x.second << endl;
  // }

  for (auto itr = umap.begin(); itr != umap.end(); itr++) {
    cout << itr->first << " " << itr->second << endl;
  }

  string key = "st";

  if (umap.find(key) != umap.end())
    cout << "Key found" << endl;
  else
    cout << "key not found" << endl;

  if (umap.find(key) != umap.end()) {
    auto temp = umap.find(key);
    cout << "Key is " << temp->first << " and value is " << temp->second << endl;
  }

  umap.insert(make_pair("newkey", 10));

  key = "helloworld";
  umap.erase(key);

  for (auto itr = umap.begin(); itr != umap.end(); itr++) {
    cout << itr->first << " " << itr->second << endl;
  }

  cout << umap.size() << endl;

  int arr[] = {7, 2, 1, 0, 5, 2, 0, 9, 6, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  unordered_map<int, int> mp;

  for (int i = 0; i < n; i++) {
    mp[arr[i]]++;
  }

  for (auto itr = mp.begin(); itr != mp.end(); itr++) {
    cout << itr->first << " " << itr->second << endl;
  }
}
