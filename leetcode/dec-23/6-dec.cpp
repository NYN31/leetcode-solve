class Solution {
public:
    int totalMoney(int n) {
      int init = 0, save = 0;
      for(int i = 1; i <= n; i += 1) {
        if(i % 7 == 1) {
          init = (i + 6) / 7;
        }
        save += init;
        init += 1;
      }
      return save;
    }
};

// solution

class Solution {
public:
    int cal(int l, int i) {
      return (l * (l + 1)) / 2 - ((i - 1) * i) / 2;
    }
    
    int totalMoney(int n) {
      int init = 1, save = 0;
      int mod = n % 7;
      for(int i = 1; i <= n / 7; i ++) {
        int l = init + 6;
        save += cal(l, init);
        init += 1;
      }
      if(mod > 0) {
        save += cal(init + mod - 1, init);
      }

      return save;
    }
};