class Solution {
 public:
  bool closeStrings(string word1, string word2) {
    map<int, int> fq1, fq2;
    vector<int> mp1, mp2;
    bool notClose = true;

    for (auto& ch : word1) fq1[ch - 'a']++;
    for (auto& ch : word2) fq2[ch - 'a']++;

    for (int i = 0; i < 26; i++) {
      if (fq1[i] == 0 && fq2[i] != 0)
        notClose = false;
      else if (fq1[i] != 0 && fq2[i] == 0)
        notClose = false;
      mp1.push_back(fq1[i]);
      mp2.push_back(fq2[i]);
    }

    if (!notClose || mp1.size() != mp2.size())
      return notClose;
    else {
      sort(mp1.begin(), mp1.end());
      sort(mp2.begin(), mp2.end());

      for (int i = 0; i < mp1.size(); i++) {
        if (mp1[i] != mp2[i]) {
          notClose = false;
          break;
        }
      }
    }
    return notClose;
  }
};