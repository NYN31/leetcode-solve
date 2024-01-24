class Solution {
 public:
  bool isUnique(string& currStr, string& newStr) {
    unordered_set<char> chars;
    for (auto& ch : newStr) {
      if (chars.count(ch) > 0) return false;
      chars.insert(ch);
      if (currStr.find(ch) != string::npos) return false;
    }
    return true;
  }

  void fn(int start, string currStr, int& n, vector<string>& arr,
          int& mxLength) {
    if (mxLength < currStr.size()) mxLength = currStr.size();

    for (int i = start; i < n; i++) {
      if (!isUnique(currStr, arr[i])) continue;
      fn(i + 1, currStr + arr[i], n, arr, mxLength);
    }
  }

  int maxLength(vector<string>& arr) {
    int n = arr.size(), mxLength = 0;
    fn(0, "", n, arr, mxLength);
    return mxLength;
  }
};