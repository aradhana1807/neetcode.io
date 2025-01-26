#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<string> winnerOfAnElection(vector<string> &votes) {
  unordered_map<string, int> mp;
  for (int i = 0; i < votes.size(); i++) {
    mp[votes[i]]++;
  }

  vector<string> ans;
  int maxVote = 0;

  for (auto it : mp) {
    if (it.second > maxVote) {
      maxVote = it.second;
      ans.clear();
      ans.push_back(it.first);
    }

    else if (it.second == maxVote) {
      ans.push_back(it.first);
    }
  }
  return ans;
}

int main() {
  vector<string> votes = {"john", "john", "john", "mary", "mary", "mary", "mary"};
  vector<string> ans = winnerOfAnElection(votes);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}