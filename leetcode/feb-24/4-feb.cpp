class Solution {
 public:
  const int frqSize = 52;

  int getIndex(char ch) {
    if (ch >= 'A' && ch <= 'Z') return ch - 'A';
    return ch - 'a' + 26;
  }

  bool isFoundFreq(vector<int>& curr, vector<int>& target) {
    for (int i = 0; i < frqSize; i++) {
      if (curr[i] < target[i]) return false;
    }
    return true;
  }

  string minWindow(string s, string t) {
    vector<int> frT(frqSize, 0), frS(frqSize, 0);
    for (auto& ch : t) frT[getIndex(ch)]++;

    int l = 0, r = 0, ansL = 0, ansR = 0, minL = INT_MAX;
    string ans = "";
    while (r < s.size()) {
      while (r < s.size()) {
        frS[getIndex(s[r])]++;
        if (isFoundFreq(frS, frT)) {
          if (r - l + 1 < minL) {
            minL = r - l + 1;
            ansL = l, ansR = r;
          }
          r++;
          break;
        }
        r++;
      }

      while (l < r) {
        frS[getIndex(s[l])]--;
        l++;
        if (!isFoundFreq(frS, frT)) break;
        if (r - l < minL) {
          minL = r - l;
          ansL = l, ansR = r - 1;
        }
      }
    }

    if (minL != INT_MAX) {
      for (int i = ansL; i <= ansR; i++) {
        ans.push_back(s[i]);
      }
    }

    return ans;
  }
};