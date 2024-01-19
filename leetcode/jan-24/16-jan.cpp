class RandomizedSet {
  vector<int> nums;
  unordered_map<int, int> u_map;

 public:
  RandomizedSet() {}

  bool insert(int val) {
    if (u_map.find(val) == u_map.end()) {
      u_map[val] = nums.size();
      nums.push_back(val);
      return true;
    }
    return false;
  }

  bool remove(int val) {
    auto it = u_map.find(val);
    if (it == u_map.end()) return false;

    int last = nums.back();
    nums[it->second] = last;
    nums.pop_back();
    u_map[nums[it->second]] = it->second;
    u_map.erase(it);
    return true;
  }

  int getRandom() {
    int n = nums.size();
    int r = rand() % n;
    return nums[r];
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */