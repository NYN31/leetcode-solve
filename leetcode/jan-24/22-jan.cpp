
class Solution {
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    unordered_map<int, int> fq;
    int duplicate, missing;
    for (auto& num : nums) {
      if (fq[num] == 1) duplicate = num;
      fq[num] += 1;
    }
    for (int i = 1; i <= nums.size(); i++) {
      if (fq.find(i) == fq.end()) {
        missing = i;
        break;
      }
    }
    return {duplicate, missing};
  }
};