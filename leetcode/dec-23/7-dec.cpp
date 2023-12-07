class Solution {
public:
    string largestOddNumber(string num) {
      int n = num.size();
      if((num[n - 1] - '0') & 1) return num;
      
      int pos = n;
      for(int i = n - 1; i >= 0; --i) {
        if((num[i] - '0') & 1) {
          pos = i; break;
        }
      }
      return pos == n ? "" : num.substr(0, pos + 1);
    }
};