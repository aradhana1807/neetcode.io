#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  unordered_set<int> s;
  s.insert(10);
  s.insert(5);
  s.insert(20);
  s.insert(15);
  s.insert(25);

  for (auto it = s.begin(); it != s.end(); it++) cout << (*it) << endl;
  cout << "number of elements: " << s.size() << endl;

  // s.clear();
  // cout << "number of elements after clear(): " << s.size() << endl;

  int key = 20;

  if (s.find(key) == s.end()) {
    cout << "Key not found" << endl;
  } else {
    cout << "Key found" << endl;
  }

  // int deleted_key = 15;
  // s.erase(deleted_key);
  // cout << "number of elements after deletion: " << s.size() << endl;

  if (s.find(key) == s.end()) {
    cout << "Key not found" << endl;
  }

  else {
    auto temp = s.find(key);
    s.erase(temp);
  }

  cout << "number of elements after deletion: " << s.size() << endl;

  return 0;
}
