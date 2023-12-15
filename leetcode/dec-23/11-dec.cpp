class Solution {
public:
    const int per = 25;
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        double tf_percent = (per * n * 1.0) / 100;
        //cout << (25 * n) / 100 << " " << tf_percent << endl;
        int cnt = 1, curr = arr[0], ans = arr[0];
        for (int i = 1; i < n; i++) {
          if (curr == arr[i]) {
            cnt += 1;
            if(cnt > tf_percent) {
              ans = arr[i];
              break;
            }
          } else {
            cnt = 1;
            curr = arr[i];
          }
        }
        return ans;
    }
};