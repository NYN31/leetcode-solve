class Solution {
 public:
  int minSteps(string s, string t) {
    vector<int> frq_s(26, 0), frq_t(26, 0);
    for (auto& c : s) frq_s[c - 'a'] += 1;
    for (auto& c : t) frq_t[c - 'a'] += 1;
    int steps = 0;
    for (int i = 0; i < frq_t.size(); i++) {
      int df = frq_t[i] - frq_s[i];
      if (df >= 0) steps += df;
    }
    return steps;
  }
};