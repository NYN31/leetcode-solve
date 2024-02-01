class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temp) {
    vector<int> ans(temp.size(), 0);
    stack<int> indx;

    for (int i = temp.size() - 1; i >= 0; --i) {
      while (!indx.empty() && temp[indx.top()] <= temp[i]) {
        indx.pop();
      }

      if (!indx.empty()) ans[i] = indx.top() - i;
      indx.push(i);
    }
    return ans;
  }
};