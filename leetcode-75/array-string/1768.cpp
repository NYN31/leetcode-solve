class Solution {
 public:
  string mergeAlternately(string word1, string word2) {
    string ans = "";
    int mn = min(word1.size(), word2.size());
    for (int i = 0; i < mn; i++) {
      ans.push_back(word1[i]);
      ans.push_back(word2[i]);
    }

    if (word1.size() > word2.size()) {
      for (int i = mn; i < word1.size(); i++) ans.push_back(word1[i]);
    } else {
      for (int i = mn; i < word2.size(); i++) ans.push_back(word2[i]);
    }
    return ans;
  }
};