class Solution {
 public:
  string v = "aeiouAEIOU";
  bool checkVowel(char ch) {
    for (auto& c : v) {
      if (c == ch) return true;
    }
    return false;
  }
  bool halvesAreAlike(string s) {
    int vowels = 0;
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
      vowels += checkVowel(s[i]) ? 1 : 0;
    }
    for (int i = n / 2; i < n; i++) {
      vowels -= checkVowel(s[i]) ? 1 : 0;
    }
    return vowels == 0 ? true : false;
  }
};