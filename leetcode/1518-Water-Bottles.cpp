#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numWaterBottles(int numBottles, int numExchange) {
    int total = numBottles;
    while (numBottles / numExchange) {
      int remBottles = numBottles % numExchange;
      numBottles /= numExchange;
      total += numBottles;
      numBottles += remBottles;
    }

    return total;
  }
};